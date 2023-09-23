#ifndef INCLUDE_LIB_ECS_SYSTEM_MANAGER_H_
#define INCLUDE_LIB_ECS_SYSTEM_MANAGER_H_

#include <map>
#include <memory>
#include <typeindex>
#include "lib/ecs/entity_manager.h"
#include "lib/ecs/system.h"

/**
 * Менеджер систем. Как и менеджер сущностей, выступает как
 * хранищиле систем. Помимо базовых действий с системами (добавление, удаление),
 * менеджер также может отключать те или иные системы. Если система будет отключена,
 * то в цикле обновления система не будет выполнять возложенные
 * на неё обязанности.
 *
 * В цикле на обновление последовательность обновления следующая:
 * - сперва системы выполняют то, что им необходимо до основного цикла (PreUpdate)
 * - системы отрабатывают (Update)
 * - системы выполняют то, что им необходимо после завершения цикла (PostUpdate)
 */
class SystemManager {
 private:
  std::map<std::type_index, std::unique_ptr<ISystem>> systems;
  EntityManager *const entity_manager;

 public:
  explicit SystemManager(EntityManager *entity_manager) : entity_manager(entity_manager) {}

  template<typename System, typename... Args>
  SystemManager *AddSystem(Args &&... args) {
    systems.emplace(typeid(System), std::make_unique<System>(entity_manager, this, std::forward<Args>(args)...));
    return this;
  }

  template<typename System>
  SystemManager *Delete() {
    systems.erase(typeid(System));
    return this;
  }

  SystemManager *DeleteAll() {
    systems.clear();
    return this;
  }

  template<typename System>
  void Disable() const {
    systems.at(typeid(System))->is_enabled_ = false;
  }

  template<typename System>
  void Enable() const {
    systems.at(typeid(System))->is_enabled_ = true;
  }

  void OnUpdate() {
    for (auto &p : systems) {
      if (p.second->is_enabled_) {
        p.second->OnPreUpdate();
      }
    }
    for (auto &p : systems) {
      if (p.second->is_enabled_) {
        p.second->OnUpdate();
      }
    }
    for (auto &p : systems) {
      if (p.second->is_enabled_) {
        p.second->OnPostUpdate();
      }
    }
  }
};
#endif  // INCLUDE_LIB_ECS_SYSTEM_MANAGER_H_


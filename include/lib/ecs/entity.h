#ifndef INCLUDE_LIB_ECS_ENTITY_H_
#define INCLUDE_LIB_ECS_ENTITY_H_

#include <map>
#include <memory>
#include <typeindex>
#include "lib/ecs/component.h"

/**
 * Сущность не содержит каких-либо методов, связанных непосредственно с логикой
 * работы той или иной сущности. Все, что она содержит - это
 * список компонентов, которые принадлежат ей.
 *
 * Системы пользуются этим для того, чтобы определять, над какой
 * сущностью они сейчас работают
 *
 * !!! Запомните - от класса Entity НЕ НАСЛЕДУЮТСЯ !!!
 * В сценах объявляются экземпляры класса Entity, куда потом накидываются нужные компоненты
 */
class Entity {
  friend class EntityManager;

 private:
  std::map<std::type_index, std::unique_ptr<IComponent>> components;
  size_t id = 0;

 public:
  explicit Entity(size_t id) : id(id) {}

  template<typename Component, typename... Args>
  Entity* Add(Args&&... args) {
    components[typeid(Component)] = std::make_unique<Component>(std::forward<Args>(args)...);
    return this;
  }

  size_t GetId() const {
    return id;
  }

  template<typename Component>
  Component* Get() const {
    auto c = components.at(typeid(Component)).get();
    return dynamic_cast<Component*>(c);
  }

  template<typename Component>
  bool Contains() const {
    return components.count(typeid(Component)) != 0;
  }

  template<typename Component>
  void Delete() {
    components.erase(typeid(Component));
  }
};

#endif  // INCLUDE_LIB_ECS_ENTITY_H_

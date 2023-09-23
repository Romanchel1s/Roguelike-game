#ifndef INCLUDE_LIB_ECS_SYSTEM_H_
#define INCLUDE_LIB_ECS_SYSTEM_H_

class SystemManager;
class EntityManager;

/**
 * Система занимается непосредственно логикой игры
 * Для этого у неё есть 3 метода:
 * - OnPreUpdate - все, что необходимо выполнить над сущностями прежде чем выполнить работу (например, очистить экран в RenderingSystem)
 * - OnUpdate - непосредственно само обновление системы, происходит работа над значениями компонентов
 * - OnPostUpdate - после того, как мы выполнили работу, иногда нам необходимо сделать что-то после обновления (обновить окно, например)
 */
class ISystem {
  friend class SystemManager;
  bool is_enabled_ = true;
  EntityManager *const entity_manager_;
  SystemManager *const system_manager_;

 protected:
  virtual void OnPreUpdate() {}
  virtual void OnUpdate() {}
  virtual void OnPostUpdate() {}

 public:
  ISystem(EntityManager *entity_manager, SystemManager *system_manager)
      : entity_manager_(entity_manager), system_manager_(system_manager) {}
  virtual ~ISystem() = default;

  EntityManager *GetEntityManagerPtr() const {
    return entity_manager_;
  }
  EntityManager &GetEntityManager() const {
    return *GetEntityManagerPtr();
  }
  SystemManager *GetSystemManagerPtr() const {
    return system_manager_;
  }
  SystemManager &GetSystemManager() const {
    return *GetSystemManagerPtr();
  }
};

#endif  // INCLUDE_LIB_ECS_SYSTEM_H_

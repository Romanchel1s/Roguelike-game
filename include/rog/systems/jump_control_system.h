#ifndef INCLUDE_ROG_SYSTEMS_JUMP_CONTROL_SYSTEM_H_
#define INCLUDE_ROG_SYSTEMS_JUMP_CONTROL_SYSTEM_H_

#include <lib/ecs/system.h>
#include <rog/controls.h>

class Entity;  // forward declaration because we include this class in the cpp file

class JumpControlSystem : public ISystem {
  const Controls& controls_;
  void OnUpdateEntity(Entity* entity) const;

 protected:
  void OnUpdate() override;

 public:
  JumpControlSystem(EntityManager* entity_manager, SystemManager* system_manager, const Controls& controls);
};

#endif  // INCLUDE_ROG_SYSTEMS_JUMP_CONTROL_SYSTEM_H_

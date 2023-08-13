#ifndef INCLUDE_ROG_SYSTEMS_DOOR_COLLISION_SYSTEM_H_
#define INCLUDE_ROG_SYSTEMS_DOOR_COLLISION_SYSTEM_H_

#include <lib/ecs/system.h>
#include <lib/scenes/context.h>

class Entity;

class DoorCollisionSystem : public ISystem {
 private:
  Context* ctx_;
  void Collide(Entity* entity_1, Entity* entity_2) const;

 public:
  DoorCollisionSystem(EntityManager* entity_manager, SystemManager* system_manager, Context* ctx);

 protected:
  void OnUpdate() override;
};

#endif  // INCLUDE_ROG_SYSTEMS_DOOR_COLLISION_SYSTEM_H_

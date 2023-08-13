#ifndef INCLUDE_ROG_SYSTEMS_FOOD_COLLISION_SYSTEM_H_
#define INCLUDE_ROG_SYSTEMS_FOOD_COLLISION_SYSTEM_H_

#include <lib/ecs/system.h>
#include <lib/scenes/context.h>

class Entity;

class FoodCollisionSystem : public ISystem {
 private:
  Context* ctx_;
  bool IsDead(Entity* entity_1) const;
  void Collide(Entity* entity_1, Entity* entity_2) const;

 public:
  FoodCollisionSystem(EntityManager* entity_manager, SystemManager* system_manager, Context* ctx);

 protected:
  void OnUpdate() override;
};

#endif  // INCLUDE_ROG_SYSTEMS_FOOD_COLLISION_SYSTEM_H_

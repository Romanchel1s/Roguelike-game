#include "rog/systems/food_collision_system.h"

#include "lib/ecs/entity.h"
#include "lib/ecs/entity_manager.h"
#include "rog/components/food_component.h"
#include "rog/components/interface_component.h"
#include "rog/components/transform_component.h"

static bool Filter(const Entity& entity) {
  return entity.Contains<FoodComponent>() && entity.Contains<TransformComponent>();
}
bool FoodCollisionSystem::IsDead(Entity* entity_1) const {
  auto ic1 = entity_1->Get<InterfaceComponent>();
  if (ic1->hungry == 0) {
    return true;
  } else {
    return false;
  }
}
void FoodCollisionSystem::Collide(Entity* entity_1, Entity* entity_2) const {
  if (entity_1->GetId() == entity_2->GetId()) {
    return;
  }

  if (entity_1->Contains<InterfaceComponent>()) {
    auto ic1 = entity_1->Get<InterfaceComponent>();
    auto tc1 = entity_1->Get<TransformComponent>();
    auto tc2 = entity_2->Get<TransformComponent>();

    if ((tc1->x_ == tc2->x_) && (tc1->y_ == tc2->y_)) {
      entity_2->Entity::Delete<TransformComponent>();
      ic1->hungry += 20;
      if (ic1->health < 100) {
        ic1->health += 15;
        if (ic1->health > 100) {
          ic1->health = 100;
        }
      }
    }
  }
}

FoodCollisionSystem::FoodCollisionSystem(EntityManager* const entity_manager, SystemManager* const system_manager,
                                         Context* ctx)
    : ISystem(entity_manager, system_manager), ctx_(ctx) {}
void FoodCollisionSystem::OnUpdate() {
  // TODO: it should be smart, but I'm still using O(n^2).
  for (auto& entity_1 : GetEntityManager()) {
    if (entity_1.Contains<InterfaceComponent>()) {
      if (IsDead(&entity_1)) {
        ctx_->scene_ = "game_over";
      }
      for (auto& entity_2 : GetEntityManager()) {
        if (Filter(entity_2)) {
          Collide(&entity_1, &entity_2);
        }
      }
    }
  }
}

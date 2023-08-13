#include "rog/systems/door_collision_system.h"

#include "lib/ecs/entity.h"
#include "lib/ecs/entity_manager.h"
#include "rog/components/food_component.h"
#include "rog/components/interface_component.h"
#include "rog/components/transform_component.h"
#include "rog/components/door_component.h"

static bool Filter(const Entity& entity) {
  return entity.Contains<DoorComponent>() && entity.Contains<TransformComponent>();
}

void DoorCollisionSystem::Collide(Entity* entity_1, Entity* entity_2) const {
  if (entity_1->GetId() == entity_2->GetId()) {
    return;
  }

  if (entity_1->Contains<InterfaceComponent>()) {
    auto tc1 = entity_1->Get<TransformComponent>();
    auto tc2 = entity_2->Get<TransformComponent>();

    if ((tc1->x_ == tc2->x_) && (tc1->y_ == tc2->y_)) {
      ctx_->scene_ = "win";
    }
  }
}

DoorCollisionSystem::DoorCollisionSystem(EntityManager* const entity_manager, SystemManager* const system_manager,
                                         Context* ctx)
    : ISystem(entity_manager, system_manager), ctx_(ctx) {}
void DoorCollisionSystem::OnUpdate() {
  // TODO: it should be smart, but I'm still using O(n^2).
  for (auto& entity_1 : GetEntityManager()) {
    if (entity_1.Contains<InterfaceComponent>()) {
      for (auto& entity_2 : GetEntityManager()) {
        if (Filter(entity_2)) {
          Collide(&entity_1, &entity_2);
        }
      }
    }
  }
}

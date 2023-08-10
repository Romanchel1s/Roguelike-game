#include "rog/systems/collision_system.h"
#include <lib/ecs/entity.h>
#include <lib/ecs/entity_manager.h>
#include <rog/components/collider_component.h>
#include <rog/components/transform_component.h>
#include <rog/math-utils.h>

static bool Filter(const Entity& entity) {
  return entity.Contains<ColliderComponent>() && entity.Contains<TransformComponent>();
}

static void Collide(Entity* entity_1, Entity* entity_2) {
  if (entity_1->GetId() == entity_2->GetId()) {
    return;
  }

  // auto cc2 = entity_2->Get<ColliderComponent>();

  // auto tc1 = entity_1->Get<TransformComponent>();
  // auto tc2 = entity_2->Get<TransformComponent>();

  // if (tc1->pos_.x == tc2->pos_.x && tc1->pos_.y == tc2->pos_.y) {
    // cc2->Collide(entity_1);
  // }
}

CollisionSystem::CollisionSystem(EntityManager* const entity_manager, SystemManager* const system_manager)
    : ISystem(entity_manager, system_manager) {}
void CollisionSystem::OnUpdate() {
  // TODO: it should be smart, but I'm still using O(n^2).

  for (auto& entity : GetEntityManager()) {
    if (entity.Contains<ColliderComponent>()) {
      entity.Get<ColliderComponent>()->Clear();
    }
  }

  for (auto& entity_1 : GetEntityManager()) {
    if (Filter(entity_1)) {
      for (auto& entity_2 : GetEntityManager()) {
        if (Filter(entity_2)) {
          Collide(&entity_1, &entity_2);
        }
      }
    }
  }
}

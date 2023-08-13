#include "rog/systems/coin_collision_system.h"

#include <BearLibTerminal.h>
#include <lib/ecs/entity.h>
#include <lib/ecs/entity_manager.h>
#include <rog/components/coin_component.h>
#include <rog/components/interface_component.h>
#include <rog/components/transform_component.h>
#include <rog/components/texture_component.h>
#include <rog/math-utils.h>

static bool Filter(const Entity& entity) {
  return entity.Contains<CoinComponent>() && entity.Contains<TransformComponent>();
}

static void Collide(Entity* entity_1, Entity* entity_2) {
  if (entity_1->GetId() == entity_2->GetId()) {
    return;
  }

  if (entity_1->Contains<InterfaceComponent>()) {
    auto ccc1 = entity_1->Get<InterfaceComponent>();
    auto tc1 = entity_1->Get<TransformComponent>();
    auto tc2 = entity_2->Get<TransformComponent>();

    if ((tc1->x_ == tc2->x_) && (tc1->y_ == tc2->y_)) {
      entity_2->Entity::Delete<TransformComponent>();
      ccc1->coins += 1;
    }
  }
}

CoinCollisionSystem::CoinCollisionSystem(EntityManager* const entity_manager, SystemManager* const system_manager)
    : ISystem(entity_manager, system_manager) {}
void CoinCollisionSystem::OnUpdate() {
  // TODO: it should be smart, but I'm still using O(n^2).
  for (auto& entity_1 : GetEntityManager()) {
    for (auto& entity_2 : GetEntityManager()) {
      if (Filter(entity_2)) {
        Collide(&entity_1, &entity_2);
      }
    }
  }
}

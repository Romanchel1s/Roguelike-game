#include "rog/systems/coinbox_collision_system.h"

#include <BearLibTerminal.h>
#include <lib/ecs/entity.h>
#include <lib/ecs/entity_manager.h>
#include <rog/components/coin_component.h>
#include <rog/components/coinbox_component.h>
#include <rog/components/interface_component.h>
#include <rog/components/transform_component.h>

#include "rog/components/texture_component.h"

static bool Filter(const Entity& entity) {
  return entity.Contains<CoinBoxComponent>() && entity.Contains<TransformComponent>();
}

void CoinBoxCollisionSystem::Collide(Entity* entity_1, Entity* entity_2) const {
  if (entity_1->GetId() == entity_2->GetId()) {
    return;
  }

  if (entity_1->Contains<InterfaceComponent>()) {
    auto ic1 = entity_1->Get<InterfaceComponent>();
    auto tc1 = entity_1->Get<TransformComponent>();
    auto tc2 = entity_2->Get<TransformComponent>();
    auto texture2 = entity_2->Get<TextureComponent>();

    if ((tc1->x_ == tc2->x_) && (tc1->y_ == tc2->y_)) {
      entity_2->Entity::Delete<CoinBoxComponent>();
      texture2->symbol_ = '/';
      ic1->coins += 15;
      ctx_->coins += 15;
    }
  }
}

CoinBoxCollisionSystem::CoinBoxCollisionSystem(EntityManager* const entity_manager, SystemManager* const system_manager,
                                               Context* ctx)
    : ISystem(entity_manager, system_manager), ctx_(ctx) {}

void CoinBoxCollisionSystem::OnUpdate() {
  // TODO: it should be smart, but I'm still using O(n^2).
  for (auto& entity_1 : GetEntityManager()) {
    for (auto& entity_2 : GetEntityManager()) {
      if (Filter(entity_2)) {
        Collide(&entity_1, &entity_2);
      }
    }
  }
}

#include "rog/systems/player_move_system.h"

#include <rog/components/control_component.h>
#include <rog/components/interface_component.h>
#include <rog/components/transform_component.h>

#include <iostream>

#include "lib/ecs/entity_manager.h"

static bool Filter(const Entity& entity) {
  return entity.Contains<ControlComponent>() && entity.Contains<TransformComponent>() &&
         entity.Contains<InterfaceComponent>();
}

void PlayerMoveSystem::OnUpdateEntity(Entity* entity) const {
  auto pcc = entity->Get<ControlComponent>();
  auto tc = entity->Get<TransformComponent>();
  auto ic = entity->Get<InterfaceComponent>();

  if (controls_.IsPressed(pcc->up_button_)) {
    tc->y_ -= 1;
    ic->hungry -= 1;
  }
  if (controls_.IsPressed(pcc->down_button_)) {
    tc->y_ += 1;
    ic->hungry -= 1;
  }
  if (controls_.IsPressed(pcc->left_button_)) {
    tc->x_ -= 1;
    ic->hungry -= 1;
  }
  if (controls_.IsPressed(pcc->right_button_)) {
    tc->x_ += 1;
    ic->hungry -= 1;
  }
}

void PlayerMoveSystem::OnUpdate() {
  // TODO: it's slow as O(n) because to find an entity we should iterate over ALL entities.
  // But we know there is only one player to control, so may be some tag could be useful.
  for (auto& entity : GetEntityManager()) {
    if (Filter(entity)) {
      OnUpdateEntity(&entity);
    }
  }
}
PlayerMoveSystem::PlayerMoveSystem(EntityManager* const entity_manager, SystemManager* const system_manager,
                                   const Controls& controls)
    : ISystem(entity_manager, system_manager), controls_(controls) {}

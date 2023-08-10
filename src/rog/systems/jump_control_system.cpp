#include "rog/systems/jump_control_system.h"
#include <rog/components/jump_component.h>
#include <rog/components/movement_component.h>
#include <rog/components/player_control_component.h>
#include <rog/components/transform_component.h>
#include <iostream>
#include "lib/ecs/entity_manager.h"

static bool Filter(const Entity& entity) {
  return entity.Contains<MovementComponent>() && entity.Contains<JumpComponent>() &&
         entity.Contains<PlayerControlComponent>() && entity.Contains<TransformComponent>();
}

void JumpControlSystem::OnUpdateEntity(Entity* entity) const {
  // auto mc = entity->Get<MovementComponent>();
  auto pcc = entity->Get<PlayerControlComponent>();
  // auto jc = entity->Get<JumpComponent>();
  auto tc = entity->Get<TransformComponent>();

  if (controls_.IsPressed(pcc->up_button_)) {
    tc->y_ -= 1;
  }
  if (controls_.IsPressed(pcc->down_button_)) {
    tc->y_ += 1;
  }
  if (controls_.IsPressed(pcc->left_button_)) {
    tc->x_ -= 1;
  }
  if (controls_.IsPressed(pcc->right_button_)) {
    tc->x_ += 1;
  }
}

void JumpControlSystem::OnUpdate() {
  // TODO: it's slow as O(n) because to find an entity we should iterate over ALL entities.
  // But we know there is only one player to control, so may be some tag could be useful.
  for (auto& entity : GetEntityManager()) {
    if (Filter(entity)) {
      OnUpdateEntity(&entity);
    }
  }
}
JumpControlSystem::JumpControlSystem(EntityManager* const entity_manager, SystemManager* const system_manager,
                                     const Controls& controls)
    : ISystem(entity_manager, system_manager), controls_(controls) {}

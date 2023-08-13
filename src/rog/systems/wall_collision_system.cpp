#include "rog/systems/wall_collision_system.h"

#include <rog/components/control_component.h>
#include <rog/components/enemy_component.h>
#include <rog/components/interface_component.h>
#include <rog/components/transform_component.h>
#include <rog/components/wall_component.h>

#include <iostream>

#include "lib/ecs/entity_manager.h"

static bool Filter(const Entity& entity) {
  return entity.Contains<WallComponent>() && entity.Contains<TransformComponent>();
}

void WallCollisionSystem::Collide(Entity* entity_1, Entity* entity_2) const {
  if (entity_1->GetId() == entity_2->GetId()) {
    return;
  }

  if (entity_1->Contains<InterfaceComponent>()) {
    auto pcc1 = entity_1->Get<ControlComponent>();
    auto tc1 = entity_1->Get<TransformComponent>();
    auto tc2 = entity_2->Get<TransformComponent>();
    auto ic1 = entity_1->Get<InterfaceComponent>();
    if ((tc1->x_ == tc2->x_) && (tc1->y_ == tc2->y_)) {
      if (controls_.IsPressed(pcc1->up_button_)) {
        tc1->y_ += 1;
        ic1->steps -= 1;
      }
      if (controls_.IsPressed(pcc1->down_button_)) {
        tc1->y_ -= 1;
        ic1->steps -= 1;
      }
      if (controls_.IsPressed(pcc1->left_button_)) {
        tc1->x_ += 1;
        ic1->steps -= 1;
      }
      if (controls_.IsPressed(pcc1->right_button_)) {
        tc1->x_ -= 1;
        ic1->steps -= 1;
      }
    }
  }
  if (entity_1->Contains<EnemyComponent>()) {
    auto pcc1 = entity_1->Get<ControlComponent>();
    auto tc1 = entity_1->Get<TransformComponent>();
    auto tc2 = entity_2->Get<TransformComponent>();
    if ((tc1->x_ == tc2->x_) && (tc1->y_ == tc2->y_)) {
      if (controls_.IsPressed(pcc1->up_button_)) {
        tc1->y_ += 1;
      }
      if (controls_.IsPressed(pcc1->down_button_)) {
        tc1->y_ -= 1;
      }
      if (controls_.IsPressed(pcc1->left_button_)) {
        tc1->x_ += 1;
      }
      if (controls_.IsPressed(pcc1->right_button_)) {
        tc1->x_ -= 1;
      }
    }
  }
}

void WallCollisionSystem::OnUpdate() {
  // TODO: it should be smart, but I'm still using O(n^2).
  for (auto& entity_1 : GetEntityManager()) {
    for (auto& entity_2 : GetEntityManager()) {
      if (Filter(entity_2)) {
        Collide(&entity_1, &entity_2);
      }
    }
  }
}

WallCollisionSystem::WallCollisionSystem(EntityManager* const entity_manager, SystemManager* const system_manager,
                                         const Controls& controls)
    : ISystem(entity_manager, system_manager), controls_(controls) {}

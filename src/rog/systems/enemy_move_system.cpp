#include "rog/systems/enemy_move_system.h"

#include <math.h>
#include <rog/components/control_component.h>
#include <rog/components/enemy_component.h>
#include <rog/components/enemy_control_component.h>
#include <rog/components/interface_component.h>
#include <rog/components/transform_component.h>
#include <rog/components/wall_component.h>

#include <iostream>

#include "lib/ecs/entity_manager.h"

double distance(int x1, int x2, int y1, int y2) {
  return sqrt(pow((x1 - x2), 2) + pow((y1 - y2), 2));
}

static bool Filter(const Entity& entity) {
  return entity.Contains<ControlComponent>() && entity.Contains<TransformComponent>() &&
         entity.Contains<EnemyComponent>();
}

void EnemyMoveSystem::EnemyMove(Entity* entity_1, Entity* entity_2) const {
  auto tc1 = entity_1->Get<TransformComponent>();
  auto tc2 = entity_2->Get<TransformComponent>();
  auto ec = entity_2->Get<EnemyComponent>();
  auto cc = entity_2->Get<ControlComponent>();
  int start_x = ec->x_;
  int start_y = ec->y_;
  double start_length = distance(tc2->x_, tc1->x_, tc2->y_, tc1->y_);
  double down_length = distance(tc2->x_, tc1->x_, tc2->y_ + 1, tc1->y_);
  double up_length = distance(tc2->x_, tc1->x_, tc2->y_ - 1, tc1->y_);
  double left_length = distance(tc2->x_ - 1, tc1->x_, tc2->y_ - 1, tc1->y_);
  double right_length = distance(tc2->x_ + 1, tc1->x_, tc2->y_ - 1, tc1->y_);
  if (controls_.IsPressed(cc->up_button_) || controls_.IsPressed(cc->down_button_) ||
      controls_.IsPressed(cc->left_button_) || controls_.IsPressed(cc->right_button_)) {
    if (down_length < start_length && distance(start_x, tc2->x_, start_y, tc2->y_ + 1) <= ec->radius_) {
      bool can_move = true;
      for (auto& collide_entity : GetEntityManager()) {
        if (collide_entity.Contains<WallComponent>()) {
          auto tc = collide_entity.Get<TransformComponent>();
          if (tc2->y_ + 1 == tc->y_ && tc2->x_ == tc->x_) {
            can_move = false;
          }
        }
      }
      if (can_move) {
        tc2->y_ += 1;
      }
    } else if (up_length < start_length && distance(start_x, tc2->x_, start_y, tc2->y_ - 1) <= ec->radius_) {
      bool can_move = true;
      for (auto& collide_entity : GetEntityManager()) {
        if (collide_entity.Contains<WallComponent>()) {
          auto tc = collide_entity.Get<TransformComponent>();
          if (tc2->y_ - 1 == tc->y_ && tc2->x_ == tc->x_) {
            can_move = false;
          }
        }
      }
      if (can_move) {
        tc2->y_ -= 1;
      }
    } else if (left_length < start_length && distance(start_x, tc2->x_ - 1, start_y, tc2->y_ + 1) <= ec->radius_) {
      bool can_move = true;
      for (auto& collide_entity : GetEntityManager()) {
        if (collide_entity.Contains<WallComponent>()) {
          auto tc = collide_entity.Get<TransformComponent>();
          if (tc2->y_  == tc->y_ && tc2->x_ - 1 == tc->x_) {
            can_move = false;
          }
        }
      }
      if (can_move) {
        tc2->x_ -= 1;
      }
    } else if (right_length < start_length && distance(start_x, tc2->x_ + 1, start_y, tc2->y_ + 1) <= ec->radius_) {
      bool can_move = true;
      for (auto& collide_entity : GetEntityManager()) {
        if (collide_entity.Contains<WallComponent>()) {
          auto tc = collide_entity.Get<TransformComponent>();
          if (tc2->y_  == tc->y_ && tc2->x_ + 1 == tc->x_) {
            can_move = false;
          }
        }
      }
      if (can_move) {
        tc2->x_ += 1;
      }
    }
  }
}

void EnemyMoveSystem::OnUpdate() {
  for (auto& entity_1 : GetEntityManager()) {
    if (entity_1.Contains<InterfaceComponent>()) {
      for (auto& entity_2 : GetEntityManager()) {
        if (Filter(entity_2)) {
          EnemyMove(&entity_1, &entity_2);
        }
      }
    }
  }
}
EnemyMoveSystem::EnemyMoveSystem(EntityManager* const entity_manager, SystemManager* const system_manager,
                                 const Controls& controls)
    : ISystem(entity_manager, system_manager), controls_(controls) {}

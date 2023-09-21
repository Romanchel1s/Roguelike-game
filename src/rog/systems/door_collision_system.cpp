#include "rog/systems/door_collision_system.h"

#include "lib/ecs/entity.h"
#include "lib/ecs/entity_manager.h"
#include "rog/components/control_component.h"
#include "rog/components/door_component.h"
#include "rog/components/food_component.h"
#include "rog/components/interface_component.h"
#include "rog/components/key_component.h"
#include "rog/components/transform_component.h"

static bool Filter(const Entity& entity) {
  return entity.Contains<DoorComponent>() && entity.Contains<TransformComponent>();
}

void DoorCollisionSystem::Collide(Entity* entity_1, Entity* entity_2) const {
  if (entity_1->GetId() == entity_2->GetId()) {
    return;
  }

  if (entity_1->Contains<InterfaceComponent>()) {
    auto tc1 = entity_1->Get<TransformComponent>();
    auto ic1 = entity_1->Get<InterfaceComponent>();
    auto tc2 = entity_2->Get<TransformComponent>();
    auto pcc = entity_1->Get<ControlComponent>();
    auto dc2 = entity_2->Get<DoorComponent>();

    if ((tc1->x_ == tc2->x_) && (tc1->y_ == tc2->y_)) {
      if (entity_2->Contains<KeyComponent>()) {
        if (ic1->key) {
          ctx_->scene_ = dc2->next_scene_;
          if (controls_.IsPressed(pcc->up_button_)) {
            ctx_->y_ += 13;
            ctx_->x_ -= 1;
          }
          if (controls_.IsPressed(pcc->down_button_)) {
            ctx_->y_ -= 14;
          }
          if (controls_.IsPressed(pcc->left_button_)) {
            ctx_->x_ += 77;
            ctx_->y_ -= 1;
          }
          if (controls_.IsPressed(pcc->right_button_)) {
            ctx_->x_ -= 79;
            ctx_->y_ -= 1;
          }
        } else {
          if (controls_.IsPressed(pcc->up_button_)) {
            tc1->y_ += 1;
            ic1->steps -= 1;
          }
          if (controls_.IsPressed(pcc->down_button_)) {
            tc1->y_ -= 1;
            ic1->steps -= 1;
          }
          if (controls_.IsPressed(pcc->left_button_)) {
            tc1->x_ += 1;
            ic1->steps -= 1;
          }
          if (controls_.IsPressed(pcc->right_button_)) {
            tc1->x_ -= 1;
            ic1->steps -= 1;
          }
        }
      } else {
        ctx_->scene_ = dc2->next_scene_;
        if (controls_.IsPressed(pcc->up_button_)) {
          ctx_->y_ += 13;
          ctx_->x_ -= 1;
        }
        if (controls_.IsPressed(pcc->down_button_)) {
          ctx_->y_ -= 14;
        }
        if (controls_.IsPressed(pcc->left_button_)) {
          ctx_->x_ += 77;
          ctx_->y_ -= 1;
        }
        if (controls_.IsPressed(pcc->right_button_)) {
          ctx_->x_ -= 79;
          ctx_->y_ -= 1;
        }
      }
    }
  }
}

DoorCollisionSystem::DoorCollisionSystem(EntityManager* const entity_manager, SystemManager* const system_manager,
                                         const Controls& controls, Context* ctx)
    : ISystem(entity_manager, system_manager), ctx_(ctx), controls_(controls) {}

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

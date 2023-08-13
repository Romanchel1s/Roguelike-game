#include "rog/systems/steps_count_system.h"

#include <rog/components/control_component.h>
#include <rog/components/interface_component.h>

#include <iostream>

#include "lib/ecs/entity_manager.h"

static bool Filter(const Entity& entity) {
  return entity.Contains<InterfaceComponent>();
}

void StepsCountSystem::Count(Entity* entity_1) const {
  if (entity_1->Contains<InterfaceComponent>()) {
    auto ic = entity_1->Get<InterfaceComponent>();
    auto pcc1 = entity_1->Get<ControlComponent>();
    if (controls_.IsPressed(pcc1->up_button_)) {
      ic->steps += 1;
    }
    if (controls_.IsPressed(pcc1->down_button_)) {
      ic->steps += 1;
    }
    if (controls_.IsPressed(pcc1->left_button_)) {
      ic->steps += 1;
    }
    if (controls_.IsPressed(pcc1->right_button_)) {
      ic->steps += 1;
    }
  }
}

void StepsCountSystem::OnUpdate() {
  for (auto& entity_1 : GetEntityManager()) {
    if (Filter(entity_1)) {
      auto ic = entity_1.Get<InterfaceComponent>();
      if (ic->steps == ic->max_steps) {
        ctx_->scene_ = "game_over";
      }
      ctx_->steps = ic->steps;
      ctx_->coins = ic->coins;
      Count(&entity_1);
    }
  }
}

StepsCountSystem::StepsCountSystem(EntityManager* const entity_manager, SystemManager* const system_manager,
                                   const Controls& controls, Context* ctx)
    : ISystem(entity_manager, system_manager), ctx_(ctx), controls_(controls) {}

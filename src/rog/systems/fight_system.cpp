#include "rog/systems/fight_system.h"

#include "lib/ecs/entity.h"
#include "lib/ecs/entity_manager.h"
#include "rog/components/enemy_fight_component.h"
#include "rog/components/food_component.h"
#include "rog/components/interface_component.h"
#include "rog/components/key_component.h"
#include "rog/components/transform_component.h"

static bool Filter(const Entity& entity) {
  return entity.Contains<EnemyFightComponent>() && entity.Contains<TransformComponent>();
}
bool FightSystem::IsDead(Entity* entity_1) const {
  auto ic1 = entity_1->Get<InterfaceComponent>();
  if (ic1->health <= 0) {
    return true;
  } else {
    return false;
  }
}
void FightSystem::Collide(Entity* entity_1, Entity* entity_2) const {
  if (entity_1->GetId() == entity_2->GetId()) {
    return;
  }

  if (entity_1->Contains<InterfaceComponent>()) {
    auto ic1 = entity_1->Get<InterfaceComponent>();
    auto tc1 = entity_1->Get<TransformComponent>();
    auto tc2 = entity_2->Get<TransformComponent>();
    auto efc2 = entity_2->Get<EnemyFightComponent>();
    if (efc2->health_ > 0) {
      if ((tc1->x_ == tc2->x_) && (tc1->y_ == tc2->y_)) {
        ic1->health -= efc2->damage_;
        efc2->health_ -= ic1->damage;
      }
    } else if (entity_2->Contains<KeyComponent>()) {
      tc2->y_ = 1000;
      tc2->x_ = 1000;
      ctx_->key = true;
      ic1->key = true;
    } else {
      tc2->y_ = 1000;
      tc2->x_ = 1000;
    }
  }
}

FightSystem::FightSystem(EntityManager* const entity_manager, SystemManager* const system_manager, Context* ctx)
    : ISystem(entity_manager, system_manager), ctx_(ctx) {}
void FightSystem::OnUpdate() {
  // TODO: it should be smart, but I'm still using O(n^2).
  for (auto& entity_1 : GetEntityManager()) {
    if (entity_1.Contains<InterfaceComponent>()) {
      if (IsDead(&entity_1)) {
        ctx_->scene_ = "game_over";
      }
      for (auto& entity_2 : GetEntityManager()) {
        if (Filter(entity_2)) {
          Collide(&entity_1, &entity_2);
        }
      }
    }
  }
}

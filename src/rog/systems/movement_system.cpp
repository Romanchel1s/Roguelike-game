#include "rog/systems/movement_system.h"

#include "lib/ecs/entity_manager.h"
#include "rog/components/movement_component.h"
#include "rog/components/transform_component.h"

MovementSystem::MovementSystem(EntityManager* const entity_manager, SystemManager* const system_manager)
    : ISystem(entity_manager, system_manager) {}
void MovementSystem::OnUpdate() {
  for (auto& entity : GetEntityManager()) {
    if (entity.Contains<MovementComponent>() && entity.Contains<TransformComponent>()) {
      // auto tc = entity.Get<TransformComponent>();
      // auto mc = entity.Get<MovementComponent>();

      // tc->pos_ += mc->direction_ * mc->speed_;  // TODO: multiply by delta time
    }
  }
}

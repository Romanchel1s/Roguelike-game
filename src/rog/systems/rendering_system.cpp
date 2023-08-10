#include "rog/systems/rendering_system.h"
#include <BearLibTerminal.h>
#include "lib/ecs/entity_manager.h"
#include "rog/components/texture_component.h"
#include "rog/components/transform_component.h"
#include "rog/math-utils.h"

void RenderingSystem::OnUpdate() {
  for (auto& e : GetEntityManager()) {
    if (e.Contains<TransformComponent>() && e.Contains<TextureComponent>()) {
      auto texture = e.Get<TextureComponent>();
      auto transform = e.Get<TransformComponent>();

      terminal_put(transform->x_, transform->y_, texture->symbol_);
    }
  }
}
void RenderingSystem::OnPreUpdate() {
  terminal_clear();
}
void RenderingSystem::OnPostUpdate() {
  terminal_refresh();
}
RenderingSystem::RenderingSystem(EntityManager* const entity_manager, SystemManager* const system_manager)
    : ISystem(entity_manager, system_manager) {}

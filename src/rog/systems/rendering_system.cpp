#include "rog/systems/rendering_system.h"

#include <BearLibTerminal.h>

#include "lib/ecs/entity_manager.h"
#include "rog/components/color_component.h"
#include "rog/components/interface_component.h"
#include "rog/components/texture_component.h"
#include "rog/components/transform_component.h"
#include "rog/math-utils.h"

void RenderingSystem::OnUpdate() {
  terminal_bkcolor("#483D8B");
  for (auto& e : GetEntityManager()) {
    if (e.Contains<TransformComponent>() && e.Contains<TextureComponent>()) {
      auto texture = e.Get<TextureComponent>();
      auto transform = e.Get<TransformComponent>();
      if (e.Contains<ColorComponent>()) {
        auto сс = e.Get<ColorComponent>();
        terminal_color(сс->color_);
        terminal_put(transform->x_, transform->y_, texture->symbol_);
        terminal_color("white");
      } else {
        terminal_put(transform->x_, transform->y_, texture->symbol_);
      }
    }
  }
  for (auto& e : GetEntityManager()) {
    if (e.Contains<InterfaceComponent>()) {
      auto interface = e.Get<InterfaceComponent>();
      terminal_printf(1, 1, "coins: %d", interface->coins);
      terminal_printf(1, 0, "health: %d", interface->health);
      terminal_printf(15, 0, "hungry: %d", interface->hungry);
      terminal_printf(15, 1, "steps: %d", interface->steps);
      terminal_printf(30, 0, "max steps: %d", interface->max_steps);
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

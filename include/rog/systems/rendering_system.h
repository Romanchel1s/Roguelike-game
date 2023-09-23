#ifndef INCLUDE_ROG_SYSTEMS_RENDERING_SYSTEM_H_
#define INCLUDE_ROG_SYSTEMS_RENDERING_SYSTEM_H_

#include <lib/scenes/context.h>

#include "lib/ecs/system.h"

class RenderingSystem : public ISystem {
  Context* ctx_;

 protected:
  void OnPreUpdate() override;
  void OnUpdate() override;
  void OnPostUpdate() override;

 public:
  RenderingSystem(EntityManager* entity_manager, SystemManager* system_manager, Context* ctx);
};

#endif  // INCLUDE_ROG_SYSTEMS_RENDERING_SYSTEM_H_

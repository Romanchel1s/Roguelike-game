#ifndef INCLUDE_ROG_SYSTEMS_STEPS_COUNT_SYSTEM_H_
#define INCLUDE_ROG_SYSTEMS_STEPS_COUNT_SYSTEM_H_

#include <lib/ecs/system.h>
#include <lib/scenes/context.h>
#include <rog/controls.h>

class Entity;  // forward declaration because we include this class in the cpp file

class StepsCountSystem : public ISystem {
  Context* ctx_;
  const Controls& controls_;
  void Count(Entity* entity_1) const;

 protected:
  void OnUpdate() override;

 public:
  StepsCountSystem(EntityManager* entity_manager, SystemManager* system_manager, const Controls& controls,
                   Context* ctx);
};

#endif  // INCLUDE_ROG_SYSTEMS_STEPS_COUNT_SYSTEM_H_

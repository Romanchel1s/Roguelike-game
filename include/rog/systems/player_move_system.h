#ifndef INCLUDE_ROG_SYSTEMS_PLAYER_MOVE_SYSTEM_H_
#define INCLUDE_ROG_SYSTEMS_PLAYER_MOVE_SYSTEM_H_

#include <lib/ecs/system.h>
#include <lib/scenes/context.h>
#include <rog/controls.h>

class Entity;  // forward declaration because we include this class in the cpp file

class PlayerMoveSystem : public ISystem {
  Context* ctx_;
  const Controls& controls_;
  void OnUpdateEntity(Entity* entity) const;

 protected:
  void OnUpdate() override;

 public:
  PlayerMoveSystem(EntityManager* entity_manager, SystemManager* system_manager, const Controls& controls,
                   Context* ctx_);
};

#endif  // INCLUDE_ROG_SYSTEMS_PLAYER_MOVE_SYSTEM_H_

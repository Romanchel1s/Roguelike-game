#ifndef INCLUDE_ROG_SYSTEMS_ENEMY_MOVE_SYSTEM_H_
#define INCLUDE_ROG_SYSTEMS_ENEMY_MOVE_SYSTEM_H_

#include <lib/ecs/system.h>
#include <rog/controls.h>

class Entity;  // forward declaration because we include this class in the cpp file

class EnemyMoveSystem : public ISystem {
  const Controls& controls_;
  void EnemyMove(Entity* entity_1, Entity* entity_2) const;

 protected:
  void OnUpdate() override;

 public:
  EnemyMoveSystem(EntityManager* entity_manager, SystemManager* system_manager, const Controls& controls);
};

#endif  // INCLUDE_ROG_SYSTEMS_ENEMY_MOVE_SYSTEM_H_

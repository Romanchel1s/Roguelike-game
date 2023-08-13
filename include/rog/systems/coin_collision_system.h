#ifndef INCLUDE_ROG_SYSTEMS_COIN_COLLISION_SYSTEM_H_
#define INCLUDE_ROG_SYSTEMS_COIN_COLLISION_SYSTEM_H_

#include <lib/ecs/system.h>
class CoinCollisionSystem: public ISystem {
 public:
  CoinCollisionSystem(EntityManager* entity_manager, SystemManager* system_manager);

 protected:
  void OnUpdate() override;
};

#endif  // INCLUDE_ROG_SYSTEMS_COIN_COLLISION_SYSTEM_H_

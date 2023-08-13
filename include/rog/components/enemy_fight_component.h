#ifndef INCLUDE_ROG_COMPONENTS_ENEMY_FIGHT_COMPONENT_H_
#define INCLUDE_ROG_COMPONENTS_ENEMY_FIGHT_COMPONENT_H_

#include <lib/ecs/component.h>

class EnemyFightComponent : public IComponent {
 public:
  int health_;
  int damage_;

  explicit EnemyFightComponent(int health, int damage) : health_(health), damage_(damage) {}
};

#endif  // INCLUDE_ROG_COMPONENTS_ENEMY_FIGHT_COMPONENT_H_

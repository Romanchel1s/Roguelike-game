#ifndef INCLUDE_ROG_COMPONENTS_ENEMY_COMPONENT_H_
#define INCLUDE_ROG_COMPONENTS_ENEMY_COMPONENT_H_

#include <lib/ecs/component.h>


class EnemyComponent : public IComponent {
 public:
  int radius_;
  int x_;
  int y_;

  explicit EnemyComponent(int  radius, int x, int y) : radius_(radius), x_(x), y_(y) {}
};

#endif  // INCLUDE_ROG_COMPONENTS_ENEMY_COMPONENT_H_

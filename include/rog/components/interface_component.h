#ifndef INCLUDE_ROG_COMPONENTS_INTERFACE_COMPONENT_H_
#define INCLUDE_ROG_COMPONENTS_INTERFACE_COMPONENT_H_

#include <lib/ecs/component.h>


class InterfaceComponent : public IComponent {
 public:
  int coins = 0;
  int hungry = 100;
  int health = 10000;
  int steps = 0;
  int max_steps = 400;
  int damage = 10;
  bool key = false;
};

#endif  // INCLUDE_ROG_COMPONENTS_INTERFACE_COMPONENT_H_

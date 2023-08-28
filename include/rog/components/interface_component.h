#ifndef INCLUDE_ROG_COMPONENTS_INTERFACE_COMPONENT_H_
#define INCLUDE_ROG_COMPONENTS_INTERFACE_COMPONENT_H_

#include <lib/ecs/component.h>


class InterfaceComponent : public IComponent {
 public:
  int coins = 0;
  int hungry = 100;
  int health = 100;
  int steps = 0;
  int max_steps = 100;
  int damage = 10;
};

#endif  // INCLUDE_ROG_COMPONENTS_INTERFACE_COMPONENT_H_

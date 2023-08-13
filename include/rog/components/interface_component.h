#ifndef INCLUDE_ROG_COMPONENTS_INTERFACE_COMPONENT_H_
#define INCLUDE_ROG_COMPONENTS_INTERFACE_COMPONENT_H_

#include <lib/ecs/component.h>

/**
 * Иногда компоненты могут не иметь полей в принципе.
 * В таком случае такие компоненты выступают как тэги, которые
 * используются системами для определения типа сущности
 */
class InterfaceComponent : public IComponent {
 public:
  int coins = 0;
  int hungry = 50000000;
  int health = 100;
  int steps = 0;
  int max_steps = 3000000;
  int damage = 10;
};

#endif  // INCLUDE_ROG_COMPONENTS_INTERFACE_COMPONENT_H_

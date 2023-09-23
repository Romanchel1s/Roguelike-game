#ifndef INCLUDE_ROG_COMPONENTS_FOOD_COMPONENT_H_
#define INCLUDE_ROG_COMPONENTS_FOOD_COMPONENT_H_

#include <lib/ecs/component.h>

/**
 * Иногда компоненты могут не иметь полей в принципе.
 * В таком случае такие компоненты выступают как тэги, которые
 * используются системами для определения типа сущности
 */
class FoodComponent : public IComponent {
  // Nothing to do, because it's a tag for systems
};

#endif  // INCLUDE_ROG_COMPONENTS_FOOD_COMPONENT_H_

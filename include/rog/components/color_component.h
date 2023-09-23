#ifndef INCLUDE_ROG_COMPONENTS_COLOR_COMPONENT_H_
#define INCLUDE_ROG_COMPONENTS_COLOR_COMPONENT_H_

#include <lib/ecs/component.h>

#include <string>

class ColorComponent : public IComponent {
 public:
  const char *color_;

  explicit ColorComponent(const char *color) : color_(color) {}
};

#endif  // INCLUDE_ROG_COMPONENTS_COLOR_COMPONENT_H_

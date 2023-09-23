#ifndef INCLUDE_ROG_COMPONENTS_TRANSFORM_COMPONENT_H_
#define INCLUDE_ROG_COMPONENTS_TRANSFORM_COMPONENT_H_
#include <lib/ecs/component.h>
#include <lib/math/vec2.h>

class TransformComponent : public IComponent {
 public:
  int x_;
  int y_;

  explicit TransformComponent(int x, int y) : x_(x), y_(y) {}
};
#endif  // INCLUDE_ROG_COMPONENTS_TRANSFORM_COMPONENT_H_

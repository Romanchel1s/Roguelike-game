#ifndef INCLUDE_ROG_COMPONENTS_JUMP_COMPONENT_H_
#define INCLUDE_ROG_COMPONENTS_JUMP_COMPONENT_H_

#include <lib/ecs/component.h>

class JumpComponent : public IComponent {
 public:
  float max_jump_height_;
  float max_speed_y_;
  float ground_y_;

  JumpComponent(float max_jump_height, float max_speed_y, float ground_y)
      : max_jump_height_(max_jump_height), max_speed_y_(max_speed_y), ground_y_(ground_y) {}
};

#endif  // INCLUDE_ROG_COMPONENTS_JUMP_COMPONENT_H_

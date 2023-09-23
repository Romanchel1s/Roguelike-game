#ifndef INCLUDE_ROG_COMPONENTS_CONTROL_COMPONENT_H_
#define INCLUDE_ROG_COMPONENTS_CONTROL_COMPONENT_H_

#include <lib/ecs/component.h>

class ControlComponent : public IComponent {
 public:
  int up_button_;
  int down_button_;
  int left_button_;
  int right_button_;

  explicit ControlComponent(int up_button, int down_button, int left_button, int right_button)
      : up_button_(up_button), down_button_(down_button), left_button_(left_button), right_button_(right_button) {}
};

#endif  // INCLUDE_ROG_COMPONENTS_CONTROL_COMPONENT_H_

#ifndef INCLUDE_ROG_COMPONENTS_DOOR_COMPONENT_H_
#define INCLUDE_ROG_COMPONENTS_DOOR_COMPONENT_H_

#include <lib/ecs/component.h>
#include <string>


class DoorComponent : public IComponent {
 public:
  std::string next_scene_ = "";
  // const std::string *next_scene_ = "";

  explicit DoorComponent(std::string next_scene) : next_scene_(next_scene) {}
  // const char *next_scene_;

  // explicit DoorComponent(char *next_scene) : next_scene_(next_scene) {}
};

#endif  // INCLUDE_ROG_COMPONENTS_DOOR_COMPONENT_H_

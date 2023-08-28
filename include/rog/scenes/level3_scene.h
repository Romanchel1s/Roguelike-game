#ifndef INCLUDE_ROG_SCENES_LEVEL3_SCENE_H_
#define INCLUDE_ROG_SCENES_LEVEL3_SCENE_H_

#include <lib/ecs/engine.h>
#include <lib/scenes/i_scene.h>
#include <rog/controls.h>

class ThirdLevelScene : public IScene {
  const Engine engine{};
  const Controls& controls;

 public:
  ThirdLevelScene(Context* const ctx, const Controls& controls);

  void OnCreate() override;
  void OnRender() override;
  void OnExit() override;
};

#endif  // INCLUDE_ROG_SCENES_LEVEL3_SCENE_H_

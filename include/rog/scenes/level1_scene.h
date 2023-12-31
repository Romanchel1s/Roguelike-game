#ifndef INCLUDE_ROG_SCENES_LEVEL1_SCENE_H_
#define INCLUDE_ROG_SCENES_LEVEL1_SCENE_H_

#include <lib/ecs/engine.h>
#include <lib/scenes/i_scene.h>
#include <rog/controls.h>

class GameScene : public IScene {
  const Engine engine{};
  const Controls& controls;

 public:
  GameScene(Context* const ctx, const Controls& controls);

  void OnCreate() override;
  void OnRender() override;
  void OnExit() override;
};

#endif  // INCLUDE_ROG_SCENES_LEVEL1_SCENE_H_

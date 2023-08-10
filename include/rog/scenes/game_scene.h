#ifndef INCLUDE_ROG_SCENES_GAME_SCENE_H_
#define INCLUDE_ROG_SCENES_GAME_SCENE_H_

#include <lib/ecs/engine.h>
#include <lib/scenes/i_scene.h>
#include <rog/controls.h>

class GameScene : public IScene {
  const int width_ = 80;
  const int ground_y_ = 15;
  const float gravity_ = 0.2;
  const Engine engine{};
  const Controls& controls;

 public:
  GameScene(Context* const ctx, const Controls& controls);

  void OnCreate() override;
  void OnRender() override;
  void OnExit() override;
};

#endif  // INCLUDE_ROG_SCENES_GAME_SCENE_H_

#ifndef INCLUDE_ROG_SCENES_WIN_SCENE_H_
#define INCLUDE_ROG_SCENES_WIN_SCENE_H_

#include "lib/scenes/i_scene.h"
#include "rog/controls.h"

class WinScene : public IScene {
  const Controls& controls_;

 public:
  WinScene(Context* ctx, const Controls& controls);
  void OnCreate() override;
  void OnRender() override;
  void OnExit() override;
};

#endif  // INCLUDE_ROG_SCENES_WIN_SCENE_H_

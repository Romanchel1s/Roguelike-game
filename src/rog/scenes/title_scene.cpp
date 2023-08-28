#include "rog/scenes/title_scene.h"
#include <BearLibTerminal.h>
void TitleScene::OnCreate() {}
void TitleScene::OnRender() {
  terminal_clear();
  terminal_print(1, 1, "Rog Game\nPress Enter to start");
  terminal_print(1, 3, "Random Rog Level\nPress Shift to start");
  if (controls_.IsPressed(TK_ENTER)) {
    ctx_->scene_ = "game";  // переходим на другую сцену
    ctx_->x_ = 5;
    ctx_->y_ = 5;
  }
  if (controls_.IsPressed(TK_SHIFT)) {
    ctx_->scene_ = "random_level";  // переходим на другую сцену
    ctx_->x_ = 5;
    ctx_->y_ = 5;
  }
  terminal_refresh();
}
void TitleScene::OnExit() {}
TitleScene::TitleScene(Context *ctx, const Controls &controls) : IScene(ctx), controls_(controls) {}

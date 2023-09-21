#include "rog/scenes/title_scene.h"

#include <BearLibTerminal.h>
void TitleScene::OnCreate() {}
void TitleScene::OnRender() {
  terminal_clear();
  terminal_set("0x23: none");
  terminal_set("0x24: none");
  terminal_set("0x25: none");
  terminal_set("0x40: none");
  terminal_set("0x45: none");
  terminal_set("0x3E: none");
  if (ctx_->graphics) {
    terminal_print(25, 1, "Graphics mode is ON\nPress Space to change");
  } else {
    terminal_print(25, 1, "Graphics mode is OFF\nPress Space to change");
  }
  terminal_print(25, 5, "Rog Game\nPress Enter to start");
  terminal_print(25, 8, "Random Rog Level\nPress Shift to start");
  if (controls_.IsPressed(TK_SPACE)) {
    if (ctx_->graphics) {
      ctx_->graphics = false;
    } else {
      ctx_->graphics = true;
    }
  }
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

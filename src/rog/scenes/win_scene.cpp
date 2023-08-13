#include "rog/scenes/win_scene.h"
#include <BearLibTerminal.h>
void WinScene::OnCreate() {}
void WinScene::OnRender() {
  terminal_clear();
  terminal_printf(1, 2, "collected coins: %d", ctx_->coins);
  terminal_printf(1, 3, "steps taken: %d", ctx_->steps);
  terminal_print(1, 4, "Press Enter to go to main menu");
  if (controls_.IsPressed(TK_ENTER)) {
    ctx_->scene_ = "title";  // переходим на другую сцену
  }
  terminal_refresh();
}
void WinScene::OnExit() {}
WinScene::WinScene(Context *ctx, const Controls &controls) : IScene(ctx), controls_(controls) {}

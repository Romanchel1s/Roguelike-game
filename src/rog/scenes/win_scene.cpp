#include "rog/scenes/win_scene.h"

#include <BearLibTerminal.h>

#include <algorithm>

void WinScene::OnCreate() {}
void WinScene::OnRender() {
  terminal_clear();
  terminal_set("0x23: none");
  terminal_set("0x24: none");
  terminal_set("0x25: none");
  terminal_set("0x40: none");
  terminal_set("0x45: none");
  terminal_set("0x3E: none");
  ctx_->leaderBord.push_back(ctx_->steps);
  int record = *min_element(ctx_->leaderBord.begin(), ctx_->leaderBord.end());
  terminal_print(25, 5, "You win!");
  terminal_printf(25, 6, "collected coins: %d", ctx_->coins);
  terminal_printf(25, 7, "steps taken: %d", ctx_->steps);
  terminal_print(25, 8, "Press Enter to go to main menu");
  terminal_printf(25, 9, "Record on level by steps: %d", record);
  if (controls_.IsPressed(TK_ENTER)) {
    ctx_->scene_ = "title";  // переходим на другую сцену
    ctx_->coins = 0;
    ctx_->steps = 0;
    ctx_->key = false;
  }
  terminal_refresh();
}
void WinScene::OnExit() {}
WinScene::WinScene(Context *ctx, const Controls &controls) : IScene(ctx), controls_(controls) {}

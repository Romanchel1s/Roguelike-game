#include "rog/scenes/game_over_scene.h"

#include <BearLibTerminal.h>

#include "rog/components/interface_component.h"
void GameOverScene::OnCreate() {}
void GameOverScene::OnRender() {
  terminal_clear();
  terminal_set("0x23: none");
  terminal_set("0x24: none");
  terminal_set("0x25: none");
  terminal_set("0x40: none");
  terminal_set("0x45: none");
  terminal_set("0x3E: none");
  terminal_print(25, 5, "Game Over");
  terminal_printf(25, 6, "collected coins: %d", ctx_->coins);
  terminal_printf(25, 7, "steps taken: %d", ctx_->steps);
  terminal_print(25, 8, "Press Enter to go to main menu");
  if (controls_.IsPressed(TK_ENTER)) {
    ctx_->scene_ = "title";  // переходим на другую сцену
  }
  ctx_->coins = 0;
  ctx_->steps = 0;
  ctx_->key = false;
  terminal_refresh();
}
void GameOverScene::OnExit() {}
GameOverScene::GameOverScene(Context *ctx, const Controls &controls) : IScene(ctx), controls_(controls) {}

#include "rog/scenes/game_over_scene.h"

#include <BearLibTerminal.h>

#include "rog/components/interface_component.h"
void GameOverScene::OnCreate() {}
void GameOverScene::OnRender() {
  terminal_clear();
  terminal_print(1, 1, "Game Over");
  terminal_printf(1, 2, "collected coins: %d", ctx_->coins);
  terminal_printf(1, 3, "steps taken: %d", ctx_->steps);
  terminal_print(1, 4, "Press Enter to go to main menu");
  if (controls_.IsPressed(TK_ENTER)) {
    ctx_->scene_ = "title";  // переходим на другую сцену
  }
  terminal_refresh();
}
void GameOverScene::OnExit() {}
GameOverScene::GameOverScene(Context *ctx, const Controls &controls) : IScene(ctx), controls_(controls) {}

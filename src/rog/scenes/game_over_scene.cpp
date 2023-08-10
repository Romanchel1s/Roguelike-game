#include "rog/scenes/game_over_scene.h"
#include <BearLibTerminal.h>
void GameOverScene::OnCreate() {}
void GameOverScene::OnRender() {
  terminal_clear();
  terminal_print(1, 1, "Game Over\nScore is ?\nPress Enter to go to main menu");
  if (controls_.IsPressed(TK_ENTER)) {
    ctx_->scene_ = "title";  // переходим на другую сцену
  }
  terminal_refresh();
}
void GameOverScene::OnExit() {}
GameOverScene::GameOverScene(Context *ctx, const Controls &controls) : IScene(ctx), controls_(controls) {}

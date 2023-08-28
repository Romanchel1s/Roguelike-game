#include <BearLibTerminal.h>
#include <rog/controls.h>
#include <rog/scenes/level1_scene.h>

#include "lib/scenes/scene_manager.h"
#include "rog/scenes/game_over_scene.h"
#include "rog/scenes/level2_scene.h"
#include "rog/scenes/level3_scene.h"
#include "rog/scenes/random_level_scene.h"
#include "rog/scenes/title_scene.h"
#include "rog/scenes/win_scene.h"

int main() {
  terminal_open();
  terminal_refresh();

  Controls controls;

  Context ctx{};  // создаем контекст на стеке в самом начале приложения
  SceneManager sm(ctx);  // создаем менеджер сцен на стеке

  // Регистрируем сцены в менеджер. Обратите внимание,
  // что деструкторы над сценами вызывать здесь не надо, так как изх вызовет менеджер.
  sm.Put("title", new TitleScene(&ctx, controls));
  sm.Put("game", new GameScene(&ctx, controls));
  sm.Put("game_over", new GameOverScene(&ctx, controls));
  sm.Put("win", new WinScene(&ctx, controls));
  sm.Put("level2", new SecondLevelScene(&ctx, controls));
  sm.Put("level3", new ThirdLevelScene(&ctx, controls));
  sm.Put("random_level", new RandomLevelScene(&ctx, controls));

  // Выставляем текущую сцену
  ctx.scene_ = "title";

  // Ждем, пока пользователь не закроет окно
  while (true) {
    controls.OnUpdate();
    if (controls.IsPressed(TK_CLOSE)) {
      break;
    }

    sm.OnRender();

    controls.Reset();
  }
  sm.OnExit();

  terminal_close();
}


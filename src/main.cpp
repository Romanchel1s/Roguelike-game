#include <BearLibTerminal.h>

#include <cmath>
#include <iostream>
#include <vector>

#include "../include/coin-manager.h"
#include "../include/controls.h"
#include "../include/food-manager.h"
#include "../include/player.h"
#include "../include/wall-manager.h"
#include "../include/level1.h"
#include "../src/level1.cpp"
#include "../include/ld-manager.h"
#include "../src/ld-manager.cpp"
#include "../include/config.h"
#include "../src/config.cpp"

int main() {
  terminal_open();
  terminal_refresh();

  Controls controls;
  FirstLevel fl;
  Config config = fl.ReadLevel();
  Player player{'@', 5, 5, controls};
  CoinsManager cm(player, config.CoinsConfig());
  FoodManager  fm(player, controls, config.FoodConfig());
  WallsManager wm(&player, controls, config.WallsConfig());
  while (true) {
    terminal_clear();
    controls.Update();
    if (controls.IsExit()) {
      break;
    }
    terminal_bkcolor("#483D8B");
    if (fm.DeathFromHungry()) {
      terminal_color("red");
      terminal_print(34, 10, "GAME OVER");
      terminal_refresh();
      continue;
    }
    fl.ReadLevel();
    cm.Update();
    player.Update();
    if (wm.Touched()) {
      continue;
    }
    fm.Update();
    terminal_refresh();
  }

  terminal_close();
}

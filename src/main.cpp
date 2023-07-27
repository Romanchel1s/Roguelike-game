#include <BearLibTerminal.h>

#include <cmath>
#include <iostream>
#include <vector>

#include "../include/coin-manager.h"
#include "../include/controls.h"
#include "../include/food-manager.h"
#include "../include/player.h"

int main() {
  terminal_open();
  terminal_refresh();

  Controls controls;
  Player player{'@', 1, 1, controls};
  CoinsManager cm(player);
  FoodManager  fm(player, controls);

  while (true) {
    terminal_clear();

    controls.Update();
    if (controls.IsExit()) {
      break;
    }
    cm.Update();
    player.Update();
    fm.Update();
    terminal_refresh();
  }

  terminal_close();
}

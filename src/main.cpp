#include <BearLibTerminal.h>

#include <cmath>
#include <iostream>
#include <vector>

#include "../include/controls.h"
#include "../include/player.h"
#include "../include/coin-manager.h"

int main() {
  terminal_open();
  terminal_refresh();

  Controls controls;
  Player player{'@', 1, 1, controls};
  CoinsManager cm(player);

  while (true) {
    terminal_clear();

    controls.Update();
    if (controls.IsExit()) {
      break;
    }

    cm.Update();
    player.Update();

    terminal_refresh();
  }

  terminal_close();
}

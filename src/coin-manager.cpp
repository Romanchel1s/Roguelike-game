#include <BearLibTerminal.h>
#include "../include/coin-manager.h"
#include "vector"



void CoinsManager::Update() {
  terminal_printf(1, 0, "coins: %d", coincount);
  std::vector<Coin> coinshelper;
  for (auto &o : coins) {
    if (player_.GetX() == o.x && player_.GetY() == o.y) {
      coincount += 1;
    } else {
      coinshelper.push_back(o);
    }
    coins = coinshelper;
    o.Update();
  }
}

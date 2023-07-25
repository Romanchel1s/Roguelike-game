#include <BearLibTerminal.h>
#include "../include/coin.h"

void Coin::Update() {
  terminal_put(x, y, '$');
}

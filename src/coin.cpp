#include <BearLibTerminal.h>
#include "../include/coin.h"

void Coin::Update() {
  terminal_color("green");
  terminal_put(x, y, '$');
  terminal_color("white");
}

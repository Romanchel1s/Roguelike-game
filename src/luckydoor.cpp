#include <BearLibTerminal.h>
#include "../include/luckydoor.h"

void LuckyDoor::Update() {
  terminal_color("purple");
  terminal_put(x, y, '?');
  terminal_color("white");
}

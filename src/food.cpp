#include <BearLibTerminal.h>
#include "../include/food.h"

void Food::Update() {
  terminal_color("orange");
  terminal_put(x, y, '%');
  terminal_color("white");
}

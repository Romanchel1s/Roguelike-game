#include <BearLibTerminal.h>
#include "../include/food.h"

void Food::Update() {
  terminal_put(x, y, '%');
}
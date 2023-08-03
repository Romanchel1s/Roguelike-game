//
// Created by rpurt on 29.07.2023.
//

#include <BearLibTerminal.h>
#include "../include/wall.h"

void Wall::Update() {
  terminal_put(x, y, symbol);
}


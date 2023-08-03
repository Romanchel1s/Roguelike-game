#include <BearLibTerminal.h>
#include "../include/wall-manager.h"
#include "../include/controls.h"
#include "vector"


bool WallsManager::Touched() {
  for (auto &o : walls) {
    if ((player_.GetX() == o.x && player_.GetY() == o.y)) {
      player_.GetBack();
      return true;
    }
    o.Update();
  }
  return false;
}

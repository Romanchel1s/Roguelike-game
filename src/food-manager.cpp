#include <BearLibTerminal.h>
#include "../include/food-manager.h"
#include "vector"


void FoodManager::GetHungry() {
  if (controls.IsMovingDown()) {
    hunger -= 1;
  }
  if (controls.IsMovingUp()) {
    hunger -= 1;
  }
  if (controls.IsMovingLeft()) {
    hunger -= 1;
  }
  if (controls.IsMovingRight()) {
    hunger -= 1;
  }
}

bool FoodManager::DeathFromHungry() {
  if (hunger == 0) {
    return true;
  } else {
    return false;
  }
}
void FoodManager::Update() {
    terminal_printf(1, 1, "hungry: %d", hunger);
  std::vector<Food> foodhelper;
  GetHungry();
  for (auto &o : food) {
    if (player_.GetX() == o.x && player_.GetY() == o.y) {
      hunger += 200;
    } else {
      foodhelper.push_back(o);
    }
    food = foodhelper;
    o.Update();
  }
}

#ifndef INCLUDE_FOOD_MANAGER_H_
#define INCLUDE_FOOD_MANAGER_H_

#include "../include/food.h"
#include "../include/player.h"
#include "../include/controls.h"
#include "vector"

class FoodManager {
  const Player &player_;
  int hunger = 200;
  const Controls &controls;
  std::vector<Food> food{{20, 15}, {30, 15}, {20, 40}};

 public:
  explicit FoodManager(const Player &player, const Controls &controls) : player_(player), controls(controls) {}

  void GetHungry();
  void Update();
};

#endif  // INCLUDE_FOOD_MANAGER_H_

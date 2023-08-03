#ifndef INCLUDE_FOOD_MANAGER_H_
#define INCLUDE_FOOD_MANAGER_H_

#include "../include/food.h"
#include "../include/player.h"
#include "../include/controls.h"
#include "vector"

class FoodManager {
  const Player &player_;
  int hunger = 50;
  const Controls &controls;
  std::vector<Food> food;

 public:
  explicit FoodManager(const Player &player, const Controls &controls, const std::vector<Food> &food)
      : player_(player), controls(controls), food(food) {}

  bool DeathFromHungry();
  void GetHungry();
  void Update();
};

#endif  // INCLUDE_FOOD_MANAGER_H_

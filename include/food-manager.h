#ifndef INCLUDE_FOOD_MANAGER_H_
#define INCLUDE_FOOD_MANAGER_H_

#include "../include/player.h"
#include "../include/food.h"
#include "vector"

class FoodManager {
  const Player &player_;
  int hunger = 0;
  std::vector<Food> food{
      {30, 20}, {55, 15}, {70, 18}};

 public:
  explicit FoodManager(const Player &player): player_(player) {}

  void Update();
};

#endif  // INCLUDE_FOOD_MANAGER_H_
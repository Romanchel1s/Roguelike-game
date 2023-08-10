#ifndef INCLUDE_CONFIG_H_
#define INCLUDE_CONFIG_H_

#include <vector>
#include "../include/coin-manager.h"
#include "../include/food-manager.h"
#include "../include/player.h"
#include "../include/wall-manager.h"
class Config {
  std::vector<Wall> walls;
  std::vector<Coin> coins;
  std::vector<Food> food;

 public:
  int x;
  int y;

  Config(std::vector<Wall> walls, std::vector<Coin> coins, std::vector<Food> food)
      : walls(walls), coins(coins), food(food) {}

  std::vector<Wall> WallsConfig();
  std::vector<Coin> CoinsConfig();
  std::vector<Food> FoodConfig();
};

#endif  // INCLUDE_CONFIG_H_

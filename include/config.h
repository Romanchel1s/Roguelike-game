#ifndef INCLUDE_CONFIG_H_
#define INCLUDE_CONFIG_H_

#include <vector>
#include "lib/math/vec2.h"
class Config {
  std::vector<Vec2> walls;
  std::vector<Vec2> coins;
  std::vector<Vec2> food;

 public:
  int x;
  int y;

  Config(std::vector<Vec2> walls, std::vector<Vec2> coins, std::vector<Vec2> food)
      : walls(walls), coins(coins), food(food) {}

  std::vector<Vec2> WallsConfig();
  std::vector<Vec2> CoinsConfig();
  std::vector<Vec2> FoodConfig();
};

#endif  // INCLUDE_CONFIG_H_

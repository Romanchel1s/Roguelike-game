#ifndef INCLUDE_CONFIG_H_
#define INCLUDE_CONFIG_H_

#include <vector>

#include "lib/math/vec2.h"
class Config {
  std::vector<Vec2> walls;
  std::vector<Vec2> coins;
  std::vector<Vec2> food;
  std::vector<Vec2> doors;
  std::vector<Vec2> enemy;
  std::vector<Vec2> player;
  std::vector<Vec2> coinbox;

 public:
  int x;
  int y;

  Config(std::vector<Vec2> walls, std::vector<Vec2> coins, std::vector<Vec2> food, std::vector<Vec2> doors,
         std::vector<Vec2> enemy, std::vector<Vec2> player, std::vector<Vec2> coinbox)
      : walls(walls), coins(coins), food(food), doors(doors), enemy(enemy), player(player), coinbox(coinbox) {}

  std::vector<Vec2> WallsConfig();
  std::vector<Vec2> CoinsConfig();
  std::vector<Vec2> FoodConfig();
  std::vector<Vec2> DoorsConfig();
  std::vector<Vec2> EnemyConfig();
  std::vector<Vec2> PlayerConfig();
  std::vector<Vec2> CoinBoxConfig();
};

#endif  // INCLUDE_CONFIG_H_

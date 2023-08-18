#include "../include/config.h"
#include <vector>
std::vector<Vec2> Config::CoinsConfig() {
  return coins;
}
std::vector<Vec2> Config::FoodConfig() {
  return food;
}
std::vector<Vec2> Config::WallsConfig() {
  return walls;
}
std::vector<Vec2> Config::DoorsConfig() {
  return doors;
}
std::vector<Vec2> Config::EnemyConfig() {
  return enemy;
}
std::vector<Vec2> Config::PlayerConfig() {
  return player;
}

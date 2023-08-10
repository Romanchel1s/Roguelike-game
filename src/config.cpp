#include "../include/config.h"
#include <vector>
std::vector<Coin> Config::CoinsConfig() {
  return coins;
}
std::vector<Food> Config::FoodConfig() {
  return food;
}
std::vector<Wall> Config::WallsConfig() {
  return walls;
}

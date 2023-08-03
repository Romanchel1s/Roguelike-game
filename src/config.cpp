#include "../include/config.h"

std::vector<Coin> Config::CoinsConfig() {
  return coins;
}
std::vector<Food> Config::FoodConfig() {
  return food;
}
std::vector<Wall> Config::WallsConfig() {
  return walls;
}
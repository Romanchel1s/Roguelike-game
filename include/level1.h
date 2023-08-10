#ifndef INCLUDE_LEVEL1_H_
#define INCLUDE_LEVEL1_H_
#include <vector>
#include "../include/coin-manager.h"
#include "../include/controls.h"
#include "../include/food-manager.h"
#include "../include/player.h"
#include "../include/wall-manager.h"
#include "../include/ireader.h"
#include "../include/config.h"

class FirstLevel : public IReader {
  std::vector<Wall> walls;
  std::vector<Coin> coins;
  std::vector<Food> food;
 public:
  Config ReadLevel();
};

#endif  // INCLUDE_LEVEL1_H_

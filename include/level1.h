#ifndef INCLUDE_LEVEL1_H_
#define INCLUDE_LEVEL1_H_
#include <vector>
#include "../include/ireader.h"
#include "../include/config.h"

class FirstLevel : public IReader {
  std::vector<Vec2> walls;
  std::vector<Vec2> coins;
  std::vector<Vec2> food;
  std::vector<Vec2> doors;
  std::vector<Vec2> enemy;
  std::vector<Vec2> player;
 public:
  Config ReadLevel();
};

#endif  // INCLUDE_LEVEL1_H_

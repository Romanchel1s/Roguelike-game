#ifndef INCLUDE_LEVEL1_H_
#define INCLUDE_LEVEL1_H_
#include <vector>
#include "../include/ireader.h"
#include "../include/config.h"

class FirstLevel : public IReader {
  std::vector<Vec2> walls;
  std::vector<Vec2> coins;
  std::vector<Vec2> food;
 public:
  Config ReadLevel();
};

#endif  // INCLUDE_LEVEL1_H_

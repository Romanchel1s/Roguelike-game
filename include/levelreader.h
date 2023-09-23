#ifndef INCLUDE_LEVELREADER_H_
#define INCLUDE_LEVELREADER_H_
#include <vector>
#include <string>
#include "../include/ireader.h"
#include "../include/config.h"

class LevelReader : public IReader {
  std::vector<Vec2> walls;
  std::vector<Vec2> coins;
  std::vector<Vec2> food;
  std::vector<Vec2> doors;
  std::vector<Vec2> enemy;
  std::vector<Vec2> player;
  std::vector<Vec2> coinbox;
 public:
  Config ReadLevel(std::string way);
};

#endif  // INCLUDE_LEVELREADER_H_

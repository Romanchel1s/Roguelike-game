#ifndef INCLUDE_IREADER_H_
#define INCLUDE_IREADER_H_

#include "../include/coin-manager.h"
#include "../include/config.h"
#include "../include/controls.h"
#include "../include/food-manager.h"
#include "../include/player.h"
#include "../include/wall-manager.h"

class IReader {
 public:
  virtual Config ReadLevel() = 0;
};

#endif  // INCLUDE_IREADER_H_

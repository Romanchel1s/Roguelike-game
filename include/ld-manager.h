#ifndef INCLUDE_LD_MANAGER_H_
#define INCLUDE_LD_MANAGER_H_

#include "../include/player.h"
#include "../include/luckydoor.h"
#include "vector"

class LDManager {
  const Player &player_;
  bool death = false;
  std::vector<LuckyDoor> doors{{22, 12}};

 public:
  explicit LDManager(const Player &player) : player_(player) {}

  void Update();
  bool DeathFromUnLucky();
};

#endif  // INCLUDE_LD_MANAGER_H_

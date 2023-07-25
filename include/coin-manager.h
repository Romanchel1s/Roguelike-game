#ifndef INCLUDE_COIN_MANAGER_H_
#define INCLUDE_COIN_MANAGER_H_

#include "../include/player.h"
#include "../include/coin.h"
#include "vector"

class CoinsManager {
  const Player &player_;
  int coincount = 0;
  std::vector<Coin> coins{
      {30, 20}, {55, 15}, {70, 18}};

 public:
  explicit CoinsManager(const Player &player): player_(player) {}

  void Update();
};

#endif  // INCLUDE_COIN_MANAGER_H_



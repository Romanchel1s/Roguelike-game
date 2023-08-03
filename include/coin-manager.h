#ifndef INCLUDE_COIN_MANAGER_H_
#define INCLUDE_COIN_MANAGER_H_

#include "../include/player.h"
#include "../include/coin.h"
#include "vector"

class CoinsManager {
  const Player &player_;
  int coincount = 0;
  std::vector<Coin> coins;

 public:
  explicit CoinsManager(const Player &player, const std::vector<Coin> &coins) : player_(player), coins(coins) {}
  void Update();
};

#endif  // INCLUDE_COIN_MANAGER_H_



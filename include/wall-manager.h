#ifndef INCLUDE_WALL_MANAGER_H_
#define INCLUDE_WALL_MANAGER_H_

#include "../include/player.h"
#include "../include/wall.h"
#include "../include/controls.h"
#include "vector"

class WallsManager {
  Player &player_;
  const Controls &controls;
  std::vector<Wall> walls;
 public:
  explicit WallsManager(Player *player, const Controls &controls, const std::vector<Wall> &walls)
      : player_(*player), controls(controls), walls(walls) {}

  bool Touched();
};

#endif  // INCLUDE_WALL_MANAGER_H_

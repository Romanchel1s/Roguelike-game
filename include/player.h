//
// Created by rpurt on 22.07.2023.
//

#ifndef INCLUDE_PLAYER_H_
#define INCLUDE_PLAYER_H_

#include "../include/controls.h"

class Player {
  char symbol = '@';
  int x_;
  int y_;
  int stepcounter = 0;
  const Controls& controls;

  void Render();

  void Move();

  void StepCount();

 public:
  Player(char symbol, int x, int y, const Controls &controls) : symbol(symbol), x_(x), y_(y), controls(controls) {}

  void Update();
  int GetX() const;
  int GetY() const;
  void GetBack();
};

#endif  // INCLUDE_PLAYER_H_

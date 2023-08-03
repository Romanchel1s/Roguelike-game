//
// Created by rpurt on 29.07.2023.
//

#ifndef INCLUDE_WALL_H_
#define INCLUDE_WALL_H_

class Wall {
  char symbol = '#';

 public:
  int x;
  int y;

  Wall(int x, int y) : x(x), y(y) {}

  void Update();
};

#endif  // INCLUDE_WALL_H_

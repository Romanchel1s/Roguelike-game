#ifndef INCLUDE_COIN_H_
#define INCLUDE_COIN_H_

class Coin {
  char symbol = '$';

 public:
  int x;
  int y;

  Coin(int x, int y) : x(x), y(y) {}

  void Update();
};

#endif  // INCLUDE_COIN_H_

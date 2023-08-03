#ifndef INCLUDE_LUCKYDOOR_H_
#define INCLUDE_LUCKYDOOR_H_

class LuckyDoor {
  char symbol = '?';

 public:
  int x;
  int y;

  LuckyDoor(int x, int y) : x(x), y(y) {}

  void Update();
};

#endif  // INCLUDE_LUCKYDOOR_H_

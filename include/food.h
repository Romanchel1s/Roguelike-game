#ifndef INCLUDE_FOOD_H_
#define INCLUDE_FOOD_H_

class Food {
  char symbol = '%';

 public:
  int x;
  int y;

  Food(int x, int y) : x(x), y(y) {}

  void Update();
};

#endif  // INCLUDE_FOOD_H_
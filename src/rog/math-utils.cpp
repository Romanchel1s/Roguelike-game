#include "rog/math-utils.h"
#include <cmath>

int ToPos(float x) {
  return static_cast<int>(std::round(x));
}

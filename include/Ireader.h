#ifndef INCLUDE_IREADER_H_
#define INCLUDE_IREADER_H_

#include "../include/config.h"

class IReader {
 public:
  virtual Config ReadLevel() = 0;
};

#endif  // INCLUDE_IREADER_H_

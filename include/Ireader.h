#ifndef INCLUDE_IREADER_H_
#define INCLUDE_IREADER_H_

#include <string>
#include "../include/config.h"

class IReader {
 public:
  virtual Config ReadLevel(std::string) = 0;
};

#endif  // INCLUDE_IREADER_H_

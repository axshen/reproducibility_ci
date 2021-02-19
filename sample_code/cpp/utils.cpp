// Copyright 2021 Austin Shen

#include <cstdlib>
#include "sample_code/cpp/utils.h"

int getRandomNumber(int min, int max) {
  static double fraction = 1.0 / (RAND_MAX + 1.0);
  return min + static_cast<int>((max - min + 1) * (std::rand() * fraction));
}

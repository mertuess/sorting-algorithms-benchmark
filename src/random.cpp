/// @file random.cpp
#include "random.h"

#include <random>
#include <time.h>

namespace sort {
Range Random::Range(int min_include, int max_exclude, size_t lenght) {
  struct Range range;
  range.size = lenght;
  // Allocate memory for array
  range.data = static_cast<int *>(malloc(lenght * sizeof(int)));

  // Initialize random number generator
  std::random_device rd;
  std::default_random_engine re(rd());
  re.seed(static_cast<unsigned int>(time(NULL)));

  // Define uniform distribution
  std::uniform_int_distribution<int> uniform_dist(min_include, max_exclude - 1);

  // Fill array with random numbers
  for (size_t i = 0; i < lenght; ++i) {
    range.data[i] = uniform_dist(re);
  }
  return range;
}
} // namespace sort

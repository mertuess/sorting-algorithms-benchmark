/// @file random.h
/// @brief Random number generation utilities

#ifndef RANDOM_H
#define RANDOM_H

#include <iostream>
#include <ostream>

namespace sort {

/// @brief Structure representing a range of integer values
struct Range {
  size_t size; ///< Size of the array
  int *data;   ///< Pointer to array data

  /// @brief Output operator for Range
  /// @param os Output stream
  /// @param range Range to output
  /// @return Output stream
  friend std::ostream &operator<<(std::ostream &os, const Range &range) {
    os << "[";
    for (size_t i = 0; i < range.size; ++i) {
      if (i == range.size - 1) {
        os << range.data[i];
        continue;
      }
      os << range.data[i] << ", ";
    }
    os << "]\n";
    return os;
  }
};

/// @brief Random number generator class
class Random {
public:
  Random() = default;

  /// @brief Generate a random range of numbers
  /// @param min_include Minimum value (inclusive)
  /// @param max_exclude Maximum value (exclusive)
  /// @param lenght Number of elements to generate
  /// @return Range structure with random numbers
  static Range Range(int min_inlcude, int max_exclude, size_t lenght);
};

} // namespace sort

#endif // !RANDOM_H

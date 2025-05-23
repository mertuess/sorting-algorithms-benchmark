/// @file i_sorter.h
/// @brief Interface for sorting algorithms

#ifndef I_SORTER_H
#define I_SORTER_H

#include "i_outputable.h"

/// @brief Interface for sortable objects
class ISorter : public IOutputable {
public:
  /// @brief Perform the sorting operation
  /// @return Number of swaps performed
  virtual unsigned int Sort(bool visualize) = 0;

  /// @brief Virtual destructor
  virtual ~ISorter() = default;
};

#endif // I_SORTER_H

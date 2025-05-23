/// @file quick.h
/// @brief Quick Sort algorithm implementation

#ifndef QUICK_H
#define QUICK_H

#include "i_sorter.h"
#include "random.h"

namespace sort {

/// @brief Quick Sort implementation
class Quick : public ISorter {
public:
  /// @brief Constructor
  /// @param range The range to be sorted
  /// @param file_stream Output file stream for logging
  Quick(Range range, std::ofstream &file_stream);

  /// @brief Output final result to console
  void Output() const override;

  /// @brief Output final result to file
  /// @param file Output file stream
  void FileOutput(std::ofstream &file) const override;

  /// @brief Perform Quick Sort
  /// @return Number of swaps performed
  unsigned int Sort(bool visualize) override;

private:
  /// @brief Output intermediate steps to console
  void out_steps() const override;

  /// @brief Output intermediate steps to file
  /// @param file Output file stream
  void file_steps(std::ofstream &file) const override;

  /// @brief Partition the array
  /// @param low Starting index
  /// @param high Ending index
  /// @param swaps Reference to swap counter
  /// @return Partition index
  int partition(int low, int high, unsigned int &swaps);

  /// @brief Recursive Quick Sort implementation
  /// @param low Starting index
  /// @param high Ending index
  /// @param swaps Reference to swap counter
  void quickSort(int low, int high, unsigned int &swaps, bool visualize);

  Range range;                ///< Data range to sort
  unsigned int swaps_counter; ///< Count of swaps performed
  unsigned int max_depth;     ///< Maximum recursion depth reached
  std::ofstream &file_stream; ///< Reference to output file stream
};

} // namespace sort

#endif // QUICK_H

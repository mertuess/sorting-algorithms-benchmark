/// @file merge.h
/// @brief Merge Sort algorithm implementation

#ifndef MERGE_H
#define MERGE_H

#include "i_sorter.h"
#include "random.h"

namespace sort {

/// @brief Merge Sort implementation
class Merge : public ISorter {
public:
  /// @brief Constructor
  /// @param range The range to be sorted
  /// @param file_stream Output file stream for logging
  Merge(Range range, std::ofstream &file_stream);

  /// @brief Output final result to console
  void Output() const override;

  /// @brief Output final result to file
  /// @param file Output file stream
  void FileOutput(std::ofstream &file) const override;

  /// @brief Perform Merge Sort
  /// @return Number of swaps performed
  unsigned int Sort(bool visualize) override;

private:
  /// @brief Output intermediate steps to console
  void out_steps() const override;

  /// @brief Output intermediate steps to file
  /// @param file Output file stream
  void file_steps(std::ofstream &file) const override;

  /// @brief Recursive Merge Sort implementation
  /// @param left Left index of sub-array
  /// @param right Right index of sub-array
  /// @param swaps Reference to swap counter
  void mergeSort(int left, int right, unsigned int &swaps, bool visualize);

  /// @brief Merge two sorted sub-arrays
  /// @param left Left index
  /// @param mid Middle index
  /// @param right Right index
  /// @param swaps Reference to swap counter
  void merge(int left, int mid, int right, unsigned int &swaps);

  Range range;                ///< Data range to sort
  unsigned int swaps_counter; ///< Count of swaps performed
  unsigned int max_depth;     ///< Maximum recursion depth reached
  std::ofstream &file_stream; ///< Reference to output file stream
};

} // namespace sort

#endif // MERGE_H

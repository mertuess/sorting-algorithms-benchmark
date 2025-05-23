/// @file heap.h
/// @brief Heap Sort algorithm implementation

#ifndef HEAP_H
#define HEAP_H

#include "i_sorter.h"
#include "random.h"

namespace sort {

/// @brief Heap Sort implementation
class Heap : public ISorter {
public:
  /// @brief Constructor
  /// @param range The range to be sorted
  /// @param file_stream Output file stream for logging
  Heap(Range range, std::ofstream &file_stream);

  /// @brief Output final result to console
  void Output() const override;

  /// @brief Output final result to file
  /// @param file Output file stream
  void FileOutput(std::ofstream &file) const override;

  /// @brief Perform Heap Sort
  /// @return Number of swaps performed
  unsigned int Sort(bool visualize) override;

private:
  /// @brief Output intermediate steps to console
  void out_steps() const override;

  /// @brief Output intermediate steps to file
  /// @param file Output file stream
  void file_steps(std::ofstream &file) const override;

  /// @brief Heapify subtree rooted at given index
  /// @param size Size of heap
  /// @param root Index of root node
  void heapify(int size, int root);

  Range range;                ///< Data range to sort
  unsigned int swaps_counter; ///< Count of swaps performed
  unsigned int max_depth;     ///< Maximum recursion depth reached
  std::ofstream &file_stream; ///< Reference to output file stream
};

} // namespace sort

#endif // HEAP_H

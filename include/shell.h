/// @file shell.h
/// @brief Shell Sort algorithm implementation

#ifndef SHELL_H
#define SHELL_H

#include "i_sorter.h"
#include "random.h"

namespace sort {

/// @brief Shell Sort implementation with different gap sequence formulas
class Shell : public ISorter {
public:
  /// @brief Enum for different gap sequence formulas
  enum class FORMULA {
    _3Hi_plus, ///< 3*H(i)+1 formula (Knuth sequence)
    _2Hi_plus, ///< 2*H(i)+1 formula
    _2Hi       ///< 2*H(i) formula
  };

  /// @brief Constructor
  /// @param range The range to be sorted
  /// @param file_stream Output file stream for logging
  Shell(Range range, std::ofstream &file_stream);

  /// @brief Output final result to console
  void Output() const override;

  /// @brief Output final result to file
  /// @param file Output file stream
  void FileOutput(std::ofstream &file) const override;

  /// @brief Perform Shell Sort
  /// @return Number of swaps performed
  unsigned int Sort(bool visualize) override;

  /// @brief Set gap sequence formula
  /// @param formula Formula to use for gap sequence
  void SetFormula(FORMULA formula);

private:
  /// @brief Output intermediate steps to console
  void out_steps() const override;

  /// @brief Output intermediate steps to file
  /// @param file Output file stream
  void file_steps(std::ofstream &file) const override;

  /// @brief Generate gap sequence
  /// @param count Size of the array
  /// @param formula Formula to use
  /// @return Array of gap sizes
  int *get_steps(size_t count, FORMULA formula);

  FORMULA formula = FORMULA::_3Hi_plus; ///< Current gap sequence formula
  int *steps;                           ///< Array of gap sizes
  size_t steps_size;                    ///< Size of gap sequence array
  Range range;                          ///< Data range to sort
  unsigned int swaps_counter;           ///< Count of swaps performed
  std::ofstream &file_stream;           ///< Reference to output file stream
};

} // namespace sort

#endif // SHELL_H

/// @file shell.cpp
#include "shell.h"

namespace sort {
Shell::Shell(Range range, std::ofstream &file_stream)
    : range(range), file_stream(file_stream) {}

void Shell::Output() const {
  std::cout << "\nShell final result:\nRange: " << range
            << "\nSwaps count: " << swaps_counter << "\n";
}

void Shell::FileOutput(std::ofstream &file) const {
  file << "\nShell final result:\nRange: " << range
       << "\nSwaps count: " << swaps_counter << "\n";
}

unsigned int Shell::Sort(bool visualize) {
  // Generate gap sequence based on selected formula
  steps = get_steps(range.size, formula);

  swaps_counter = 0;
  // Iterate through each gap size
  for (size_t i = 0; i < steps_size; ++i) {
    int step = steps[i];

    // Perform insertion sort for current gap size
    for (int j = step; j < range.size; j++) {
      int temp = range.data[j];
      int k = j;

      // Shift elements until correct position is found
      while (k >= step && range.data[k - step] > temp) {
        range.data[k] = range.data[k - step];
        k -= step;
        swaps_counter++;
      }
      range.data[k] = temp;
    }

    // Output intermediate sorting steps
    if (visualize) {
      out_steps();
      file_steps(file_stream);
    }
  }
  return swaps_counter;
}

void Shell::SetFormula(Shell::FORMULA formula) { (*this).formula = formula; }

void Shell::out_steps() const { std::cout << range; }

void Shell::file_steps(std::ofstream &file_stream) const {
  file_stream << range;
}

int *Shell::get_steps(size_t count, Shell::FORMULA formula) {
  // First pass: calculate required number of steps
  size_t steps_count = 0;
  int step = 1;
  while (step < static_cast<int>(count)) {
    steps_count++;
    switch (formula) {
    case Shell::FORMULA::_3Hi_plus:
      step = 3 * step + 1; // Knuth's sequence
      break;
    case Shell::FORMULA::_2Hi_plus:
      step = 2 * step + 1; // Hibbard's sequence
      break;
    case Shell::FORMULA::_2Hi:
      step = 2 * step; // Pratt's sequence
      break;
    }
  }

  // Allocate memory for steps array
  steps_size = steps_count;
  int *steps = static_cast<int *>(malloc(steps_count * sizeof(int)));

  // Second pass: generate steps sequence
  step = 1;
  for (size_t i = 0; i < steps_count; ++i) {
    steps[i] = step;
    switch (formula) {
    case Shell::FORMULA::_3Hi_plus:
      step = 3 * step + 1;
      break;
    case Shell::FORMULA::_2Hi_plus:
      step = 2 * step + 1;
      break;
    case Shell::FORMULA::_2Hi:
      step = 2 * step;
      break;
    }
  }

  // Reverse the sequence for descending order
  std::reverse(steps, steps + steps_count);
  return steps;
}

} // namespace sort

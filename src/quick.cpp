/// @file quick.cpp
#include "quick.h"

namespace sort {
Quick::Quick(Range range, std::ofstream &file_stream)
    : range(range), file_stream(file_stream), swaps_counter(0), max_depth(0) {}

void Quick::Output() const {
  std::cout << "\nQuick final result:\nRange: " << range
            << "\nSwaps count: " << swaps_counter << "\n"
            << "\nMax recursion depth: " << max_depth << "\n";
}

void Quick::FileOutput(std::ofstream &file) const {
  file << "\nQuick final result:\nRange: " << range
       << "\nSwaps count: " << swaps_counter << "\n";
}

int Quick::partition(int low, int high, unsigned int &swaps) {
  // Select last element as pivot
  int pivot = range.data[high];
  // Index of smaller element
  int i = low - 1;

  for (int j = low; j <= high - 1; j++) {
    // If current element is smaller than pivot
    if (range.data[j] < pivot) {
      i++; // Increment index of smaller element
      std::swap(range.data[i], range.data[j]);
      swaps++;
    }
  }
  std::swap(range.data[i + 1], range.data[high]);
  swaps++;
  return i + 1;
}

void Quick::quickSort(int low, int high, unsigned int &swaps, bool visualize) {
  max_depth++; // Every repeat add a depth
  if (low < high) {
    // Partitioning index
    int pi = partition(low, high, swaps);

    // Output intermediate state
    if (visualize) {
      out_steps();
      file_steps(file_stream);
    }

    // Sort elements before and after partition
    quickSort(low, pi - 1, swaps, visualize);
    quickSort(pi + 1, high, swaps, visualize);
  }
}

unsigned int Quick::Sort(bool visualize) {
  quickSort(0, range.size - 1, swaps_counter, visualize);
  return swaps_counter;
}

void Quick::out_steps() const { std::cout << range; }

void Quick::file_steps(std::ofstream &file) const { file << range; }
} // namespace sort

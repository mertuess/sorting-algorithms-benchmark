/// @file merge.cpp
#include "merge.h"
#include <vector>

namespace sort {

Merge::Merge(Range range, std::ofstream &file_stream)
    : range(range), file_stream(file_stream), swaps_counter(0), max_depth(0) {}

void Merge::Output() const {
  std::cout << "\nMerge final result:\nRange: " << range
            << "\nSwaps count: " << swaps_counter << "\n"
            << "\nMax recursion depth: " << max_depth << "\n";
}

void Merge::FileOutput(std::ofstream &file) const {
  file << "\nMerge final result:\nRange: " << range
       << "\nSwaps count: " << swaps_counter << "\n";
}

void Merge::merge(int left, int mid, int right, unsigned int &swaps) {
  // Calculate sizes of two subarrays
  int n1 = mid - left + 1;
  int n2 = right - mid;

  // Create temporary arrays
  std::vector<int> L(n1), R(n2);

  // Copy data to temp arrays
  for (int i = 0; i < n1; i++)
    L[i] = range.data[left + i];
  for (int j = 0; j < n2; j++)
    R[j] = range.data[mid + 1 + j];

  // Merge the temp arrays back
  int i = 0, j = 0, k = left;
  while (i < n1 && j < n2) {
    if (L[i] <= R[j]) {
      range.data[k] = L[i];
      i++;
    } else {
      range.data[k] = R[j];
      j++;
      // Count inversions (swaps needed to make array sorted)
      swaps += (n1 - i);
    }
    k++;
  }

  // Copy remaining elements of L[] if any
  while (i < n1) {
    range.data[k] = L[i];
    i++;
    k++;
  }

  // Copy remaining elements of R[] if any
  while (j < n2) {
    range.data[k] = R[j];
    j++;
    k++;
  }
}

void Merge::mergeSort(int left, int right, unsigned int &swaps,
                      bool visualize) {
  max_depth++; // Every repeat add a depth
  if (left < right) {
    // Find middle point
    int mid = left + (right - left) / 2;

    // Sort first and second halves
    mergeSort(left, mid, swaps, visualize);
    mergeSort(mid + 1, right, swaps, visualize);

    // Merge the sorted halves
    merge(left, mid, right, swaps);
    if (visualize) {
      out_steps();
      file_steps(file_stream);
    }
  }
}

unsigned int Merge::Sort(bool visualize) {
  mergeSort(0, range.size - 1, swaps_counter, visualize);
  return swaps_counter;
}

void Merge::out_steps() const { std::cout << range; }

void Merge::file_steps(std::ofstream &file) const { file << range; }

} // namespace sort

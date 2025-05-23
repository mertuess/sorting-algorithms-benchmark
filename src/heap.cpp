/// @file heap.cpp
#include "heap.h"

namespace sort {

Heap::Heap(Range range, std::ofstream &file_stream)
    : range(range), file_stream(file_stream), swaps_counter(0), max_depth(0) {}

void Heap::Output() const {
  std::cout << "\nHeap final result:\nRange: " << range
            << "\nSwaps count: " << swaps_counter << "\n"
            << "\nMax recursion depth: " << max_depth << "\n";
}

void Heap::FileOutput(std::ofstream &file) const {
  file << "\nHeap final result:\nRange: " << range
       << "\nSwaps count: " << swaps_counter << "\n";
}

void Heap::heapify(int size, int root) {
  max_depth++;              // Every repeat add a depth
  int largest = root;       // Initialize largest as root
  int left = 2 * root + 1;  // Left child
  int right = 2 * root + 2; // Right child

  // If left child is larger than root
  if (left < size && range.data[left] > range.data[largest]) {
    largest = left;
  }

  // If right child is larger than current largest
  if (right < size && range.data[right] > range.data[largest]) {
    largest = right;
  }

  // If largest is not root
  if (largest != root) {
    std::swap(range.data[root], range.data[largest]);
    swaps_counter++;
    // Recursively heapify the affected subtree
    heapify(size, largest);
  }
}

unsigned int Heap::Sort(bool visualize) {
  // Build max heap (rearrange array)
  for (int i = range.size / 2 - 1; i >= 0; i--) {
    heapify(range.size, i);
    if (visualize) {
      out_steps();
      file_steps(file_stream);
    }
  }

  // Extract elements from heap one by one
  for (int i = range.size - 1; i > 0; i--) {
    // Move current root to end
    std::swap(range.data[0], range.data[i]);
    swaps_counter++;
    // Call heapify on the reduced heap
    heapify(i, 0);
    if (visualize) {
      out_steps();
      file_steps(file_stream);
    }
  }

  return swaps_counter;
}

void Heap::out_steps() const { std::cout << range; }

void Heap::file_steps(std::ofstream &file) const { file << range; }

} // namespace sort

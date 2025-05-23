/// @file main.cpp
/// @brief Main program for sorting algorithms comparison

#include "heap.h"
#include "merge.h"
#include "programm_options.h"
#include "quick.h"
#include "random.h"
#include "shell.h"

#include <sstream>
#include <vector>

int main(int argc, char *argv[]) {
  // Parse command line arguments
  auto opt = sort::ProgrammOptionsMgr::parseArguments(argc, argv);
  if (sort::ProgrammOptionsMgr::opt_err > 0)
    return 1; // Exit if there were parsing errors

  sort::Range range; // Container for the data to be sorted

  // Handle input source (file or random generation)
  if (opt.input_file) {
    // Read from input file
    std::ifstream in_file(*opt.input_file);
    if (!in_file) {
      std::cerr << "Cannot open input file: " << *opt.input_file << std::endl;
      return 1;
    }

    std::vector<int> numbers; // Temporary storage for file data
    std::string line;

    // Process each line in the input file
    while (std::getline(in_file, line)) {
      // Clean the line by removing non-digit characters (except spaces)
      line.erase(remove_if(line.begin(), line.end(),
                           [](char c) { return !isdigit(c) && c != ' '; }),
                 line.end());

      // Parse numbers from the cleaned line
      std::stringstream ss(line);
      int num;
      while (ss >> num) {
        numbers.push_back(num);
      }
    }
    in_file.close();

    // Allocate memory and copy data from vector to range
    range.size = numbers.size();
    range.data = static_cast<int *>(malloc(range.size * sizeof(int)));
    std::copy(numbers.begin(), numbers.end(), range.data);
  } else {
    // Generate random data if no input file specified
    sort::Random random;
    range = random.Range(opt.min_value, opt.max_value, opt.array_size);
  }

  // Set up output destination (file or default)
  std::ofstream out_file;
  if (opt.output_file) {
    out_file.open(*opt.output_file);
  } else {
    out_file.open("out.txt"); // Default output file
  }

  // Print initial array state
  out_file << "Start range: " << range;
  std::cout << "Start range: " << range;

  // Execute selected sorting algorithm
  if (opt.algorithm == "shell") {
    sort::Shell shell(range, out_file); // Init sorter

    // Set Shell sort formula based on options
    sort::Shell::FORMULA formula;
    if (opt.shell_formula == "3Hi+1") {
      formula = sort::Shell::FORMULA::_3Hi_plus;
    } else if (opt.shell_formula == "2Hi+1") {
      formula = sort::Shell::FORMULA::_2Hi_plus;
    } else {
      formula = sort::Shell::FORMULA::_2Hi;
    }

    shell.SetFormula(formula);  // Set the formula to shell object
    shell.Sort(opt.visualize);  // Perform sorting
    shell.Output();             // Print results to console
    shell.FileOutput(out_file); // Write results to file
  } else if (opt.algorithm == "heap") {
    sort::Heap heap(range, out_file);
    heap.Sort(opt.visualize);
    heap.Output();
    heap.FileOutput(out_file);
  } else if (opt.algorithm == "quick") {
    sort::Quick quick(range, out_file);
    quick.Sort(opt.visualize);
    quick.Output();
    quick.FileOutput(out_file);
  } else if (opt.algorithm == "merge") {
    sort::Merge merge(range, out_file);
    merge.Sort(opt.visualize);
    merge.Output();
    merge.FileOutput(out_file);
  }

  // Clean up dynamically allocated memory if we read from file
  if (opt.input_file) {
    free(range.data);
  }

  // Close stream
  out_file.close();

  return 0;
}

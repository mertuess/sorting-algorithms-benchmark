/// @file programm_options.h
/// @brief Program options and command line parsing

#ifndef PROGRAMM_OPTIONS_H
#define PROGRAMM_OPTIONS_H

#include <optional>
#include <string>

namespace sort {

/// @brief Structure holding program configuration options
struct ProgramOptions {
  std::string algorithm = "shell";        ///< Sorting algorithm to use
  std::string shell_formula = "3Hi+1";    ///< Shell sort gap sequence formula
  std::optional<std::string> input_file;  ///< Optional input file path
  std::optional<std::string> output_file; ///< Optional output file path
  size_t array_size = 15;                 ///< Size of array to generate
  int min_value = 0;                      ///< Minimum value in random array
  int max_value = 100;                    ///< Maximum value in random array
  bool visualize = true;                  ///< Visualize each step of algorithm
};

/// @brief Manager for program options and command line parsing
class ProgrammOptionsMgr {
private:
  ProgrammOptionsMgr();

public:
  static unsigned int opt_err; ///< Count of option parsing errors

  /// @brief Parse command line arguments
  /// @param argc Argument count
  /// @param argv Argument values
  /// @return ProgramOptions structure with parsed values
  static ProgramOptions parseArguments(int argc, char *argv[]);

  /// @brief Print help message to console
  static void print_help();
};

} // namespace sort

#endif // !PROGRAMM_OPTIONS_H

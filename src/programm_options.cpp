#include "programm_options.h"
#include <algorithm>
#include <iostream>

namespace sort {
unsigned int ProgrammOptionsMgr::opt_err = 0;
ProgramOptions ProgrammOptionsMgr::parseArguments(int argc, char **argv) {
  ProgramOptions options;

  for (int i = 1; i < argc; ++i) {
    std::string arg = argv[i];

    std::transform(arg.begin(), arg.end(), arg.begin(),
                   [](unsigned char c) { return std::tolower(c); });

    if (arg == "--algorithm" || arg == "-a") {
      if (i + 1 < argc) {
        std::string algo = argv[++i];
        std::transform(algo.begin(), algo.end(), algo.begin(),
                       [](unsigned char c) { return std::tolower(c); });

        if (algo == "shell" || algo == "heap" || algo == "quick" ||
            algo == "merge") {
          options.algorithm = algo;
        } else {
          std::cerr << "Unknown algorithm: " << algo << std::endl;
          ProgrammOptionsMgr::opt_err++;
        }
      }
    } else if (arg == "--shell-formula" || arg == "-f") {
      if (i + 1 < argc) {
        std::string formula = argv[++i];
        if (formula == "3Hi+1" || formula == "2Hi+1" || formula == "2Hi") {
          options.shell_formula = formula;
        } else {
          std::cerr << "Unknown Shell formula: " << formula << std::endl;
          ProgrammOptionsMgr::opt_err++;
        }
      }
    } else if (arg == "--input" || arg == "-i") {
      if (i + 1 < argc) {
        options.input_file = argv[++i];
      }
    } else if (arg == "--output" || arg == "-o") {
      if (i + 1 < argc) {
        options.output_file = argv[++i];
      }
    } else if (arg == "--size" || arg == "-s") {
      if (i + 1 < argc) {
        try {
          options.array_size = std::stoul(argv[++i]);
        } catch (...) {
          std::cerr << "Invalid size value" << std::endl;
          ProgrammOptionsMgr::opt_err++;
        }
      }
    } else if (arg == "--min" || arg == "-min") {
      if (i + 1 < argc) {
        try {
          options.min_value = std::stoi(argv[++i]);
        } catch (...) {
          std::cerr << "Invalid min value" << std::endl;
          ProgrammOptionsMgr::opt_err++;
        }
      }
    } else if (arg == "--max" || arg == "-max") {
      if (i + 1 < argc) {
        try {
          options.max_value = std::stoi(argv[++i]);
        } catch (...) {
          std::cerr << "Invalid max value" << std::endl;
          ProgrammOptionsMgr::opt_err++;
        }
      }
    } else if (arg == "--off-visualize") {
      options.visualize = false;
    } else if (arg == "--help" || arg == "-h") {
      ProgrammOptionsMgr::print_help();
      exit(0);
    }
  }

  return options;
}

void ProgrammOptionsMgr::print_help() {
  std::cout
      << "Usage: sort [options]\n"
      << "Options:\n"
      << "  -a, --algorithm <algo>    Sorting algorithm (shell, heap, quick, "
         "merge)\n"
      << "  -f, --shell-formula <f>   Shell sort formula (3Hi+1, 2Hi+1, 2Hi)\n"
      << "  -i, --input <file>        Input file (optional)\n"
      << "  -o, --output <file>       Output file (optional)\n"
      << "  -s, --size <n>            Array size (default: 15)\n"
      << "  -min, --min <val>         Minimum value (default: 0)\n"
      << "  -min, --max <val>         Maximum value (default: 100)\n"
      << "  --off-visualize           Turn off visualization of each step of "
         "the algorithm\n"
      << "  -h, --help                Show this help message\n";
}
} // namespace sort

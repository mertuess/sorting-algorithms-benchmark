# Sorting Algorithms Benchmark

## Project Overview

This C++ project implements and compares four classic sorting algorithms with customizable parameters and visualization options. The program allows users to test algorithms with different input types and analyze their performance characteristics.

## Features

- **Implemented Algorithms**:
  - Shell Sort (with selectable gap sequences)
  - Heap Sort
  - Quick Sort
  - Merge Sort

- **Metrics Tracking**:
  - Number of swaps/comparisons
  - Maximum recursion depth
  - Intermediate step visualization

- **Input Options**:
  - Random number generation with customizable range
  - File input for custom datasets
  - Adjustable array size

- **Output Options**:
  - Console output
  - File logging
  - Step-by-step visualization

## Build Instructions

### Prerequisites
- C++17 compatible compiler (GCC, Clang, MSVC)
- CMake (version 3.10 or higher)

### Building
```bash
cmake --presets=default
cmake --build build
```

## Usage

```bash
./sort [options]
```

### Available Options

| Option               | Description                              | Default Value     |
|----------------------|------------------------------------------|-------------------|
| `-a, --algorithm`    | Sorting algorithm (shell/heap/quick/merge) | shell            |
| `-f, --shell-formula`| Shell sort formula (3Hi+1/2Hi+1/2Hi)     | 3Hi+1            |
| `-i, --input`        | Input file path                          | None (random gen) |
| `-o, --output`       | Output file path                         | out.txt           |
| `-s, --size`         | Array size for random generation         | 15                |
| `-min, --min`        | Minimum random value                     | 0                 |
| `-max, --max`        | Maximum random value                     | 100               |
| `--off-visualize`    | Turn off step visualization              | false             |
| `-h, --help`         | Show help message                        | N/A               |

## Examples

1. **Basic Usage**
```bash
./sort -a quick -s 20
```

2. **File Input with Visualization**
```bash
./sort -a merge -i input.txt -v -o results.log
```

3. **Custom Shell Sort**
```bash
./sort -a shell -f 2Hi+1 -s 50 -min 10 -max 1000
```

## Output Format

The program generates detailed output including:
- Initial unsorted array
- Intermediate steps (if visualization enabled)
- Final sorted array
- Performance metrics:
  - Number of swaps
  - Maximum recursion depth
  - Execution time

Example output:
```
Start range: [5, 3, 8, 1, 2]

Merge final result:
Range: [1, 2, 3, 5, 8]
Swaps count: 6
Max recursion depth: 3
```

## File Format

When using file input, the program accepts:
- One number per line
- Multiple numbers per line (space separated)
- Ignores non-numeric characters

Example input file:
```
5 3 8
1 2
```

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.

## Contributing

Contributions are welcome! Please open an issue or submit a pull request for any improvements or bug fixes.

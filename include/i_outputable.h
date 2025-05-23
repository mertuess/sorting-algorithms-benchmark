/// @file i_outputable.h
/// @brief Interface for output capabilities

#ifndef I_OUTPUTABLE_H
#define I_OUTPUTABLE_H

#include <fstream>

/// @brief Interface for objects that can output their state
class IOutputable {
public:
  /// @brief Output to console
  virtual void Output() const = 0;

  /// @brief Output to file
  /// @param file Output file stream
  virtual void FileOutput(std::ofstream &file) const = 0;

  /// @brief Virtual destructor
  virtual ~IOutputable() = default;

private:
  /// @brief Output intermediate steps to console
  virtual void out_steps() const = 0;

  /// @brief Output intermediate steps to file
  /// @param file Output file stream
  virtual void file_steps(std::ofstream &file) const = 0;
};

#endif // I_OUTPUTABLE_H

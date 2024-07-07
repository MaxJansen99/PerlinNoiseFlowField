#ifndef RANDOM_HPP
#define RANDOM_HPP

/**
 * @class Random
 * @brief Provides static methods for generating random numbers.
 *
 * This class encapsulates functionality for generating random numbers within specified ranges.
 * It offers methods for both integer and floating-point numbers. The random number generation
 * is based on the standard C++ <random> library to ensure good quality randomness and reproducibility.
 */
class Random {
public:
  /**
   * @brief Generates a random integer within a specified range.
   * @param min The lower bound of the range (inclusive).
   * @param max The upper bound of the range (inclusive).
   * @return A random integer between min and max, inclusive.
   */
  static int rInt(int min, int max);

  /**
   * @brief Generates a random floating-point number within a specified range.
   * @param min The lower bound of the range (inclusive).
   * @param max The upper bound of the range (inclusive).
   * @return A random floating-point number between min and max, inclusive.
   */
  static float rFloat(float min, float max);
};

#endif
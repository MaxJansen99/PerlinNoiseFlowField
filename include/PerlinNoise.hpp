#ifndef PERLINNOISE_HPP
#define PERLINNOISE_HPP

/**
 * @class PerlinNoise
 * @brief Implements Perlin Noise generation for procedural texture generation, terrain generation, etc.
 *
 * This class provides an implementation of the Perlin noise algorithm, which is a type of gradient noise
 * useful in creating naturally appearing textures, landscapes, and other randomized, yet smooth, graphical elements.
 */
class PerlinNoise {
private:
  int* pPtr; ///< Pointer to the permutation array used for noise generation.

  /**
   * @brief Applies the fade function to t, enhancing the smoothness of the noise.
   * @param t The input value to the fade function.
   * @return The smoothed value.
   */
  static double fade(double t);

  /**
   * @brief Performs linear interpolation between values a and b using t.
   * @param t The interpolation coefficient.
   * @param a The start value.
   * @param b The end value.
   * @return The interpolated value.
   */
  static double lerp(double t, double a, double b);

  /**
   * @brief Calculates the gradient at a specific point.
   * @param hash Hash value influencing the gradient direction.
   * @param x X-coordinate of the point.
   * @param y Y-coordinate of the point.
   * @param z Z-coordinate of the point.
   * @return The gradient at the given point.
   */
  static double grad(int hash, double x, double y, double z);

public:
  /**
   * @brief Constructor for PerlinNoise, initializes permutation array.
   */
  PerlinNoise();

  /**
   * @brief Destructor for PerlinNoise, cleans up resources.
   */
  ~PerlinNoise();

  /**
   * @brief Generates Perlin noise value for a point in 3D space.
   * @param x X-coordinate of the point.
   * @param y Y-coordinate of the point.
   * @param z Z-coordinate of the point.
   * @return The Perlin noise value.
   */
  double noise(double x, double y, double z);
};

#endif
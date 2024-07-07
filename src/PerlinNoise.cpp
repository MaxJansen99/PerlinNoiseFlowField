#include "../include/PerlinNoise.hpp"
#include "../include/Random.hpp"
#include <cmath>

double PerlinNoise::fade(double t) {
  return t * t * t * (t * (t * 6 - 15) + 10);
}

double PerlinNoise::lerp(double t, double a, double b) {
  return a + t * (b - a);
}

double PerlinNoise::grad(int hash, double x, double y, double z) {
  int h = hash & 15;
  double u = h < 8 ? x : y;
  double v = h < 4 ? y : h == 12 || h == 14 ? x : z;
  return ((h & 1) == 0 ? u : -u) + ((h & 2) == 0 ? v : -v);
}

PerlinNoise::PerlinNoise() {
  this->pPtr = new int[512];

  for (int i = 0; i < 256; ++i) {
    int randomValue = Random::rInt(0, 255);
    this->pPtr[i] = randomValue;
    this->pPtr[256 + i] = randomValue;
  }
}

PerlinNoise::~PerlinNoise() {
  delete[] this->pPtr;
}

double PerlinNoise::noise(double x, double y, double z) {
  int X = (int) floor(x) & 255;
  int Y = (int) floor(y) & 255;
  int Z = (int) floor(z) & 255;

  x -= floor(x);
  y -= floor(y);
  z -= floor(z);

  double u = fade(x);
  double v = fade(y);
  double w = fade(z);

  int A = this->pPtr[X] + Y;
  int AA = this->pPtr[A] + Z;
  int AB = this->pPtr[A + 1] + Z;
  int B = this->pPtr[X + 1] + Y;
  int BA = this->pPtr[B] + Z;
  int BB = this->pPtr[B + 1] + Z;

  return lerp(
    w,
    lerp(
      v,
      lerp(
        u,
        grad(this->pPtr[AA], x, y, z),
        grad (this->pPtr[BA], x - 1, y, z)
      ),
      lerp(
        u,
        grad(this->pPtr[AB], x, y - 1, z),
        grad(this->pPtr[BB], x - 1, y - 1, z )
      )
    ),
    lerp(
      v,
      lerp(
        u,
        grad(this->pPtr[AA + 1], x, y, z - 1) ,
        grad(this->pPtr[BA + 1], x - 1, y, z - 1)
      ),
      lerp(
        u,
        grad(this->pPtr[AB + 1], x , y -1 , z - 1) ,
        grad(this->pPtr[BB + 1], x - 1 , y -1 , z - 1)
      )
    )
  );
}
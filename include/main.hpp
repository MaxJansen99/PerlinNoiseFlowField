#ifndef MAIN_HPP
#define MAIN_HPP

#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Color.hpp>
#include "Random.hpp"

// Window
const std::string title {"Perlin Noise Flow Field"};
const int width {1920};
const int height {1080};


// Noise
const float noiseStrength {0.002}; // 0.002
const float noiseSpeed {1.5}; // 1.5
float noiseTime {0.001}; // 0.001
float noiseChange {0.0}; // 0.0


const float dotCount {10000}; // 10000
const float dotSize {1.5}; // 1.5
const sf::Color dotColor {sf::Color(42, 82, 190, 100)}; // 42, 82, 190, 100

// Particle
struct Particle {
  sf::Vector2f position;
  sf::Vector2f velocity;

  Particle(float x, float y) {
    position = sf::Vector2f(x, y);
    velocity = sf::Vector2f(0.0f, 0.0f);
  }

  void moveParticle() {
    position += velocity;
  }

  void randomCollision() {
    if(position.x < 0 || position.x > width || position.y < 0 || position.y > height) {
      position.x = Random::rFloat(0, width);
      position.y = Random::rFloat(0, height);
    }
  }

  void borderCollision() {
    if(position.x < 0)
      position.x = width;
    else if(position.x > width)
      position.x = 0;

    if (position.y < 0)
      position.y = height;
    else if (position.y > height)
      position.y = 0;
  }

  void drawDot(sf::RenderWindow& window) const {
    sf::CircleShape dot(dotSize);
    dot.setFillColor(dotColor);
    dot.setPosition(position.x, position.y);
    window.draw(dot);
  }
};

#endif
#include "../include/main.hpp"
#include "../include/PerlinNoise.hpp"
#include <SFML/Graphics.hpp>
#include <vector>
#include <cmath>

int main() {
  // Initalization: Perlin Noise, Window, Particles
  auto* perlin = new PerlinNoise();
  auto* particles = new std::vector<Particle>();
  auto* window = new sf::RenderWindow(sf::VideoMode::getDesktopMode(), title, sf::Style::Fullscreen);

  // Create Particles
  for(int i {0}; i < dotCount; i++) {
    particles->emplace_back(Random::rFloat(0.0, width), Random::rFloat(0.0, height));
  }

  while(window->isOpen()) {
    sf::Event event{};

    while (window->pollEvent(event)) {
      if (event.type == sf::Event::Closed || event.type == sf::Event::KeyPressed) {
        window->close();
      }
    }

    // Background
    sf::RectangleShape rectangle(sf::Vector2f(width, height));
    rectangle.setFillColor(sf::Color(0, 0, 0, 20));
    window->draw(rectangle);

    for (auto& particle : *particles) {
      // Movement of the particles based on Perlin noise
      auto noise = perlin->noise(particle.position.x * noiseStrength, particle.position.y * noiseStrength, noiseChange);
      auto alpha = 2 * M_PI * noise;
      particle.velocity = sf::Vector2f(float(noiseSpeed * cos(alpha)), float(noiseSpeed * sin(alpha)));

      // Calling struct methods
      particle.moveParticle();
      particle.randomCollision();
      particle.drawDot(*window);
    }

    noiseChange += noiseTime;
    window->display();
  }

  // Destruction: Perlin Noise, Window, Particles
  delete perlin;
  delete window;
  delete particles;

  return 0;
}

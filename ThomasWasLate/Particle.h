#ifndef THOMAS_WAS_LATE_PARTICLE_H
#define THOMAS_WAS_LATE_PARTICLE_H

#include <SFML\Graphics.hpp>

class Particle
{
public:
   Particle(sf::Vector2f direction);

   void update(float dtAsSeconds);

   void setPosition(sf::Vector2f position);

   sf::Vector2f getPosition();

private:
   sf::Vector2f m_position;
   sf::Vector2f m_velocity;
};

#endif // !THOMAS_WAS_LATE_PARTICLE_H
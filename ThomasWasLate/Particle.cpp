#include "Particle.h"

Particle::Particle(sf::Vector2f direction)
{
   m_velocity.x = direction.x;
   m_velocity.y = direction.y;
}

void Particle::update(float dtAsSeconds)
{
   m_position += m_velocity * dtAsSeconds;
}

void Particle::setPosition(sf::Vector2f position) { m_position = position; }

sf::Vector2f Particle::getPosition() { return m_position; }
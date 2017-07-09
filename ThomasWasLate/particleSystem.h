#ifndef THOMAS_WAS_LATE_PARTICLE_SYSTEM_H
#define THOMAS_WAS_LATE_PARTICLE_SYSTEM_H

#include <SFML\Graphics.hpp>
#include "Particle.h"

class ParticleSystem : public sf::Drawable
{
public:
   virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

   void init(int count);

   void emitParticles(sf::Vector2f position);

   void update(float elapsed);

   bool isRunning();

private:
   std::vector<Particle> m_particles;
   sf::VertexArray m_vertecies;
   float m_duration;
   bool m_isRunning = false;
};

#endif // !THOMAS_WAS_LATE_PARTICLE_SYSTEM_H
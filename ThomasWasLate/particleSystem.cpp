#include "particleSystem.h"

void ParticleSystem::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
   target.draw(m_vertecies, states);
}

void ParticleSystem::init(int count)
{
   m_vertecies.setPrimitiveType(sf::Points);
   m_vertecies.resize(count);

   for (int i = 0; i < count; i++)
   {
      srand(time(0) + i);
      float angle = (rand() % 360) * 3.1415f / 180.f;
      float speed = (rand() % 600) + 600.f;

      sf::Vector2f direction;

      direction = sf::Vector2f(cos(angle) * speed, sin(angle) * speed);

      m_particles.push_back(Particle(direction));
   }
}

void ParticleSystem::emitParticles(sf::Vector2f position)
{
   m_isRunning = true;
   m_duration = 2;

   std::vector<Particle>::iterator it;
   int currentVertex = 0;

   for (it = m_particles.begin(); it != m_particles.end(); it++) {
      m_vertecies[currentVertex].color = sf::Color::Red;
      (*it).setPosition(position);

      currentVertex++;
   }
}

void ParticleSystem::update(float elapsed)
{
   m_duration -= elapsed;
   std::vector<Particle>::iterator it;
   int currentVertex = 0;

   for (it = m_particles.begin(); it != m_particles.end(); it++) {
      (*it).update(elapsed);

      m_vertecies[currentVertex].position = (*it).getPosition();

      currentVertex++;
   }

   if (m_duration < 0) {
      m_isRunning = false;
   }
}

bool ParticleSystem::isRunning() { return m_isRunning; }

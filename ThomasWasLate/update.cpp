#include "engine.h"
#include <sstream>

void Engine::update(float dtAsSeconds) {
   if (m_newLevelRequired) {
      m_thomas.spawn(sf::Vector2f(0, 0), GRAVITY);
      m_bob.spawn(sf::Vector2f(100, 0), GRAVITY);

      m_timeRemaining = 10;
      m_newLevelRequired = false;
   }

   if (m_playing) {
      m_thomas.update(dtAsSeconds);

      m_bob.update(dtAsSeconds);

      m_timeRemaining -= dtAsSeconds;

      if (m_timeRemaining <= 0) { m_newLevelRequired = true; }
   }

   if (m_splitScreen) {
      m_leftView.setCenter(m_thomas.getCenter());
      m_rightView.setCenter(m_bob.getCenter());
   }
   else {
      if (m_characterOne) { m_mainView.setCenter(m_thomas.getCenter()); }
      else { m_mainView.setCenter(m_bob.getCenter()); }
   }
}
#include "engine.h"
#include <sstream>

void Engine::update(float dtAsSeconds) {
   if (m_newLevelRequired) {
      loadLevel();
   }

   if (m_playing) {
      m_thomas.update(dtAsSeconds);

      m_bob.update(dtAsSeconds);

      if (detectCollision(m_thomas) && detectCollision(m_bob)) {
         m_newLevelRequired = true;
      }
      else {
         detectCollision(m_bob); // Thomas already there
      }

      // Jump on each head
      if (m_bob.getFeet().intersects(m_thomas.getHead())) { m_bob.stopFalling(m_thomas.getHead().top); }
      else if (m_thomas.getFeet().intersects(m_bob.getHead())) { m_thomas.stopFalling(m_bob.getHead().top); }

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
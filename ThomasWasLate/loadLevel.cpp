#include "engine.h"

void Engine::loadLevel() {
   m_playing = false;

   for (int i = 0; i < m_levelManager.getLevelSize().y; i++)
   {
      delete[] m_ArrayLevel[i];
   }
   delete[] m_ArrayLevel;

   m_ArrayLevel = m_levelManager.nextLevel(m_VALevel);

   populateEmitters(m_fireEmitters, m_ArrayLevel);

   m_timeRemaining = m_levelManager.getTimeLimit();

   m_thomas.spawn(m_levelManager.getStartPosition(), GRAVITY);
   m_bob.spawn(m_levelManager.getStartPosition(), GRAVITY);

   m_newLevelRequired = false;
}
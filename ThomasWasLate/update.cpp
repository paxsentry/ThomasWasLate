#include "engine.h"
#include <sstream>

void Engine::update(float dtAsSeconds) {
   if (m_playing) {
      m_timeRemaining -= dtAsSeconds;

      if (m_timeRemaining <= 0) { m_newLevelRequired = true; }
   }
}
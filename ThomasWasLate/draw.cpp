#include "engine.h"

void Engine::draw() {
   m_window.clear(sf::Color::White);

   if (!m_splitScreen) {
      m_window.setView(m_BG_mainView);
      m_window.draw(m_sprite_Background);
      m_window.setView(m_mainView);
   }
   else {
      m_window.setView(m_BG_leftView);
      m_window.draw(m_sprite_Background);
      m_window.setView(m_leftView);

      m_window.setView(m_BG_rightView);
      m_window.draw(m_sprite_Background);
      m_window.setView(m_rightView);
   }

   m_window.setView(m_hudView);

   m_window.display();
}
#include "engine.h"

void Engine::draw() {
   m_window.clear(sf::Color::White);

   if (!m_splitScreen) {
      m_window.setView(m_BG_mainView);
      m_window.draw(m_sprite_Background);
      m_window.setView(m_mainView);

      m_window.draw(m_VALevel, &m_textureTiles);

      m_window.draw(m_thomas.getSprite());
      m_window.draw(m_bob.getSprite());
   }
   else {
      m_window.setView(m_BG_leftView);
      m_window.draw(m_sprite_Background);
      m_window.setView(m_leftView);
      
      m_window.draw(m_VALevel, &m_textureTiles);

      m_window.draw(m_bob.getSprite()); // Reverse order to provide "priority" on this view
      m_window.draw(m_thomas.getSprite());

      m_window.setView(m_BG_rightView);
      m_window.draw(m_sprite_Background);
      m_window.setView(m_rightView);

      m_window.draw(m_VALevel, &m_textureTiles);

      m_window.draw(m_thomas.getSprite()); // Same reason
      m_window.draw(m_bob.getSprite());
   }

   m_window.setView(m_hudView);

   m_window.display();
}
#include "engine.h"

void Engine::draw() {
   m_window.clear(sf::Color::White);

   m_rippleShader.setUniform("uTime", m_gameTimeTotal.asSeconds());

   if (!m_splitScreen) {
      m_window.setView(m_BG_mainView);
      m_window.draw(m_sprite_Background, &m_rippleShader);
      m_window.setView(m_mainView);

      m_window.draw(m_VALevel, &m_textureTiles);

      m_window.draw(m_thomas.getSprite());
      m_window.draw(m_bob.getSprite());

      if (m_particleSystem.isRunning()) {
         m_window.draw(m_particleSystem);
      }
   }
   else {
      m_window.setView(m_BG_leftView);
      m_window.draw(m_sprite_Background, &m_rippleShader);
      m_window.setView(m_leftView);

      m_window.draw(m_VALevel, &m_textureTiles);

      m_window.draw(m_bob.getSprite()); // Reverse order to provide "priority" on this view
      m_window.draw(m_thomas.getSprite());

      if (m_particleSystem.isRunning()) {
         m_window.draw(m_particleSystem);
      }

      m_window.setView(m_BG_rightView);
      m_window.draw(m_sprite_Background, &m_rippleShader);
      m_window.setView(m_rightView);

      m_window.draw(m_VALevel, &m_textureTiles);

      m_window.draw(m_thomas.getSprite()); // Same reason
      m_window.draw(m_bob.getSprite());

      if (m_particleSystem.isRunning()) {
         m_window.draw(m_particleSystem);
      }
   }

   m_window.setView(m_hudView);
   m_window.draw(m_hud.getLevel());
   m_window.draw(m_hud.getTime());

   if (!m_playing) { m_window.draw(m_hud.getMessage()); }

   m_window.display();
}
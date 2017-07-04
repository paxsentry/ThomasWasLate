#include "engine.h"

void Engine::input() {
   sf::Event event;

   while (m_window.pollEvent(event))
   {
      if (event.type == sf::Event::KeyPressed) {
         if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) { m_window.close(); }

         if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return)) { m_playing = true; }

         if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) { m_characterOne = !m_characterOne; }

         if (sf::Keyboard::isKeyPressed(sf::Keyboard::E)) { m_splitScreen = !m_splitScreen; }
      }
   }
}
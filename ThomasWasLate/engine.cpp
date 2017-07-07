#include "engine.h"

Engine::Engine()
{
   sf::Vector2f resolution;
   resolution.x = 1920;
   resolution.y = 1080;

   m_window.create(sf::VideoMode(resolution.x, resolution.y), "Thomas was late", sf::Style::Resize);

   m_mainView.setSize(resolution);
   m_hudView.reset(sf::FloatRect(0, 0, resolution.x, resolution.y));

   m_leftView.setViewport(sf::FloatRect(0.001f, 0.001f, 0.498f, 0.998f));
   m_rightView.setViewport(sf::FloatRect(0.5f, 0.001f, 0.499f, 0.998f));

   m_BG_leftView.setViewport(sf::FloatRect(0.001f, 0.001f, 0.498f, 0.998f));
   m_BG_rightView.setViewport(sf::FloatRect(0.5f, 0.001f, 0.499f, 0.998f));

   m_texture_Background = TextureHolder::getTexture("graphics/background.png");
   m_sprite_Background.setTexture(m_texture_Background);

   m_textureTiles = TextureHolder::getTexture("graphics/tiles_sheet.png");
}

void Engine::run()
{
   sf::Clock clock;

   while (m_window.isOpen())
   {
      sf::Time delta = clock.restart();

      m_gameTimeTotal += delta;

      float dtAsSeconds = delta.asSeconds();

      input();
      update(dtAsSeconds);
      draw();
   }
}
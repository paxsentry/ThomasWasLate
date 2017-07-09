#include "hud.h"

Hud::Hud()
{
   sf::Vector2u resolution;
   resolution.x = 1920;
   resolution.y = 1080;

   m_font.loadFromFile("fonts/Roboto-Light.ttf");

   m_startText.setFont(m_font);
   m_startText.setCharacterSize(100);
   m_startText.setFillColor(sf::Color::White);
   m_startText.setString("Press Enter when ready");

   sf::FloatRect textRect = m_startText.getLocalBounds();

   m_startText.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
   m_startText.setPosition(resolution.x / 2.0f, resolution.y / 2.0f);

   m_timeText.setFont(m_font);
   m_timeText.setCharacterSize(75);
   m_timeText.setFillColor(sf::Color::White);
   m_timeText.setPosition(resolution.x - 150, 0);
   m_timeText.setString("-----");

   m_levelText.setFont(m_font);
   m_levelText.setCharacterSize(75);
   m_levelText.setFillColor(sf::Color::White);
   m_levelText.setPosition(25, 0);
   m_levelText.setString("1");
}

sf::Text Hud::getMessage() { return m_startText; }

sf::Text Hud::getLevel() { return m_levelText; }

sf::Text Hud::getTime() { return m_timeText; }

void Hud::setLevel(std::string text) { m_levelText.setString(text); }

void Hud::setTime(std::string text) { m_timeText.setString(text); }
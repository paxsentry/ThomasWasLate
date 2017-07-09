#ifndef THOMAS_WAS_LATE_HUD_H
#define THOMAS_WAS_LATE_HUD_H

#include <SFML\Graphics.hpp>

class Hud
{
public:
   Hud();

   sf::Text getMessage();
   sf::Text getLevel();
   sf::Text getTime();

   void setLevel(std::string text);
   void setTime(std::string text);

private:
   sf::Font m_font;
   sf::Text m_startText;
   sf::Text m_timeText;
   sf::Text m_levelText;
};

#endif // !THOMAS_WAS_LATE_HUD_H
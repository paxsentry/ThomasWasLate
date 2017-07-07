#ifndef THOMAS_WAS_LATE_LEVEL_MANAGER_H
#define THOMAS_WAS_LATE_LEVEL_MANAGER_H

#include <SFML/Graphics.hpp>

class LevelManager
{
public:
   const int TILE_SIZE = 50;
   const int VERTS_IN_QUAD = 4;

   float getTimeLimit();

   sf::Vector2f getStartPosition();

   int** nextLevel(sf::VertexArray& rVALevel); // Pointer to a pointer

   sf::Vector2i getLevelSize();

   int getCurrentLevel();

private:
   sf::Vector2i m_levelSize;
   sf::Vector2f m_startPosition;

   float m_timeModifier = 1;
   float m_baseTimeLimit = 0;

   int m_currentLevel = 1;
   const int NUM_LEVELS = 4;
};

#endif // !THOMAS_WAS_LATE_LEVEL_MANAGER_H
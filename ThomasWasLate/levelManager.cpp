#include "levelManager.h"
#include "SFML\Audio.hpp"
#include "textureHolder.h"
#include <sstream>
#include <fstream>

float LevelManager::getTimeLimit() { return m_baseTimeLimit * m_timeModifier; }

sf::Vector2f LevelManager::getStartPosition() { return m_startPosition; }

int ** LevelManager::nextLevel(sf::VertexArray & rVALevel)
{
   m_levelSize.x = 0;
   m_levelSize.y = 0;

   m_currentLevel++;

   if (m_currentLevel > NUM_LEVELS) {
      m_currentLevel = 1;
      m_timeModifier -= .1f;
   }

   std::string levelToLoad;
   switch (m_currentLevel)
   {
   case 1:
      levelToLoad = "levels/level1.txt";
      m_startPosition.x = 100;
      m_startPosition.y = 100;
      m_baseTimeLimit = 30.0f;
      break;
   case 2:
      levelToLoad = "levels/level2.txt";
      m_startPosition.x = 100;
      m_startPosition.y = 3600;
      m_baseTimeLimit = 100.0f;
      break;
   case 3:
      levelToLoad = "levels/level3.txt";
      m_startPosition.x = 1250;
      m_startPosition.y = 0;
      m_baseTimeLimit = 30.0f;
      break;
   case 4:
      levelToLoad = "levels/level4.txt";
      m_startPosition.x = 50;
      m_startPosition.y = 200;
      m_baseTimeLimit = 50.0f;
      break;
   default:
      break;
   }

   std::ifstream inputFile(levelToLoad);
   std::string s;

   while (std::getline(inputFile, s))
   {
      ++m_levelSize.y;
   }
   m_levelSize.x = s.length();

   inputFile.clear();
   inputFile.seekg(0, std::ios::beg);

   int** arrayLevel = new int*[m_levelSize.y];
   for (int i = 0; i < m_levelSize.y; ++i)
   {
      arrayLevel[i] = new int[m_levelSize.x];
   }

   std::string row;
   int y = 0;
   while (inputFile >> row)
   {
      for (int x = 0; x < row.length(); x++)
      {
         const char val = row[x];
         arrayLevel[y][x] = atoi(&val);
      }
      y++;
   }

   inputFile.close();

   rVALevel.setPrimitiveType(sf::Quads);
   rVALevel.resize(m_levelSize.x * m_levelSize.y * VERTS_IN_QUAD);

   int currentVertex = 0;

   for (int x = 0; x < m_levelSize.x; x++)
   {
      for (int y = 0; y < m_levelSize.y; y++)
      {
         rVALevel[currentVertex + 0].position = sf::Vector2f(x * TILE_SIZE, y * TILE_SIZE);
         rVALevel[currentVertex + 1].position = sf::Vector2f((x * TILE_SIZE) + TILE_SIZE, y * TILE_SIZE);
         rVALevel[currentVertex + 2].position = sf::Vector2f((x * TILE_SIZE) + TILE_SIZE, (y * TILE_SIZE) + TILE_SIZE);
         rVALevel[currentVertex + 3].position = sf::Vector2f(x * TILE_SIZE, (y * TILE_SIZE) + TILE_SIZE);

         int verticalOffset = arrayLevel[y][x] * TILE_SIZE;

         rVALevel[currentVertex + 0].texCoords = sf::Vector2f(0, 0 + verticalOffset);
         rVALevel[currentVertex + 1].texCoords = sf::Vector2f(TILE_SIZE, 0 + verticalOffset);
         rVALevel[currentVertex + 2].texCoords = sf::Vector2f(TILE_SIZE, TILE_SIZE + verticalOffset);
         rVALevel[currentVertex + 3].texCoords = sf::Vector2f(0, TILE_SIZE + verticalOffset);

         currentVertex = currentVertex + VERTS_IN_QUAD;
      }
   }

   return arrayLevel;
}

sf::Vector2i LevelManager::getLevelSize() { return m_levelSize; }

int LevelManager::getCurrentLevel() { return m_currentLevel; }
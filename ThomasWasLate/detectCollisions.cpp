#include "engine.h"

bool Engine::detectCollision(PlayableCharacter& character) {
   bool reachedGoal = false;

   sf::FloatRect detectionZone = character.getPosition();

   sf::FloatRect block;
   block.width = TILE_SIZE;
   block.height = TILE_SIZE;

   int startX = (int)(detectionZone.left / TILE_SIZE) - 1;
   int startY = (int)(detectionZone.top / TILE_SIZE) - 1;
   int endX = (int)(detectionZone.left / TILE_SIZE) + 2;
   int endY = (int)(detectionZone.top / TILE_SIZE) + 3;

   if (startX < 0) { startX = 0; }
   if (startY < 0) { startY = 0; }
   if (endX >= m_levelManager.getLevelSize().x) { endX = m_levelManager.getLevelSize().x; }
   if (endY >= m_levelManager.getLevelSize().y) { endY = m_levelManager.getLevelSize().y; }

   sf::FloatRect level(0, 0, m_levelManager.getLevelSize().x * TILE_SIZE, m_levelManager.getLevelSize().y * TILE_SIZE);

   if (!character.getPosition().intersects(level)) { character.spawn(m_levelManager.getStartPosition(), GRAVITY); }

   for (int x = startX; x < endX; x++)
   {
      for (int y = startY; y < endY; y++)
      {
         block.left = x * TILE_SIZE;
         block.top = y * TILE_SIZE;

         if (m_ArrayLevel[y][x] == 2 || m_ArrayLevel[y][x] == 3) {
            if (character.getHead().intersects(block)) {
               character.spawn(m_levelManager.getStartPosition(), GRAVITY);

               if (m_ArrayLevel[y][x] == 2) {
                  //Fire sound
               }
               else {
                  //water sound
               }
            }
         }

         if (m_ArrayLevel[y][x] == 1) {
            if (character.getRight().intersects(block)) { character.stopRight(block.left); }
            else if (character.getLeft().intersects(block)) { character.stopLeft(block.left); }

            if (character.getFeet().intersects(block)) { character.stopFalling(block.top); }
            else if (character.getHead().intersects(block)) { character.stopJump(); }
         }

         if (m_ArrayLevel[y][x] == 4) {
            reachedGoal = true;
         }
      }
   }

   return reachedGoal;
}
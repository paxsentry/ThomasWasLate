#include "engine.h"

void Engine::populateEmitters(std::vector <sf::Vector2f>& vSoundEmitters, int** arrayLevel) {
   vSoundEmitters.empty();

   sf::FloatRect previousEmitter;

   for (int x = 0; x < (int)m_levelManager.getLevelSize().x; x++)
   {
      for (int y = 0; y < (int)m_levelManager.getLevelSize().y; y++)
      {
         if (arrayLevel[y][x] == 2) {
            if (!sf::FloatRect(x * TILE_SIZE, y * TILE_SIZE, TILE_SIZE, TILE_SIZE).intersects(previousEmitter)) {
               vSoundEmitters.push_back(sf::Vector2f(x  * TILE_SIZE, y * TILE_SIZE));

               previousEmitter.left = x * TILE_SIZE;
               previousEmitter.top = y * TILE_SIZE;
               previousEmitter.width = TILE_SIZE * 6;
               previousEmitter.height = TILE_SIZE * 6;
            }
         }
      }
   }

   return;
}
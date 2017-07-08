#ifndef THOMAS_WAS_LATE_ENGINE
#define THOMAS_WAS_LATE_ENGINE

#include <SFML/Graphics.hpp>
#include "textureHolder.h"
#include "thomas.h"
#include "bob.h"
#include "levelManager.h"

class Engine
{
public:
   Engine();

   void run();

private:
   TextureHolder m_th;

   Thomas m_thomas;
   Bob m_bob;

   LevelManager m_levelManager;

   const int TILE_SIZE = 50;
   const int VERTS_IN_QUAD = 4;
   const int GRAVITY = 300;

   sf::RenderWindow m_window;

   sf::View m_mainView;
   sf::View m_leftView;
   sf::View m_rightView;

   sf::View m_BG_mainView;
   sf::View m_BG_leftView;
   sf::View m_BG_rightView;

   sf::View m_hudView;

   sf::Sprite m_sprite_Background;
   sf::Texture m_texture_Background;

   bool m_playing = false;
   bool m_characterOne = true;
   bool m_splitScreen = false;
   bool m_newLevelRequired = true;

   float m_timeRemaining = 10;
   sf::Time m_gameTimeTotal;

   sf::VertexArray m_VALevel;

   int** m_ArrayLevel = NULL;

   sf::Texture m_textureTiles;

   void input();
   void update(float dtAsSeconds);
   void draw();

   void loadLevel();

   bool detectCollision(PlayableCharacter& character);
};

#endif // !THOMAS_WAS_LATE_ENGINE
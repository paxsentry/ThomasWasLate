#ifndef THOMAS_WAS_LATE_ENGINE
#define THOMAS_WAS_LATE_ENGINE

#include <SFML/Graphics.hpp>
#include "textureHolder.h"
#include "thomas.h"
#include "bob.h"
#include "levelManager.h"
#include "SoundManager.h"
#include "hud.h"
#include "particleSystem.h"

class Engine
{
public:
   Engine();

   void run();

private:
   TextureHolder m_th;

   ParticleSystem m_particleSystem;

   Thomas m_thomas;
   Bob m_bob;

   LevelManager m_levelManager;
   SoundManager m_soundManager;
   
   Hud m_hud;
   int m_frameSinceLastUpdate = 0;
   int m_targetFramesPerUpdate = 500;

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

   void populateEmitters(std::vector <sf::Vector2f>& vSoundEmitters, int** arrayLevel);
   std::vector <sf::Vector2f> m_fireEmitters;
};

#endif // !THOMAS_WAS_LATE_ENGINE
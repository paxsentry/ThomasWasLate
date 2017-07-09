#ifndef THOMAS_WAS_LATE_SOUND_MANAGER
#define THOMAS_WAS_LATE_SOUND_MANAGER

#include <SFML\Audio.hpp>

class SoundManager {
public:
   SoundManager();

   void playFire(sf::Vector2f emitterLocation, sf::Vector2f listenerLocation);
   void playFallInFire();
   void playFallInWater();
   void playJump();
   void playReachGoal();

private:
   sf::SoundBuffer m_sb_fire;
   sf::SoundBuffer m_sb_fallInFire;
   sf::SoundBuffer m_sb_fallInWater;
   sf::SoundBuffer m_sb_jump;
   sf::SoundBuffer m_sb_reachGoal;

   sf::Sound m_s_Fire1;
   sf::Sound m_s_Fire2;
   sf::Sound m_s_Fire3;
   sf::Sound m_s_fallInFire;
   sf::Sound m_s_fallInWater;
   sf::Sound m_s_jump;
   sf::Sound m_s_reachGoal;

   int m_nextSound = 1;
};

#endif // !THOMAS_WAS_LATE_SOUND_MANAGER
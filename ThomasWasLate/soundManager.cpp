#include "SoundManager.h"

SoundManager::SoundManager()
{
   m_sb_fire.loadFromFile("sound/fire1.wav");
   m_sb_fallInFire.loadFromFile("sound/fallinfire.wav");
   m_sb_fallInWater.loadFromFile("sound/fallinwater.wav");
   m_sb_jump.loadFromFile("sound/jump.wav");
   m_sb_reachGoal.loadFromFile("sound/reachgoal.wav");

   m_s_Fire1.setBuffer(m_sb_fire);
   m_s_Fire2.setBuffer(m_sb_fire);
   m_s_Fire3.setBuffer(m_sb_fire);
   m_s_fallInFire.setBuffer(m_sb_fallInFire);
   m_s_fallInWater.setBuffer(m_sb_fallInWater);
   m_s_jump.setBuffer(m_sb_jump);
   m_s_reachGoal.setBuffer(m_sb_reachGoal);

   float minDistance = 150;
   float attenuation = 15;

   m_s_Fire1.setAttenuation(attenuation);
   m_s_Fire2.setAttenuation(attenuation);
   m_s_Fire3.setAttenuation(attenuation);

   m_s_Fire1.setMinDistance(minDistance);
   m_s_Fire2.setMinDistance(minDistance);
   m_s_Fire3.setMinDistance(minDistance);

   m_s_Fire1.setLoop(true);
   m_s_Fire2.setLoop(true);
   m_s_Fire3.setLoop(true);
}

void SoundManager::playFire(sf::Vector2f emitterLocation, sf::Vector2f listenerLocation)
{
   sf::Listener::setPosition(listenerLocation.x, listenerLocation.y, 0.0f);

   switch (m_nextSound)
   {
   case 1:
      m_s_Fire1.setPosition(emitterLocation.x, emitterLocation.y, 0.0f);
      if (m_s_Fire1.getStatus() == sf::Sound::Status::Stopped) { m_s_Fire1.play(); }
      break;

   case 2:
      m_s_Fire2.setPosition(emitterLocation.x, emitterLocation.y, 0.0f);
      if (m_s_Fire2.getStatus() == sf::Sound::Status::Stopped) { m_s_Fire2.play(); }
      break;

   case 3:
      m_s_Fire3.setPosition(emitterLocation.x, emitterLocation.y, 0.0f);
      if (m_s_Fire3.getStatus() == sf::Sound::Status::Stopped) { m_s_Fire3.play(); }
      break;

   default:
      break;
   }

   m_nextSound++;
   if (m_nextSound > 3) { m_nextSound = 1; }
}

void SoundManager::playFallInFire()
{
   m_s_fallInFire.setRelativeToListener(true);
   m_s_fallInFire.play();
}

void SoundManager::playFallInWater()
{
   m_s_fallInWater.setRelativeToListener(true);
   m_s_fallInWater.play();
}

void SoundManager::playJump()
{
   m_s_jump.setRelativeToListener(true);
   m_s_jump.play();
}

void SoundManager::playReachGoal()
{
   m_s_reachGoal.setRelativeToListener(true);
   m_s_reachGoal.play();
}
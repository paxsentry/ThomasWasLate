#ifndef THOMAS_WAS_LATE_PLAYABLE_CHARACTER_H
#define THOMAS_WAS_LATE_PLAYABLE_CHARACTER_H

#include <SFML\Graphics.hpp>

class PlayableCharacter
{
public:
   void spawn(sf::Vector2f startPosition, float gravity);

   bool virtual handleInput() = 0;

   sf::FloatRect getPosition();

   sf::FloatRect getFeet();
   sf::FloatRect getHead();
   sf::FloatRect getRight();
   sf::FloatRect getLeft();

   sf::Sprite getSprite();

   void stopFalling(float position);
   void stopRight(float position);
   void stopLeft(float position);
   void stopJump();

   sf::Vector2f getCenter();

   void update(float elapsedTime);

protected:
   sf::Sprite m_sprite;

   float m_jumpDuration;
   bool m_isJumping;
   bool m_isFalling;

   bool m_leftPressed;
   bool m_rightPressed;

   float m_timeThisJump;
   bool m_justJumped = false;

private:
   float m_gravity;
   float m_speed = 400;
   sf::Vector2f m_position;

   sf::FloatRect m_feet;
   sf::FloatRect m_head;
   sf::FloatRect m_right;
   sf::FloatRect m_left;

   sf::Texture m_texture;
};

#endif // !THOMAS_WAS_LATE_PLAYABLE_CHARACTER_H
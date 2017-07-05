#include "playableCharacter.h"

void PlayableCharacter::spawn(sf::Vector2f startPosition, float gravity)
{
   m_position.x = startPosition.x;
   m_position.y = startPosition.y;

   m_gravity = gravity;

   m_sprite.setPosition(m_position);
}

sf::FloatRect PlayableCharacter::getPosition() { return m_sprite.getGlobalBounds(); }

sf::FloatRect PlayableCharacter::getFeet() { return m_feet; }

sf::FloatRect PlayableCharacter::getHead() { return m_head; }

sf::FloatRect PlayableCharacter::getRight() { return m_right; }

sf::FloatRect PlayableCharacter::getLeft() { return m_left; }

sf::Sprite PlayableCharacter::getSprite() { return m_sprite; }

void PlayableCharacter::stopFalling(float position)
{
   m_position.y = position - getPosition().height;
   m_sprite.setPosition(m_position);
   m_isFalling = false;
}

void PlayableCharacter::stopRight(float position)
{
   m_position.x = position - m_sprite.getGlobalBounds().width;
   m_sprite.setPosition(m_position);
}

void PlayableCharacter::stopLeft(float position)
{
   m_position.x = position + m_sprite.getGlobalBounds().width;
   m_sprite.setPosition(m_position);
}

void PlayableCharacter::stopJump()
{
   m_isFalling = true;
   m_isJumping = false;
}

sf::Vector2f PlayableCharacter::getCenter()
{
   return sf::Vector2f(
      m_position.x + m_sprite.getGlobalBounds().width / 2,
      m_position.y + m_sprite.getGlobalBounds().contains / 2
   );
}

void PlayableCharacter::update(float elapsedTime)
{
   if (m_rightPressed) { m_position.x += m_speed * elapsedTime; }

   if (m_leftPressed) { m_position.y -= m_speed * elapsedTime; }

   if (m_isJumping) {
      m_timeThisJump += elapsedTime;

      if (m_timeThisJump < m_jumpDuration) { m_position.y -= m_gravity * 2 * elapsedTime; }
      else {
         m_isJumping = false;
         m_isFalling = true;
      }
   }

   if (m_isFalling) { m_position.y += m_gravity * elapsedTime; }

   sf::FloatRect r = getPosition();

   m_feet.left = r.left + 3;
   m_feet.top = r.top + r.height - 1;
   m_feet.width = r.width - 6;
   m_feet.height = 1;

   m_head.left = r.left;
   m_head.top = r.top + (r.height * 0.3);
   m_head.width = r.width;
   m_head.height = 1;

   m_right.left = r.left + r.width - 2;
   m_right.top = r.top + r.height * .35;
   m_right.width = 1;
   m_right.height = r.height * .3;

   m_left.left = r.left;
   m_left.top = r.top + r.height * .3;
   m_left.width = 1;
   m_left.height = r.height * .3;

   m_sprite.setPosition(m_position);
}

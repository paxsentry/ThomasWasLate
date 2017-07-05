#include "bob.h"
#include "textureHolder.h"

Bob::Bob()
{
   m_sprite = sf::Sprite(TextureHolder::getTexture("graphics/bob.png"));

   m_jumpDuration = .25f;
}

bool Bob::handleInput()
{
   m_justJumped = false;

   if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
      if (!m_isJumping && !m_isFalling) {
         m_isJumping = true;
         m_timeThisJump = 0;
         m_justJumped = true;
      }
   }
   else {
      m_isJumping = false;
      m_isFalling = true;
   }

   if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) { m_leftPressed = true; }
   else { m_leftPressed = false; }

   if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) { m_rightPressed = true; }
   else { m_rightPressed = false; }

   return m_justJumped;
}
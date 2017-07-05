#include "thomas.h"
#include "textureHolder.h"

Thomas::Thomas()
{
   m_sprite = sf::Sprite(TextureHolder::getTexture("graphics/thomas.png"));

   m_jumpDuration = .45f;
}

bool Thomas::handleInput()
{
   m_justJumped = false;

   if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
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

   if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) { m_leftPressed = true; }
   else { m_leftPressed = false; }

   if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) { m_rightPressed = true; }
   else { m_rightPressed = false; }

   return m_justJumped;
}
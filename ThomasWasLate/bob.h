#ifndef THOMAS_WAS_LATE_BOB_H
#define THOMAS_WAS_LATE_BOB_H

#include "playableCharacter.h"

class Bob :public PlayableCharacter
{
public:
   Bob();

   // Inherited via PlayableCharacter
   virtual bool handleInput() override;
};

#endif // !THOMAS_WAS_LATE_BOB_H
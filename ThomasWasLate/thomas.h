#pragma once
#ifndef THOMAS_WAS_LATE_THOMAS_H
#define THOMAS_WAS_LATE_THOMAS_H

#include "playableCharacter.h"

class Thomas : public PlayableCharacter
{
public:
   Thomas();

   // Inherited via PlayableCharacter
   virtual bool handleInput() override;
};

#endif // !THOMAS_WAS_LATE_THOMAS_H
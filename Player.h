#ifndef PLAYER_H
#define PLAYER_H

#include "Arduboy2.h"

class Player {

   public:
     Rect getRect();
     
   int16_t x;
   int16_t y;
   const uint8_t *bitmap;
   
};
#endif

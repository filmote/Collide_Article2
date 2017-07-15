#include "Player.h"
#include "Arduboy2.h"

Rect Player::getRect() {
   
  return (Rect){x, y, pgm_read_byte(bitmap), pgm_read_byte(bitmap + 1)};

}



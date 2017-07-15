#include <Arduboy2.h>
#include "Player.h"
#include "Images.h"

Arduboy2 arduboy;  
Sprites sprites;

int16_t frame; 

Player playerA;
Player playerB;

void setup() {

  playerA.x = -16;
  playerA.y = 12;
  playerA.bitmap = squareA;

  playerB.x = 128;
  playerB.y = 24;
  playerB.bitmap = squareB;

  arduboy.begin();
  
}

void loop() {

  arduboy.clear();

  Serial.println("------------------------");
  Serial.print("A collides with circle : ");
  Serial.println(arduboy.collide(playerA.getRect(), (Rect){24, 4, 16, 16}));
  Serial.print("A collides with B : ");
  Serial.println(arduboy.collide(playerA.getRect(), playerB.getRect()));
  Serial.print("A collides with dot : ");
  Serial.println(arduboy.collide( (Point){64, 20}, playerA.getRect() ));
  Serial.print("B collides with square : ");
  Serial.println(arduboy.collide(playerB.getRect(), (Rect){96, 32, 16, 16}));
  Serial.print("B collides with dot : ");
  Serial.println(arduboy.collide( (Point){64, 32}, playerB.getRect()));

  arduboy.drawCircle(32, 12, 8, WHITE);
  arduboy.drawRect(96, 32, 16, 16, WHITE);
  arduboy.drawPixel(64, 20, WHITE);
  arduboy.drawPixel(64, 32, WHITE);

  sprites.drawOverwrite(playerA.x, playerA.y, playerA.bitmap, frame);
  sprites.drawOverwrite(playerB.x, playerB.y, playerB.bitmap, frame);

  playerA.x++;  if (playerA.x >= 128)  { playerA.x = -16; }
  playerB.x--;  if (playerB.x < -16)   { playerB.x = 128; }
  
  arduboy.display();
  arduboy.delayShort(10);

  while (true) {

    if (arduboy.pressed(A_BUTTON)) { break; }
    arduboy.delayShort(20);  

  }

}


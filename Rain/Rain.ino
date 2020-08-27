#include <Arduboy2.h>
#include <EEPROM.h>
Arduboy2 ard;
Sprites sprite;
#include "Enums.h"
#include "Bitmaps.h"
#include "Game.h"


void setup() {
  ard.begin();
}

void loop() {
  if(!ard.nextFrame())
    return;


  ard.pollButtons();
  ard.clear();  
  RunLoop();
  ard.display();
}

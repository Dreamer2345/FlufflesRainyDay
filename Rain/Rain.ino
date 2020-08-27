#include <Arduboy2.h>
#include <ArduboyTones.h>
#include <EEPROM.h>
Arduboy2 ard;
Sprites sprite;
ArduboyTones sound(ard.audio.enabled);
#include "Music.h"
#include "Enums.h"
#include "Bitmaps.h"
#include "Game.h"


void setup() {
  ard.begin();
  
}

void loop() {
  if(!ard.nextFrameDEV())
    return;


  ard.pollButtons();
  ard.clear();  
  RunLoop();
  ard.display();
}

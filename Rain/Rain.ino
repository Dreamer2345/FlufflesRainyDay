#include <Arduboy2.h>
Arduboy2 ard;
#include "Rain.h"
#include "Enums.h"
#include "Bitmaps.h"
#include "Game.h"


void setup() {
  ard.begin();
  amb.Init();
}

void loop() {
  if(!ard.nextFrame())
    return;


  ard.pollButtons();
  ard.clear();  
  RunLoop();
  ard.display();
}

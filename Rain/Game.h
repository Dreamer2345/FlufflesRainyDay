#pragma once
#define MAXZLEVELS 4
#define EEPROM_START   EEPROM_STORAGE_SPACE_START + 1
#define EEPROM_SCORE_START   EEPROM_START + 2

unsigned long Score = 0;
unsigned long High = 0;
uint8_t Speed = 1;

#include "Rain.h"
#include "ObjectManager.h"
Ambiance amb;
ObjectManager objmngr;

void InitHighScore(){
  char F = EEPROM.read(EEPROM_START);
  char R = EEPROM.read(EEPROM_START+1);
  
  if((F != 'F')||(R != 'R')){
    EEPROM.update(EEPROM_START, 'F');
    EEPROM.update(EEPROM_START+1, 'R');  
    EEPROM.put(EEPROM_SCORE_START, (unsigned long)0);
  }
  else
  {
    EEPROM.get(EEPROM_SCORE_START, High);
  }
  
  gamestate = GameState::MainMenu;
}

void MainMenu(){
  sprite.drawSelfMasked(15,0,Title,0);
  ard.setCursor(55,42);
  ard.print((unsigned long)High);
  if(ard.justPressed(0xFF)){
    gamestate = GameState::GameInit;
  }
}


//Type, State, Frame, X, Y, SizeX, SizeY, Active
void GameInit(){
  amb.Init();
  objmngr.Reset();
  Score = 0;
  Speed = 1;
  objmngr.AddObject((Object){0,0,0,10,10,24,17,true});
  uint8_t r = random(0,MAXZLEVELS);
  uint8_t r1 = random(0,MAXZLEVELS);
  if(r != r1){
    objmngr.AddObject((Object){1,0,0,128,(r * 9) + 20,24,16,true});
    objmngr.AddObject((Object){1,0,0,128,(r1  * 9) + 20,10,10,true});
  }
  else{
    objmngr.AddObject((Object){1,0,0,128,(r * 9) + 20,24,16,true});
  }
  
  gamestate = GameState::GamePlay;
}

void GamePlay(){
  amb.Update();
  amb.Draw();
  objmngr.Update();
  objmngr.Draw();

  if(!objmngr.Contains(1))
  {
    Score++;
    if(Score % 20 == 0)
      Speed++;
    uint8_t r = random(0,MAXZLEVELS);
    uint8_t r1 = random(0,MAXZLEVELS);
    if(r != r1){
      objmngr.AddObject((Object){1,0,0,128,(r * 9) + 20,24,16,true});
      objmngr.AddObject((Object){1,0,0,128,(r1  * 9) + 20,10,10,true});
    }
    else{
      objmngr.AddObject((Object){1,0,0,128,(r * 9) + 20,24,16,true});
    }
  }

  
  if(Speed > 3)
    Speed = 3;
  ard.print(F("Score:"));
  ard.print((unsigned long)Score);
}

void GameOver(){
  amb.Draw();
  objmngr.Update();
  objmngr.Draw();

  if(ard.justPressed(0xFF)){
    gamestate = GameState::MainMenu;
    if(Score > High){
      High = Score;
      EEPROM.put(EEPROM_SCORE_START, High);  
    }
  }
}

void RunLoop(){
  switch(gamestate){
    case GameState::InitHighScore: InitHighScore(); break;
    case GameState::MainMenu: MainMenu(); break;
    case GameState::GameInit: GameInit(); break;
    case GameState::GamePlay: GamePlay(); break;
    case GameState::GameOver: GameOver(); break;
  }
}

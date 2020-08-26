#pragma once
#include "ObjectManager.h"
Ambiance amb;
ObjectManager objmngr;

void MainMenu(){
  amb.Update();
  amb.Draw();

  if(ard.pressed(A_BUTTON)){
    gamestate = GameState::GameInit;
  }
}

void GameInit(){
  objmngr.Reset();
  objmngr.AddObject((Object){0,0,0,0,0,10,10,true});
  objmngr.AddObject((Object){1,0,0,128,0,10,10,true});
  gamestate = GameState::GamePlay;
}

void GamePlay(){
  objmngr.Update();
  objmngr.Draw();
}


void RunLoop(){
  switch(gamestate){
    case GameState::MainMenu: MainMenu(); break;
    case GameState::GameInit: GameInit(); break;
    case GameState::GamePlay: GamePlay(); break;
    case GameState::GameOver: break;
  }
}

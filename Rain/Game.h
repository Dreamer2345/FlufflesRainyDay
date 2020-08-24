#pragma once
#include "ObjectManager.h"
Ambiance amb;
ObjectManager objmngr;

void MainMenu(){
  amb.Update();
  amb.Draw();
}

void GameInit(){
  objmngr.Reset();
  gamestate = GameState::GamePlay;
}


void RunLoop(){
  switch(gamestate){
    case GameState::MainMenu: MainMenu(); break;
    case GameState::GameInit: break;
    case GameState::GamePlay: break;
    case GameState::GameOver: break;
  }
}

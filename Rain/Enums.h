#pragma once

enum class GameState {MainMenu,GameInit,GameOver,GamePlay};
const uint8_t PROGMEM FlufflesWalk[] = {0,1,0,2};
const uint8_t PROGMEM FlufflesCry[] = {0,3,0,3};
const uint8_t *const FlufflesFrameRefrence[] PROGMEM = {FlufflesWalk, FlufflesCry};



GameState gamestate = GameState::MainMenu;

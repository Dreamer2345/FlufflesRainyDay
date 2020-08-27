#pragma once



void UpdateFluffles(Object* obj, ObjectManager* handler)
{
  if(ard.justPressed(UP_BUTTON))
  {
    if(obj->Y > 10)
      obj->Y-=9;    
  }

  if(ard.justPressed(DOWN_BUTTON))
  {
    if(obj->Y < (9 * MAXZLEVELS) + 10)
      obj->Y+=9;    
  }

  if(ard.justPressed(A_BUTTON))
  {
    
    obj->State = 1;    
  }

  if(ard.justPressed(B_BUTTON))
  {
    
    obj->State = 0;    
    gamestate = GameState::MainMenu;
  }
  
  if(handler->UpdateFrameCount())
  {
    obj->FrameData++;
    obj->FrameData%=4;
  }
}

void UpdatePuddle(Object* obj, ObjectManager* handler)
{
  if(obj->State == 0){
    obj->X-=Speed;
    if(obj->X < -20)
    {
      uint8_t r = random(0,MAXZLEVELS);
      obj->Active = false;
      //handler->AddObject((Object){1,0,0,128,(9*r)+20,10,10,true});
    }  

    Object player = handler->Objects[0];
    int16_t PuddleColideY =  obj->Y - 10;

    if((player.Y == PuddleColideY)&&(obj->X < 24))
    {
      handler->Objects[0].State = 1;
      for(IntType i = 0; i < MAXOBJECTS; i++)
      {
        if(handler->Objects[i].Active)
          if(handler->Objects[i].Type == obj->Type)
            handler->Objects[i].State = 1;
      }
      gamestate = GameState::GameOver;
    }
  }
}


using UpdateObjectFunction = void(*)(Object *, ObjectManager* );
UpdateObjectFunction UpdateFunctionArray[MAXOBJECTTYPE] {UpdateFluffles,UpdatePuddle};

void RunFunction(uint8_t type, Object * object, ObjectManager* handler)
{
  if(type > MAXOBJECTTYPE -1)
    return;

  UpdateFunctionArray[type](object, handler);
}

#pragma once


void UpdateFluffles(Object* obj, ObjectManager* handler)
{
  if(ard.justPressed(UP_BUTTON))
  {
    if(obj->Y > 0)
      obj->Y-=18;    
  }

  if(ard.justPressed(DOWN_BUTTON))
  {
    if(obj->Y < 36)
      obj->Y+=18;    
  }

  if(ard.justPressed(A_BUTTON))
  {
    
    obj->State = 1;    
  }

  if(ard.justPressed(B_BUTTON))
  {
    
    obj->State = 0;    
  }
  
  if(handler->UpdateFrameCount())
  {
    obj->FrameData++;
    obj->FrameData%=4;
  }
}

void UpdateTree(Object* obj, ObjectManager* handler)
{
    obj->X--;

    if(obj->X < 20)
    {
      obj->Active = false;
      handler->AddObject((Object){1,1,0,200,0,true});
    }  
}


using UpdateObjectFunction = void(*)(Object *, ObjectManager* );
UpdateObjectFunction UpdateFunctionArray[MAXOBJECTTYPE] {UpdateFluffles,UpdateTree};

void RunFunction(uint8_t id, Object * object, ObjectManager* handler)
{
  if(id > MAXOBJECTTYPE)
    return;

  UpdateFunctionArray[id](object, handler);
}

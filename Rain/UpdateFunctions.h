#pragma once




using UpdateObjectFunction = void(*)(Object *);
UpdateObjectFunction UpdateFunctionArray[MAXOBJECTTYPE] {};

void RunFunction(uint8_t id, Object * object)
{
  if(id > MAXOBJECTTYPE)
    return;

  UpdateFunctionArray[id](object);
}

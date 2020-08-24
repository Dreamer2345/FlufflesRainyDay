#pragma once




using DrawObjectFunction = void(*)(Object *);
DrawObjectFunction DrawFunctionArray[MAXOBJECTTYPE] {};

void DrawFunction(uint8_t id, Object * object)
{
  if(id > MAXOBJECTTYPE)
    return;

  DrawFunctionArray[id](object);
}

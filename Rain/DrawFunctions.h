#pragma once

void DrawFluffles(Object* fluffles, ObjectManager* handler){
  uint16_t X = fluffles -> X;
  uint16_t Y = fluffles -> Y;
  uint8_t frame = pgm_read_byte_near(pgm_read_byte_near(&(FlufflesFrameRefrence[fluffles->State]))+fluffles->FrameData);
  ard.println(fluffles->State);
  ard.println(frame);
  sprite.drawSelfMasked(X,Y,FlufflesSprite,frame);
}

void DrawTree(Object* obj, ObjectManager* handler){
  uint16_t X = obj -> X;
  uint16_t Y = obj -> Y;
  

  sprite.drawSelfMasked(X-40,Y,FlufflesSprite,0);
}


using DrawObjectFunction = void(*)(Object *, ObjectManager*);
DrawObjectFunction DrawFunctionArray[MAXOBJECTTYPE] {DrawFluffles, DrawTree};

void DrawFunction(uint8_t id, Object * object, ObjectManager* handler)
{
  if(id > MAXOBJECTTYPE)
    return;

  DrawFunctionArray[id](object, handler);
}

#pragma once

void DrawFluffles(Object* fluffles, ObjectManager* handler){
  int16_t X = fluffles -> X;
  int16_t Y = fluffles -> Y;
  uint8_t frame = pgm_read_byte_near(pgm_read_byte_near(&(FlufflesFrameRefrence[fluffles->State]))+fluffles->FrameData);
  sprite.drawExternalMask(X,Y,FlufflesSprite,FlufflesSpriteMask,frame,frame);
}

void DrawPuddle(Object* obj, ObjectManager* handler){
  int16_t X = obj -> X;
  int16_t Y = obj -> Y;
  

  sprite.drawExternalMask(X,Y,PuddleSprite,PuddleSpriteMask,0,0);
}

void DrawTree(Object* obj, ObjectManager* handler){
  int16_t X = obj -> X;
  int16_t Y = obj -> Y;
  

  sprite.drawExternalMask(X,Y,TreeSprite,TreeSpriteMask,0,0);
}


using DrawObjectFunction = void(*)(Object *, ObjectManager*);
DrawObjectFunction DrawFunctionArray[MAXOBJECTTYPE] {DrawFluffles, DrawPuddle, DrawTree};

void DrawFunction(uint8_t type, Object * object, ObjectManager* handler)
{
  if(type > MAXOBJECTTYPE - 1)
    return;

  DrawFunctionArray[type](object, handler);
}

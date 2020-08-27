#pragma once
#define FramesPerAnimUpdate 10
#define MAXOBJECTS 5
#define MAXOBJECTTYPE 3
#define IntType uint16_t
#include "Object.h"

class ObjectManager{
  public:
    void Update();
    void Draw();
    bool AddObject(Object i);
    bool RemoveObject(IntType ID);
    bool Contains(IntType Type);
    void Reset();
    bool UpdateFrameCount();
    Object Objects[MAXOBJECTS];
    uint8_t FrameCounter;
};

#include "UpdateFunctions.h"
#include "DrawFunctions.h"

void ObjectManager::Update(){
  FrameCounter++;
  FrameCounter %= FramesPerAnimUpdate;
  
  for(IntType i = 0; i < MAXOBJECTS; i++){
    if(Objects[i].Active)
    {
      RunFunction(Objects[i].Type,&Objects[i],this);
    }
  }
}

void ObjectManager::Draw(){
  IntType DrawOrder[MAXOBJECTS];
  int16_t DrawVals[MAXOBJECTS];
  for(IntType i = 0; i < MAXOBJECTS; i++){DrawOrder[i] = i; if(Objects[i].Active){DrawVals[i] = Objects[i].Y + Objects[i].SizeY;}else{DrawVals[i] = -256;}}

  
  uint8_t A = 1;
  while(A < MAXOBJECTS)
  {
    uint8_t B = A;
    while((B > 0)&&(DrawVals[B-1] > DrawVals[B])){
      uint8_t s = DrawOrder[B];
      DrawOrder[B] = DrawOrder[B - 1];
      DrawOrder[B - 1] = s;

      int16_t s1 = DrawVals[B];
      DrawVals[B] = DrawVals[B - 1];
      DrawVals[B - 1] = s;
      
      B--; 
    }
    A++;
  }
  
  for(IntType i = 0; i < MAXOBJECTS; i++){
    if(Objects[DrawOrder[i]].Active)
    {
      DrawFunction(Objects[DrawOrder[i]].Type,&Objects[DrawOrder[i]],this);
    }
  }
  /*
  for(IntType i = 0; i < MAXOBJECTS; i++){
    if(Objects[DrawOrder[i]].Active){
      ard.setCursor(Objects[DrawOrder[i]].X,Objects[DrawOrder[i]].Y);
      ard.print(i);
      ard.print(F(":"));
      ard.print(DrawVals[i]);
      ard.print(F(":"));
      ard.print(Objects[DrawOrder[i]].SizeY);
    }
  }
  ard.setCursor(0,0);
  */
}

bool ObjectManager::AddObject(Object obj){
  for(IntType i = 0; i < MAXOBJECTS; i++){
    
    if(!Objects[i].Active)
    {
      
      Objects[i].X = obj.X;
      Objects[i].Y = obj.Y;
      Objects[i].State = obj.State;
      Objects[i].FrameData = obj.FrameData;
      Objects[i].Type = obj.Type;
      Objects[i].SizeX = obj.SizeX;
      Objects[i].SizeY = obj.SizeY;
      Objects[i].Active = true;
      return true;
    }
  }
  return false;
}

bool ObjectManager::RemoveObject(IntType ID){
  if(ID > MAXOBJECTS)
      return false;
  Objects[ID].Active = false;
  return true;
}

bool ObjectManager::Contains(IntType type){
  if(type > MAXOBJECTTYPE-1)
      return false;
  for(IntType i = 0; i < MAXOBJECTS; i++){
    if(Objects[i].Active)
      if(Objects[i].Type == type)
        return true;
  }
  return false;
}

void ObjectManager::Reset(){
  for(IntType i = 0; i < MAXOBJECTS; i++){
    if(Objects[i].Active)
    {
      Objects[i].Active = false;
    }
  }
}

bool ObjectManager::UpdateFrameCount(){
  return FrameCounter == FramesPerAnimUpdate - 1;
}

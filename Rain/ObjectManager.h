#pragma once
#define FramesPerAnimUpdate 10
#define MAXOBJECTS 10
#define MAXOBJECTTYPE 4
#define IntType uint16_t
#include "Object.h"

class ObjectManager{
  public:
    void Update();
    void Draw();
    bool AddObject(Object i);
    bool RemoveObject(IntType i);
    void Reset();
    bool UpdateFrameCount();
   private:
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
      RunFunction(i,&Objects[i],this);
    }
  }
}

void ObjectManager::Draw(){
  for(IntType i = 0; i < MAXOBJECTS; i++){
    if(Objects[i].Active)
    {
      DrawFunction(i,&Objects[i],this);
    }
  }
}

bool ObjectManager::AddObject(Object obj){
  for(IntType i = 0; i < MAXOBJECTS; i++){
    if(!Objects[i].Active)
    {
      Objects[i] = obj;
      Objects[i].Active = true;
      return true;
    }
  }
  return false;
}

bool ObjectManager::RemoveObject(IntType i){
  if(i > MAXOBJECTS)
      return false;
  Objects[i].Active = false;
  return true;
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

#pragma once
#define MAXOBJECTS 10
#define MAXOBJECTTYPE 4
#define IntType uint8_t
#include "Object.h"
bool AddObject(Object);
bool RemoveObject(IntType);


#include "UpdateFunctions.h"
#include "DrawFunctions.h"

class ObjectManager{
  public:
    void Update();
    void Draw();
    bool AddObject(Object);
    void RemoveObject(IntType);
    void Reset();
   private:
    Object Objects[MAXOBJECTS];
};

void ObjectManager::Update(){
  for(IntType i = 0; i < MAXOBJECTS; i++){
    if(Objects[i].Active)
    {
      RunFunction(Objects[i],&Object);
    }
  }
}

void ObjectManager::Draw(){
  for(IntType i = 0; i < MAXOBJECTS; i++){
    if(Objects[i].Active)
    {
      DrawFunction(Objects[i],&Object);
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

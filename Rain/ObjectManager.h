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
    bool AddObject(Object i);
    bool RemoveObject(IntType i);
    void Reset();
   private:
    Object Objects[MAXOBJECTS];
};

void ObjectManager::Update(){
  for(IntType i = 0; i < MAXOBJECTS; i++){
    if(Objects[i].Active)
    {
      RunFunction(i,&Objects[i]);
    }
  }
}

void ObjectManager::Draw(){
  for(IntType i = 0; i < MAXOBJECTS; i++){
    if(Objects[i].Active)
    {
      DrawFunction(i,&Objects[i]);
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

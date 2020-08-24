#pragma once
#include <Arduboy2.h>
#define MaxParticles 5
#define LightningChance 50
#define LightningCooldown 200


struct Particle{
  uint8_t x;
  uint8_t y;
  bool Active;
};

class Ambiance
{
  public:
    void Init();
    void Update();
    void Draw();
  private:
    uint8_t CooldownFrames = 0;
    uint8_t Accum = 0;
    bool Lightning = false;
    bool Wind;
    Particle particles[MaxParticles];
};


void Ambiance::Init(){

  for(uint8_t i = 0; i < MaxParticles; i++)
  {
      particles[i].Active = true;      
      particles[i].y = random(0,64);
      particles[i].x = random(0,127);
  }
}

void Ambiance::Update(){
  if(CooldownFrames == 0){
    uint8_t r = random(0,256);
    uint8_t r1 = random(0,256);
    if(r1 > 127){
      Wind = !Wind;
    }
    
    Accum += r;
    if(Accum > LightningChance){
      Accum -= LightningChance;
      CooldownFrames = random(60,LightningCooldown);
      Lightning = true;
      ard.invert(true);
    }
  }
  else{
    CooldownFrames--;
    if(Lightning)
    {
      Lightning = false;
      ard.invert(false);
    }
  }


  for(uint8_t i = 0; i < MaxParticles; i++)
  {
    if(particles[i].Active)
      {
        if(particles[i].y > 64)
          particles[i].Active = false;
        
        particles[i].y += 3;
        if(Wind)
          particles[i].x += random(0,2);
        else
          particles[i].x -= random(0,2);
      }
  }

  for(uint8_t i = 0; i < MaxParticles; i++)
  {
    if(!particles[i].Active)
      {
        particles[i].Active = true;
        
        particles[i].y = 0;
        particles[i].x = random(0,127);
      }
  }

  
}

void Ambiance::Draw(){
  for(uint8_t i = 0; i < MaxParticles; i++)
  {
    if(particles[i].Active){
      ard.drawPixel(particles[i].x, particles[i].y, WHITE);
    }
  }
}

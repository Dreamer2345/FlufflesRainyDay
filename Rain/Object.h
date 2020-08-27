#pragma once


class Object{
  public:
    uint8_t Type;
    uint8_t State;
    uint8_t FrameData;
    int16_t X;
    int16_t Y;
    int8_t SizeX;
    int8_t SizeY;
    bool Active;
};

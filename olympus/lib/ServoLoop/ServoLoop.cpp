/* 
This file is based on the Adafruit pixypet  
https://learn.adafruit.com/pixy-pet-robot-color-vision-follower-using-pixycam/the-code 
*/

#include "ServoLoop.h"

ServoLoop::ServoLoop(int propGain, int deriGain)
{
  pos = RCS_CENTER_POS;
  _propGain = propGain;
  _deriGain = deriGain;
  _prevError = 0x80000000L;
}
 
// ServoLoop Update 
// Calculates new output based on the measured
// error and the current state.
void ServoLoop::update(int32_t error)
{
  long int velocity;
  char buf[32];
  if (_prevError!=0x80000000)
  { 
    velocity = (error * _propGain + (error - _prevError) * _deriGain)>>10;
    
    Serial.print(error); 
    Serial.print(" "); 
    Serial.print(_propGain);
    Serial.print(" "); 
    Serial.print(_prevError);
    Serial.print(" "); 
    Serial.print(_deriGain); 
    Serial.print(" ");
    Serial.println(velocity);

    pos += velocity;
    if (pos>RCS_MAX_POS) 
    {
      pos = RCS_MAX_POS; 
    }
    else if (pos<RCS_MIN_POS) 
    {
      pos = RCS_MIN_POS;
    }
  }
  _prevError = error;
}
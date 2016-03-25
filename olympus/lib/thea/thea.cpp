/* Hermes contolls the pixy cam */

#include "thea.h"

ServoLoop panLoop(300, 500);  // Servo loop for pan
ServoLoop tiltLoop(500, 700); // Servo loop for tilt 

// constructor
Thea::Thea(){
	pixy.init(); //start up the camera.

}

// Track blocks via the Pixy pan/tilt mech
void Thea::followBlocks()
{
  blocks = pixy.getBlocks();

  if(blocks){
    _panError = X_CENTER - pixy.blocks[0].x;
    _tiltError = pixy.blocks[0].y - Y_CENTER;

    panLoop.update(_panError);
    tiltLoop.update(_tiltError);

    pixy.setServos(panLoop.pos, tiltLoop.pos);
  }
}
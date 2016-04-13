/* Hermes contolls the pixy cam */

#include "thea.h"



// constructor
Thea::Thea(){
	pixy.init(); //start up the camera.

}

// Track blocks via the Pixy pan/tilt mech
void Thea::followBlocks(){
  blocks = pixy.getBlocks();

  if(blocks){
    _panError = X_CENTER - pixy.blocks[0].x;
    _tiltError = pixy.blocks[0].y - Y_CENTER;

    panLoop.update(_panError);
    tiltLoop.update(_tiltError);

    pixy.setServos(panLoop.pos, tiltLoop.pos);
  }
}

void Thea::stop(){
	pixy.setServos(X_CENTER, Y_CENTER);
}
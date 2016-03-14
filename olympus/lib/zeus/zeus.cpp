/* Zeus is the control system*/

#include <zeus.h>

#define COLLISIONDISTANCE 10 // in cm


Zeus::Zeus(){}


void Zeus::addSonar(int pins[][3], int length){
    for(int i=0;i < length; i++){
        Serial.println("Adding Sensor");
        anemoi.addSonar(pins[i][0], pins[i][1], pins[i][2]);
    }
}

void Zeus::addButton(int pins[], int length){
    for(int i=0; i < length; i++){
        Serial.println("Adding Button");
        anemoi.addButton(pins[i]);
    }
}

void Zeus::initAnemoi(){
    anemoi = Anemoi(); // set a new instance
}

void Zeus::initApollo(int pins[], int length){
    apollo = Apollo(pins, length);
}

void Zeus::initHermes(int pins[][2]) {
    for(int i=0; i < 4; i++){
        hermes.addMotor(pins[i][0], pins[i][1]);
    }
}


// Stop if we are too close to an object
void Zeus::collisionDetection(){
    int speed = hermes.getSpeed(0);
    if(anemoi.getSonarDistance(0) < COLLISIONDISTANCE){
        //too close to vehicle infront
        if(speed > 0){ // no need to call stop() if we are already stopped.
            hermes.stop();
        }
    }else if(speed == 0){
        hermes.moveForward(200);
    }  
}

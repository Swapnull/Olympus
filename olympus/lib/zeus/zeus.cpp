/* Zeus is the control system*/

#include <zeus.h>

#define COLLISIONDISTANCE 10 // in cm


Zeus::Zeus(){}

void Zeus::hermesSetup(int pins[][2]) {
    for(int i=0; i < 4; i++){
        hermes.addMotor(pins[i][0], pins[i][1]);
    }
}

void Zeus::apolloSetup(int pins[]){
    apollo = Apollo(pins);
}

void Zeus::anemoiSetup(int pins[][3], int length){
    for(int i=0;i < length ;i++){
        Serial.println("Adding Sensor");
        anemoi.addSensor(pins[i][0], pins[i][1], pins[i][2]);
    }
}

// Stop if we are too close to an object
void Zeus::collisionDetection(){
    int speed = hermes.getSpeed(0);
    if(anemoi.getDistanceCentimeters(0) < COLLISIONDISTANCE){
        //too close to vehicle infront
        if(speed > 0){ // no need to call stop() if we are already stopped.
            hermes.stop();
        }
    }else if(speed == 0){
        hermes.moveForward(200);
    }
    
}

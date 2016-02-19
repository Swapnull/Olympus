/* Zeus is the control system*/

#include <zeus.h>

#define COLLISIONDISTANCE 10 // in cm


Zeus::Zeus(){}

void Zeus::hermesSetup(int enablePin, int controlPin1, int controlPin2) {
    hermes.addMotor(enablePin, controlPin1, controlPin2);
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
    for(int i =0; i < hermes.getMotorCount(); i++){
        int speed = hermes.getSpeed(i);
        if(anemoi.getDistanceCentimeters(0) < COLLISIONDISTANCE){
            //too close to vehicle infront
            if(speed > 0){ // no need to call stop() if we are already stopped.
                hermes.stop(i);
            }
        }else if(speed == 0){
            hermes.moveForward(i , 200);
        }
    }


}

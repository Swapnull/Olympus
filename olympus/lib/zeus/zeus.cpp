/* Zeus is the control system*/

#include <zeus.h>

//Anemoi anemoi = Anemoi();


Zeus::Zeus(){
    Serial.println("Attaching Zeus");
}

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

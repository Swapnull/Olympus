/* Zeus is the control system*/

#include <zeus.h>

Hermes hermes = Hermes();
//Anemoi anemoi = Anemoi();


Zeus::Zeus(){
}

void Zeus::hermesSetup(int enablePin, int controlPin1, int controlPin2) {
    hermes.addMotor(enablePin, controlPin1, controlPin2);
    hermes.moveForward(0, 200);
}

void Zeus::apolloSetup(int pins[]){
    _apollo = Apollo(pins);
}

/*
void Zeus::anemoiSetup(int pins[][2]){
    for(int i=0;i < (sizeof(pins)/sizeof(pins[0])) ;i++){
        anemoi.addSensor(i, pins[i][0], pins[i][1]);
    }
}*/

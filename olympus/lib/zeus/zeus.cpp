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

void Zeus::anemoiSetup(int pins[][2]){
    int length = (sizeof(pins)/sizeof(pins[0]));
    Serial.println(length);
    for(int i=0;i < length ;i++){
        anemoi.addSensor(pins[i][0], pins[i][1]);
    }
}

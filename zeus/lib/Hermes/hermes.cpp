/* Hermes contolls the motors and steering */

#include "hermes.h"

Hermes::Hermes(){
    int _pins[4][3];
    int _id = 0;
}

void Hermes::addMotor(int enablePin, int controlPin1, int controlPin2){

    pinMode(enablePin, OUTPUT);
    pinMode(controlPin1, OUTPUT);
    pinMode(controlPin2, OUTPUT);

    _pins[_id][0] = enablePin;
    _pins[_id][1] = controlPin1;
    _pins[_id][2] = controlPin2;
}

void Hermes::setSpeed(int id, int speed){
    analogWrite(_pins[id][0], speed);
}

void Hermes::moveForward(int id, int speed){
    //set one high and one low due to motors facing inwards
    digitalWrite(_pins[id][1], HIGH);
    digitalWrite(_pins[id][2], LOW);

    setSpeed(id, speed);
}

void Hermes::moveBackward(int id, int speed){
    //set one high and one low due to motors facing inwards
    digitalWrite(_pins[id][1], LOW);
    digitalWrite(_pins[id][2], HIGH);

    setSpeed(id, speed);
}

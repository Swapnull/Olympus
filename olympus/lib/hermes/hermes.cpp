/* Hermes contolls the motors and steering */

#include "hermes.h"

Hermes::Hermes(Anemoi anemoi){
    _anemoi = anemoi;
}

void Hermes::addMotor(int enablePin, int controlPin1, int controlPin2){

    pinMode(enablePin, OUTPUT);
    pinMode(controlPin1, OUTPUT);
    pinMode(controlPin2, OUTPUT);

    _pins[_id][0] = enablePin;
    _pins[_id][1] = controlPin1;
    _pins[_id][2] = controlPin2;
    _pins[_id][3] = 0; //speed
}

void Hermes::setSpeed(int id, int speed){
    _pins[id][3] = speed;
    analogWrite(_pins[id][0], speed);
}

int Hermes::getSpeed(int id){
    return _pins[id][3];
}

int Hermes::getMotorCount(){
    return _id;
}

void Hermes::moveForward(int id, int speed){
    //set one high and one low due to motors facing inwards
    digitalWrite(_pins[id][1], HIGH);
    digitalWrite(_pins[id][2], LOW);

    setSpeed(id, speed);

    Serial.print("Motor ");
    Serial.print(id);
    Serial.print(" is moving forwards at ");
    Serial.println(speed);
}

void Hermes::moveBackward(int id, int speed){
    //set one high and one low due to motors facing inwards
    digitalWrite(_pins[id][1], LOW);
    digitalWrite(_pins[id][2], HIGH);

    setSpeed(id, speed);
}

void Hermes::stop(int id){
    Serial.println("Stopping!");
    setSpeed(id, 0);
}

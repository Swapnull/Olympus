/* Hermes contolls the motors and steering */

#include "hermes.h"


Hermes::Hermes(Anemoi anemoi){
    _anemoi = anemoi;
}

void Hermes::addMotor(int directionPin, int speedPin){

    pinMode(directionPin, OUTPUT);
    pinMode(speedPin, OUTPUT);

    _motors[_id][0] = directionPin;
    _motors[_id][1] = speedPin;
    _motors[_id][2] = 0; 
    _id++;
}

void Hermes::setSpeed(int speed){
    for(int i=0; i <= _id; i++){
        this->setSpeed(i, speed);
    }
}

void Hermes::setSpeed(int id, int speed){
    _motors[id][3] = speed;
    analogWrite(_motors[id][1], speed);
}

int Hermes::getSpeed(int id){
    return _motors[id][2];
}

int Hermes::getMotorCount(){
    return _id;
}

void Hermes::moveForward(int speed){
    //set two high and two low due to motors facing inwards

    for(int i=0; i <= _id; i++){
        if(i < 2){
            digitalWrite(_motors[i][0], HIGH);
        }else{
            digitalWrite(_motors[i][0], LOW);

        }
    }

    this->setSpeed(speed);

    Serial.print("Motors are moving forwards at ");
    Serial.println(speed);
}

void Hermes::moveBackward(int id, int speed){
    //set one high and one low due to motors facing inwards
    setSpeed(id, speed);
}

void Hermes::stop(){
    Serial.println("Stopping!");
    setSpeed(0);
}

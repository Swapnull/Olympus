/* Hermes contolls the motors and steering */

#include "hermes.h"

// constructor
Hermes::Hermes(Anemoi anemoi){
    _anemoi = anemoi;
}

// Add a motor
void Hermes::addMotor(int directionPin, int speedPin){

    pinMode(directionPin, OUTPUT);
    pinMode(speedPin, OUTPUT);

    _motors[_id][0] = directionPin;
    _motors[_id][1] = speedPin;
    _motors[_id][2] = 0; 
    _id++;
}

// gradually change the speed
void Hermes::changeSpeed(int currentSpeed, int targetSpeed){
    if(targetSpeed > currentSpeed){
        // need to speed up
        for(int i = currentSpeed; i < targetSpeed; i++){
            this->setSpeed(i);
        }
    }else{
        // need to slow down
        for(int i = currentSpeed; i > targetSpeed; i--){
            this->setSpeed(i);
        }
    }
}

// Returns the number of motors
int Hermes::getMotorCount(){
    return _id;
}

// Returns the speed of a particular motor or the first motor if no motor is provided. 
int Hermes::getSpeed(int id){
    return _motors[id][2];
}

// Accellerates forwards to desired speed
void Hermes::moveForward(int speed){
    //set two high and two low due to motors facing inwards

    for(int i=0; i <= _id; i++){
        if(i < 2){
            digitalWrite(_motors[i][0], HIGH);
        }else{
            digitalWrite(_motors[i][0], LOW);

        }
    }

    this->changeSpeed(this->getSpeed(), speed);   

    Serial.print("Motors are moving forwards at ");
    Serial.println(speed);
}

// Accellerates backwards to desired speed 
void Hermes::moveBackward(int speed){
    for(int i=0; i <= _id; i++){
        if(i < 2){
            digitalWrite(_motors[i][0], LOW);
        }else{
            digitalWrite(_motors[i][0], HIGH);

        }
    }

    this->changeSpeed(this->getSpeed(), speed);   


    Serial.print("Motors are moving backwards at ");
    Serial.println(speed);
}

// Sets the speed of all the motors
void Hermes::setSpeed(int speed){
    for(int i=0; i <= _id; i++){
        this->setSpeed(i, speed);
    }
}

// Sets the speed of one motor
void Hermes::setSpeed(int id, int speed){
    _motors[id][2] = speed;
    analogWrite(_motors[id][1], speed);
}

// Gradually stops the motors
void Hermes::stop(){
    Serial.println("Stopping");

    for(int i = this->getSpeed(); i > 0; i--){
            this->setSpeed(i);
    }

    Serial.println("Stopped");
}

// Turn left at current speed
void Hermes::turnLeft(){
    Serial.println("Turning Left");
   for(int i=0; i <= _id; i++){
        if(i % 2 == 1){
            digitalWrite(_motors[i][0], HIGH);
        }else{
            digitalWrite(_motors[i][0], LOW);

        }
    }
}

// Turn right at current speed
void Hermes::turnRight(){
    Serial.println("Turning Right");
   for(int i=0; i <= _id; i++){
        if(i % 2 == 1){
            digitalWrite(_motors[i][0], LOW);
        }else{
            digitalWrite(_motors[i][0], HIGH);

        }
    }
}
/* Hermes contolls the motors and steering */

#include "hermes.h"

// constructor
Hermes::Hermes(){
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

    if(targetSpeed > _maxSpeed){
        targetSpeed = _maxSpeed;
    }

    if(targetSpeed > currentSpeed){
        // need to speed up
        for(int i = currentSpeed; i < targetSpeed; i++){
            setSpeed(i);
        }
    }else{
        // need to slow down
        for(int i = currentSpeed; i > targetSpeed; i--){
            setSpeed(i);
        }
    }
}

// returns the number of motors
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
    Serial.println("moving forward");
    for(int i=0; i < _id; i++){
        if(i < 2){
            digitalWrite(_motors[i][0], HIGH);
        }else{
            digitalWrite(_motors[i][0], LOW);

        }
    }

    changeSpeed(getSpeed(), speed);   
}

// Accellerates backwards to desired speed 
void Hermes::moveBackward(int speed){
    for(int i=0; i < _id; i++){
        if(i < 2){
            digitalWrite(_motors[i][0], LOW);
        }else{
            digitalWrite(_motors[i][0], HIGH);

        }
    }

    changeSpeed(getSpeed(), speed);   
}

// Sets the speed of all the motors
void Hermes::setSpeed(int speed){
    for(int i=0; i < _id; i++){
        setSpeed(i, speed);
    }
}

// Sets the speed of one motor
void Hermes::setSpeed(int id, int speed){
    //ensure not faster than maxSpeed
    if(speed > _maxSpeed){
        speed = _maxSpeed;
    }
    //Serial.print("setting speed: "); Serial.println(speed);

    _motors[id][2] = speed;
    analogWrite(_motors[id][1], speed);
}

void Hermes::setLeftSpeed(int speed){
    digitalWrite(_motors[0][0], HIGH);
    digitalWrite(_motors[2][0], LOW);
    setSpeed(0, speed);
    setSpeed(2, speed);
}

void Hermes::setRightSpeed(int speed){
    digitalWrite(_motors[1][0], HIGH);
    digitalWrite(_motors[3][0], LOW);
    setSpeed(1, speed);
    setSpeed(3, speed);
}

void Hermes::setMaxSpeed(int maxSpeed){
    _maxSpeed = maxSpeed;
}

int Hermes::getMaxSpeed(){
    return _maxSpeed; 
}

// Gradually stops the motors
void Hermes::stop(){
    setSpeed(0);
}

// Turn left at current speed
void Hermes::turn(int direction, int angle, int speed){
    Serial.print("turning: ");
    Serial.println(angle);
    _angle = angle;

    for(int i=0; i < _id; i++){
        if(((i == 0 || i == 3) && direction == ANTICLOCKWISE) || ((i == 1 || i == 2) && direction == CLOCKWISE) ){
            digitalWrite(_motors[i][0], LOW);
        }else{
            digitalWrite(_motors[i][0], HIGH);
        }
    }

    turning = true;

    setSpeed(speed);
}

int Hermes::getAngleSteps(){
    //value of STEPSPER90 will need changing for every rig.
    return (_angle / 90) * STEPSPER90;
}
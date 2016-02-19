/* Anemoi is the Ultrasound class */

#include "Anemoi.h"

#define MAXDIST 200  // the maximum distance we will check for

// Initalize the class
Anemoi::Anemoi(){
}

// Adds a sensor to the array
void Anemoi::addSensor(int trig, int echo){
    // set the pin mode
    pinMode(trig, OUTPUT);
    pinMode(echo, INPUT);

    // add pins to array
    _pins[_id][0] = trig;
    _pins[_id][1] = echo;

    digitalWrite(trig, LOW); // clear the trig pin
    _id++; // increment the id
}


int Anemoi::ping(int id){
    int trig = _pins[id][0];
    int echo = _pins[id][1];

    // pings the trig pin
    digitalWrite(trig, HIGH);
    delay(10);
    digitalWrite(trig, LOW);

    return pulseIn(echo, HIGH);
}

// Returns distance in centimeters
int Anemoi::getDistanceCentimeters(int id){
	return (ping(id) * 0.034) / 2;  // distance = time * speed. We then divide by 2 as the wave must travel out and back.
}

/* Anemoi is the Ultrasound class */

#include "Anemoi.h"

#define MAXDIST 200  // the maximum distance we will check for

// Initalize the class
Anemoi::Anemoi(){
}

void Anemoi::addSensor(int trig, int echo, int maxdist){
    _sonar[_id] = NewPing(trig, echo, maxdist);
    _id++;
}

/* Returns distance in centimeters */
int Anemoi::getDistanceCentimeters(int id){
	return _sonar[id].ping_cm();
}

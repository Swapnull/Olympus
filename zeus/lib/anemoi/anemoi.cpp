/* Anemoi is the Ultrasound class that implements the NewPing library */

#include "Anemoi.h"

/* Initalize the class */
Anemoi::Anemoi(){
    // init the sonar with empty classes
    NewPing _sonar[4] = {NewPing(0, 0, 0), NewPing(0, 0, 0), NewPing(0, 0, 0), NewPing(0, 0, 0)};
    int _pins[4][3];
    int _id = 0;
}

/* Adds a sensor to the array */
void Anemoi::addSensor(int trig, int echo, int maxdist){
    _sonar[_id] = NewPing(trig, echo, maxdist);
    _id++;
}

/* Returns distance in centimeters */
int Anemoi::getDistanceCentimeters(int id){
	return _sonar[id].ping_cm();
}

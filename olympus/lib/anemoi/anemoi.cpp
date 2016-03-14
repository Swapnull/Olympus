/* Anemoi is the Ultrasound class */

#include "Anemoi.h"



// Add an ultrasonic sensor
Anemoi::Anemoi(int trig, int echo, int maxDist){
	pinMode(trig, OUTPUT);
	pinMode(echo, INPUT);

	_sonar = NewPing(trig, echo, maxDist);
}

int Anemoi::ping_cm(){
	return _sonar.ping_cm();
}
/* Apollo is the light system*/

#include "apollo.h"

Apollo::Apollo(int pins[]){
	//setup the lights
	int numOfPins = sizeof(pins)/sizeof(pins[0]);
	for(int i = 0; i < numOfPins ; i++){
		pinMode(pins[i], OUTPUT);
	}
}

void Apollo::turnOn(int pin){
	digitalWrite(pin, HIGH);
}

void Apollo::turnOff(int pin){
	digitalWrite(pin, LOW);
}

void Apollo::blink(int pin, int interval){
	digitalWrite(pin, HIGH);
	delay(interval);
	digitalWrite(pin, LOW);
}

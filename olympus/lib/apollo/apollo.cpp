/* Apollo is the light system*/

#include "apollo.h"

Apollo::Apollo(int pins[], int length){
	//setup the lights
	for(int i = 0; i < length ; i++){
		pinMode(pins[i], OUTPUT);
		this->turnOn(pins[i]);

		_pins[i] = pins[i];
	}

}

void Apollo::turnOn(int id){
	Serial.println(id);
	Serial.print("turning on pin ");
	Serial.println(_pins[0]);
	digitalWrite(_pins[id], HIGH);
}

void Apollo::turnOff(int id){
	digitalWrite(_pins[id], LOW);
}

void Apollo::blink(int id, int interval){
	digitalWrite(_pins[id], HIGH);
	delay(interval);
	digitalWrite(_pins[id], LOW);
}

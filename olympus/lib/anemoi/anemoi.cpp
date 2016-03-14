/* Anemoi is the Ultrasound class */

#include "Anemoi.h"

#define MAXDIST 200  // the maximum distance we will check for

// Initalize the class
Anemoi::Anemoi(){
}

// Add an ultrasonic sensor
void Anemoi::addSonar(int trig, int echo, int maxdist){
    _sonar[_sonarID] = NewPing(trig, echo, maxdist);
    _sonarID++;
}

// Add a button
void Anemoi::addButton(int pin){
	Serial.print("Pin in: ");
	Serial.println(pin);

	pinMode(pin, OUTPUT);

	this->_buttonPins[0] = pin;

	Serial.print("id: ");
	Serial.println(this->_buttonID);

	Serial.print("Buttons: ");
	Serial.println(this->_buttonPins[_buttonID]);
	_buttonID++;
}

// Returns distance in centimeters for sonar sensor
int Anemoi::getSonarDistance(int id){
	return _sonar[id].ping_cm();
}

// Wait for the button to be pressed. This will halt the program.
void Anemoi::waitForButton(int id){
	bool pressed = false, down = false;
	int state = 0;
	Serial.println("Waiting for button");
	Serial.println(_buttonPins[id]);
	while(!pressed){
		state = digitalRead(_buttonPins[id]);
		//Serial.println(state);
		if(state == HIGH){ // button has been pressed
			down = true; 
			Serial.println("button down");
		} else if (state == LOW && down){ // button has been released
			Serial.println("button pressed");
			pressed = true; // button has been pressed so break out. 
		}
	}
}

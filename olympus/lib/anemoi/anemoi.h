#include <Arduino.h>
#include <NewPing.h>

#ifndef __anemoi
#define __anemoi

class Anemoi{
	private:
		NewPing _sonar[4] = {NewPing(0, 0, 0), NewPing(0, 0, 0), NewPing(0, 0, 0), NewPing(0, 0, 0)};
		int _sonarID = 0;

		int _buttonPins[4] = {0, 0, 0, 0};
		int _buttonID = 0;

	public:
		//functions

		Anemoi();
        void addSonar(int trig, int echo, int maxdist);
        void addButton(int pin);
		int getSonarDistance(int id = 0); // assume there is only one if not specified
		void waitForButton(int id = 0); // assume there is only one if not specified
};

#endif

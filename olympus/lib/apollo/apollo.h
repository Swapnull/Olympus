#include <Arduino.h>

#ifndef __apollo
#define __apollo


class Apollo{
	private:
	public:
		//functions
		Apollo(int pins[]);
		void turnOn(int pin);
		void turnOff(int pin);
		void blink(int pin, int interval = 500);
};
#endif

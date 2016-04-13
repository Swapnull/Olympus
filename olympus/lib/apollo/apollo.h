#include <Arduino.h>

#ifndef __apollo
#define __apollo


class Apollo{
	private:
		int _pins[];
	public:
		//functions
		Apollo(int pins[], int length = 1);
		void turnOn(int id = 0);
		void turnOff(int id = 0);
		void blink(int id = 0, int interval = 500);
};
#endif

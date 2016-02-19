#include <Arduino.h>
#include <hermes.h>
#include <apollo.h>
#include <anemoi.h>


#ifndef __zeus
#define __zeus

class Zeus{
	public:
		Apollo apollo = NULL;
		Anemoi anemoi;
		Hermes hermes;
		Zeus();
        void hermesSetup(int enablePin, int controlPin1, int controlPin2);
        void apolloSetup(int pins[]);
		void anemoiSetup(int pins[][2]);
};
#endif

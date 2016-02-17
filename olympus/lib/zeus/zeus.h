#include <Arduino.h>
#include <hermes.h>
#include <apollo.h>
//#include <anemoi.h>


#ifndef __zeus
#define __zeus

class Zeus{
	public:
		Hermes hermes;
		Apollo apollo = NULL;
		Zeus();
        void hermesSetup(int enablePin, int controlPin1, int controlPin2);
        void apolloSetup(int pins[]);
		void anemoiSetup(int[][2]);
};
#endif

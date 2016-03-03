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
		Hermes hermes = Hermes(anemoi);
		Zeus();
        void hermesSetup(int pins[][2]);
        void apolloSetup(int pins[]);
		void anemoiSetup(int pins[][3], int length);
		void collisionDetection();
};
#endif

#include <Arduino.h>
#include <hermes.h>
#include <apollo.h>
#include <anemoi.h>

// constants to be used for accessing arrays
#define FRONT 0
#define RIGHT 1
#define BACK  2
#define LEFT  3

// constatnts to be used for wheels
#define BACKLEFT 0
#define BACKRIGHT 1
#define FRONTLEFT 2
#define FRONTRIGHT 3

#ifndef __zeus
#define __zeus

class Zeus{

	private:
		int _sonarCount = 0;
	public:
		Apollo apollo = NULL;
		Anemoi sonar[];
		Hermes hermes = Hermes();
		Zeus();
		//void addButton(int pins[], int length = 1);
		void addSonar(int trig, int echo, int maxDist = 200);
		void initApollo(int pins[], int length = 1);
        void initHermes(int pins[][2]);
		void wander();
};
#endif

#include <Arduino.h>
#include <hermes.h>
#include <apollo.h>
#include <anemoi.h>
#include <thea.h>

#ifndef __zeus
#define __zeus

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

// safe distance of sonars
#define SAFEDIST 10 
#define MAXRETRY 3

class Zeus{

	private:
		int _sonarCount = 0;
		int _direction = 0;
		uint32_t _lastBlockTime = 0;
	public:
		//Apollo apollo = NULL;
		//Anemoi sonar[];
		NewPing sonar[];
		Hermes hermes;
		Thea thea; 
		Zeus();
		//void addButton(int pins[], int length = 1);
		void addSonar(int trig, int echo, int maxDist = 200);
		void initApollo(int pins[], int length = 1);
        void initHermes(int pins[][2]);
        void runThea();
        bool isObstructed();
		void avoid();
		void wander(); 
};
#endif

#include <Arduino.h>
#include <NewPing.h>

#ifndef __anemoi
#define __anemoi

class Anemoi{
	private:
		int _trig = 0, _echo = 0, _maxDist = 0;
		NewPing _sonar = NewPing(_trig, _echo, _maxDist);


	public:
		//functions
        Anemoi(int trig, int echo, int maxDist = 200);
		int ping_cm(); // assume there is only one if not specified
};

#endif

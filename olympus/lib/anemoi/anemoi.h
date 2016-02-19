#include <Arduino.h>
#include <NewPing.h>

#ifndef __anemoi
#define __anemoi

class Anemoi{
	private:
		NewPing _sonar[4] = {NewPing(0, 0, 0), NewPing(0, 0, 0), NewPing(0, 0, 0), NewPing(0, 0, 0)};
        int _pins[][3]; // 2nd dimention is trig, echo, maxdist
		int _id = 0;
	public:
		//functions
		Anemoi();
        void addSensor(int, int, int);
		int getDistanceCentimeters(int);
};

#endif

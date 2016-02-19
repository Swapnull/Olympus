#include <Arduino.h>

#ifndef __anemoi
#define __anemoi

class Anemoi{
	private:
        int _pins[][2]; // 2nd dimention is trig, echo, maxdist
		int _id = 0;
	public:
		//functions
		Anemoi();
        void addSensor(int, int);
		int ping(int id);
		int getDistanceCentimeters(int);
};

#endif

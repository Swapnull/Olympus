#include <Arduino.h>

#ifndef __hermes
#define __hermes

class Hermes{
	private:
		int _pins[4][3];
        int _id = 0;
	public:
		//functions
		Hermes();
		void addMotor(int, int, int);
		void setSpeed(int, int);
        void moveForward(int, int);
        void moveBackward(int, int);
};
#endif

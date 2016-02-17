#include <Arduino.h>

#ifndef __hermes
#define __hermes

class Hermes{
	private:
		int _pins[4][3];
        int _id;
	public:
		//functions
		Hermes();
		void addMotor(int enablePin, int controlPin1, int controlPin2);
		void setSpeed(int id, int speed);
        void moveForward(int id, int speed);
        void moveBackward(int id, int speed);
};
#endif

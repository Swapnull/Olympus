#include <Arduino.h>
#include <Servo.h>

#ifndef __hermes
#define __hermes

class Hermes{
	private:
		int _pins[4][3];
        int _id;
		Servo _steering;
	public:
		//functions
		Hermes();
		void addMotor(int, int, int);
		void setSpeed(int, int);
        void moveForward(int, int);
        void moveBackward(int, int);
		void addServo(int);
		void turnLeft();
		void turnRight();
		void straight();
};
#endif

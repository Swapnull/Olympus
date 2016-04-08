#include <Arduino.h>

#ifndef __hermes
#define __hermes

#define CLOCKWISE 0
#define ANTICLOCKWISE 1
#define STEPSPER90 415 // will need changing for every rig.


class Hermes{
	private:
		int _motors[4][3];
        int _id = 0;
        int _maxSpeed = 200;
        int _angle = 0;

	public:
		volatile bool turning = false;
		volatile int steps = 0;
		//functions
		Hermes();
		void addMotor(int directionPin, int speedPin);
		void changeSpeed(int currentSpeed, int targetSpeed);
		int getSpeed(int id = 0);
		int getMotorCount();
        void moveForward(int speed);
        void moveBackward(int speed);
        void setSpeed(int speed);
		void setSpeed(int id, int speed);
		void setLeftSpeed(int speed);
		void setRightSpeed(int speed);
		void setMaxSpeed(int maxSpeed);
		int getMaxSpeed();
		void stop();
		void turn(int direction = 0, int angle = 90, int speed = 50);
		int getAngleSteps();

};
#endif

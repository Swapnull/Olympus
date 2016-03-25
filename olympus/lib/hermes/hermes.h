#include <Arduino.h>
#include <anemoi.h>

#ifndef __hermes
#define __hermes

#define CLOCKWISE 0
#define ANTICLOCKWISE 1


class Hermes{
	private:
		int _motors[4][3];
        int _id = 0;
	public:
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
		void stop();
		void turn(int direction = 0, int angle = 90, int speed = 50);
};
#endif

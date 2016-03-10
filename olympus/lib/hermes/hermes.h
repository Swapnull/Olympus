#include <Arduino.h>
#include <anemoi.h>

#ifndef __hermes
#define __hermes

class Hermes{
	private:
		int _motors[4][3];
        int _id = 0;
		Anemoi _anemoi;
	public:
		//functions
		Hermes(Anemoi anemoi);
		void addMotor(int directionPin, int speedPin);
		void changeSpeed(int currentSpeed, int targetSpeed);
		int getSpeed(int id = 0);
		int getMotorCount();
        void moveForward(int speed);
        void moveBackward(int speed);
        void setSpeed(int speed);
		void setSpeed(int id, int speed);
		void stop();
		void turnLeft();
		void turnRight();
};
#endif

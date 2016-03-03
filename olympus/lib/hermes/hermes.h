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
		void setSpeed(int speed);
		void setSpeed(int id, int speed);
		int getSpeed(int id);
		int getMotorCount();
        void moveForward(int speed);
        void moveBackward(int id, int speed);
		void stop();
};
#endif

#include <Arduino.h>
#include <anemoi.h>

#ifndef __hermes
#define __hermes

class Hermes{
	private:
		int _pins[4][4];
        int _id;
		Anemoi _anemoi;
	public:
		//functions
		Hermes(Anemoi anemoi);
		void addMotor(int enablePin, int controlPin1, int controlPin2);
		void setSpeed(int id, int speed);
		int getSpeed(int id);
		int getMotorCount();
        void moveForward(int id, int speed);
        void moveBackward(int id, int speed);
		void stop(int id);
};
#endif

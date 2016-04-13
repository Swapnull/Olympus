#include <Arduino.h>
#include <SPI.h>  
#include <Pixy.h>
#include "ServoLoop.h"

#ifndef __thea
#define __thea

class Thea{
	private:
		int oldX, oldY, oldSignature;
		int32_t _panError, _tiltError;
		uint16_t blocks;
	public:
		Pixy pixy;
		ServoLoop panLoop = ServoLoop(300, 500);  
		ServoLoop tiltLoop = ServoLoop(500, 700);

		Thea();
		void followBlocks();
		void scanForBlocks();
		void stop();

};
#endif

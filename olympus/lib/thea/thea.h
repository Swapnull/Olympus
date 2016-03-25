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

		Thea();
		void followBlocks();
		void scanForBlocks();

};
#endif

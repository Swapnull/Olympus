#include <Arduino.h>

#ifndef __ServoLoop
#define __ServoLoop

#define X_CENTER    	160L
#define Y_CENTER    	100L
#define RCS_MIN_POS     0L
#define RCS_MAX_POS     1000L
#define RCS_CENTER_POS  ((RCS_MAX_POS-RCS_MIN_POS)/2)

class ServoLoop{
	private:
		int _prevError, _propGain, _deriGain;
	public:
		int pos;
		ServoLoop(int propGain, int deriGain);
		void update(int32_t error);
};
#endif
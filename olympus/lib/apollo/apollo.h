#include <Arduino.h>

#ifndef __apollo
#define __apollo

class Apollo{
	private:
		int _pins[4][3];
        int _id;
	public:
		//functions
		Apollo();
		void addLight(int, int, int);
		void setColorRGB(int, int, int, int);
        void setColorText(int, String);
};
#endif

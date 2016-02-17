#include <Arduino.h>
#include <hermes.h>
#include <apollo.h>
//#include <anemoi.h>


#ifndef __zeus
#define __zeus

class Zeus{
	private:
		Apollo _apollo = NULL;
	public:
		//functions
		Zeus();
        void hermesSetup(int, int, int);
        void apolloSetup(int[]);
		void anemoiSetup(int[][2]);
};
#endif

#include <Arduino.h>
#include <hermes.h>
#include <apollo.h>
#include <anemoi.h>


#ifndef __zeus
#define __zeus

class Zeus{
	public:
		Apollo apollo = NULL;
		Anemoi anemoi;
		Hermes hermes = Hermes(anemoi);
		Zeus();
		void addButton(int pins[], int length = 1);
		void addSonar(int pins[][3], int length = 1);
		void initAnemoi();
		void initApollo(int pins[], int length = 1);
        void initHermes(int pins[][2]);
      
		
		void collisionDetection();
};
#endif

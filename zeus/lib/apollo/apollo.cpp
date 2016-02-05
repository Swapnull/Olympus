/* Apollo is the light system*/

#include "apollo.h"



Apollo::Apollo(){
    int _pins [4][3]; //[lightID][r/g/b] so [2][2] gets 3rd light blue pin.
    int _id = 0;
}

void Apollo::addLight(int red, int green, int blue){
    Serial.println(_id);
	// set the pins
	pinMode(red, OUTPUT);
	pinMode(green, OUTPUT);
	pinMode(blue, OUTPUT);

	// set private variables for pins
    _pins[_id][0] = red;
    _pins[_id][1] = green;
    _pins[_id][2] = blue;ex

    //increment the next one
    _id++;
}

void Apollo::setColor(int id, int red, int green, int blue){
	analogWrite(_pins[id][0], red);
	analogWrite(_pins[id][1], green);
	analogWrite(_pins[id][2], blue);
}

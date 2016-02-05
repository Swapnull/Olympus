/* Apollo is the light system*/

#include "apollo.h"



Apollo::Apollo(){
    int _pins [4][3]; //[lightID][r/g/b] so [2][2] gets 3rd light blue pin.
    int _id = 0;
}

void Apollo::addLight(int red, int green, int blue){
	// set the pins
	pinMode(red, OUTPUT);
	pinMode(green, OUTPUT);
	pinMode(blue, OUTPUT);

	// set private variables for pins
    _pins[_id][0] = red;
    _pins[_id][1] = green;
    _pins[_id][2] = blue;

    //increment the next one
    _id++;
}

/* Set color by RGB */
void Apollo::setColorRGB(int id, int red, int green, int blue){
	analogWrite(_pins[id][0], red);
	analogWrite(_pins[id][1], green);
	analogWrite(_pins[id][2], blue);
}

/* A helper class to set colors by text instead of RGB*/
void Apollo::setColorText(int id, String text){
    if(text == "white"){
        setColorRGB(id, 0, 0, 0);
    }else if(text == "red"){
        setColorRGB(id, 255, 0, 0);
    }else if(text == "yellow"){
        setColorRGB(id, 255, 255, 0);
    }else if(text == "orange"){
        setColorRGB(id, 255, 128, 0);
    }else if(text == "green"){
        setColorRGB(id, 0, 255, 0);
    }else if(text == "blue"){
        setColorRGB(id, 0, 0, 255);
    }else if(text == "purple"){
        setColorRGB(id, 255, 0, 255);
    }else{
        // Not a basic color
        Serial.println("Attempting to set a color by text that is not set. Try using setColorRGB instead");
    }
}

#include "apollo.h"

Apollo apollo = Apollo();

void setup()
{
    Serial.begin(9600);
    apollo.addLight(2, 3, 4);
    //apollo.addLight(4, 5, 6);

}

void loop()
{
    apollo.setColorRGB(0, 255, 0, 0);
    delay(500);
    apollo.setColorRGB(0, 0, 255, 0);
    delay(500);
    apollo.setColorRGB(0, 0, 0, 255);
    delay(500);
}

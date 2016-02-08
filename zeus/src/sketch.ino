#include "apollo.h"
#include "anemoi.h"
#include "hermes.h"


//Apollo apollo = Apollo();
Anemoi anemoi = Anemoi();
Hermes hermes = Hermes();

void setup()
{
    Serial.begin(9600);
    //apollo.addLight(2, 3, 4);
    anemoi.addSensor(2, 3, 200);
    hermes.addMotor(5, 6, 7);
}

void loop()
{
    Serial.println(anemoi.getDistanceCentimeters(0));
    /*apollo.setColorRGB(0, 255, 0, 0);
    delay(500);
    apollo.setColorRGB(0, 0, 255, 0);
    delay(500);
    apollo.setColorRGB(0, 0, 0, 255);
    delay(500);*/
}

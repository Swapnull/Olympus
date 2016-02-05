#include "apollo.h"

Apollo apollo = Apollo();

void setup()
{
    Serial.begin(9600);
    apollo.addLight(4, 5, 6);
    apollo.addLight(4, 5, 6);

}

void loop()
{
}

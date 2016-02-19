#include <zeus.h>
//#include <apollo.h>


//setup the control system
Zeus zeus = Zeus();

void setup()
{
    Serial.begin(9600);

    //int apolloPins[] = {5, 6, 7};
    //zeus.apolloSetup(apolloPins);
    //zeus.hermesSetup(7, 8, 9);

    //int anemoiPins[][2] = {{2,3}, {4,5}, {6, 7}, {8, 9}};
    Serial.println("setting up");

    int anemoiPins[][3] = {{12, 11, 200}};
    zeus.anemoiSetup(anemoiPins, 1);
}

void loop()
{
    int distance = zeus.anemoi.getDistanceCentimeters(0);
    Serial.print("distance: ");
    Serial.println(distance);
    delay(500);
}

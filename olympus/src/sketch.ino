#include <zeus.h>
//#include <apollo.h>


//setup the control system
Zeus zeus = Zeus();

void setup()
{
    Serial.begin(9600);

    int apolloPins[] = {5, 6, 7};
    zeus.apolloSetup(apolloPins);
    zeus.hermesSetup(7, 8, 9);

    //int anemoiPins[][2] = {{2,3}, {4,5}, {6, 7}, {8, 9}};
    //zeus.anemoiSetup(anemoiPins);
}

void loop()
{

}

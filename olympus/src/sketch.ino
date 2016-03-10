#include <zeus.h>
//#include <apollo.h>


//setup the control system
Zeus zeus;

void setup()
{
    Serial.begin(9600);

    //int apolloPins[] = {5, 6, 7};
    //zeus.apolloSetup(apolloPins);
    int motors[4][2] = {{25, 4}, {24, 5}, {23, 6}, {22, 7}};
    zeus.hermesSetup(motors);

    //int anemoiPins[][2] = {{2,3}, {4,5}, {6, 7}, {8, 9}};
    Serial.println("setting up");

    //int anemoiPins[][3] = {{12, 11, 200}};
    //zeus.anemoiSetup(anemoiPins, 1);
}

void loop()
{
 //   zeus.collisionDetection();
    zeus.hermes.moveForward(200);
    delay(5000);
    zeus.hermes.stop();
    delay(1000);
    zeus.hermes.moveBackward(100);
    delay(5000);
    zeus.hermes.stop();
    delay(1000);
}

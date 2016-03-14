#include <zeus.h>


//setup the control system
Zeus zeus;


void setup()
{
    Serial.begin(9600);

    //int apolloPins[] = {5, 6, 7};
    //zeus.apolloSetup(apolloPins);
    //int motors[4][2] = {{25, 4}, {24, 5}, {23, 6}, {22, 7}};
    //zeus.initHermes(motors);

    //int buttons[] = {40};
    //zeus.addButton(buttons);

    //int anemoiPins[][2] = {{2,3}, {4,5}, {6, 7}, {8, 9}};
    //Serial.println("setting up");

    int apolloPins[] = {46, 47, 48, 49, 50, 51};
    zeus.initApollo(apolloPins, 6);
    //zeus.apollo.turnOn(0);

    //int anemoiPins[][3] = {{12, 11, 200}};
    //zeus.anemoiSetup(anemoiPins, 1);
}

int id = 0;
void loop()
{


 //   zeus.collisionDetection();
    //zeus.anemoi.waitForButton(); // holds the program till button pressed

    /*Serial.println("Moving forward");
    zeus.hermes.moveForward(200);
    delay(5000);
    zeus.hermes.stop();*/

    /*Serial.println("Moving forward & turning left");
    zeus.hermes.moveForward(200);
    zeus.hermes.turnLeft();
    delay(5000);
    zeus.hermes.stop();
    delay(1000);*/

    /*Serial.println("Moving backward & turning right");
    zeus.hermes.moveBackward(100);
    zeus.hermes.turnRight();
    delay(5000);
    zeus.hermes.stop();
    delay(1000);*/

}

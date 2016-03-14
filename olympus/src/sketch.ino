#include <zeus.h>


//setup the control system
Zeus zeus;

void setup()
{
    Serial.begin(9600);
    
    //motors
    int motors[4][2] = {{25, 4}, {24, 5}, {23, 6}, {22, 7}};
    zeus.initHermes(motors);

    //sonar
    zeus.addSonar(8, 9);
    //Serial.println(zeus.sonar[FRONT].ping_cm()); 
    zeus.wander();

}

void loop()
{
}

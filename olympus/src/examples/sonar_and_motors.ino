#include <zeus.h>


//setup the control system
Zeus zeus;

void setup()
{
    Serial.begin(9600);
    
    //motors
    int motors[4][2] = {{25, 4}, {24, 5}, {23, 6}, {22, 7}};
    zeus.initHermes(motors);
    zeus.hermes.moveForward(200);

    //sonar
    zeus.addSonar(37, 36, 200);

}

void loop()
{
    Serial.println(zeus.sonar[FRONT].ping_cm());
    delay(500);
}

#include <zeus.h>


//setup the control system
Zeus zeus;

void setup()
{
    Serial.begin(9600);
    
    //motors
    //int motors[1][2] = {{25, 4}};//, {24, 5}, {23, 6}, {22, 7}};
    //zeus.initHermes(motors);
    //zeus.hermes.moveForward(200);


    //sonar
    //zeus.addSonar(8, 9, 200);
   // zeus.hermes.moveForward(200);
    //delay(500);
    //Serial.println(zeus.sonar[FRONT].ping_cm());

    /*zeus.hermes.turn(CLOCKWISE, 90, 50);
    delay(1000);
    zeus.hermes.turn(ANTICLOCKWISE, 90, 50);*/
    //zeus.hermes.stop();
    //zeus.hermes.moveForward(100);
    //zeus.avoid();

}

void loop()
{
    zeus.runThea();

    /*if(analogRead(4) > 500){
        zeus.hermes.moveForward(200);
    }else{
        zeus.hermes.stop();
    }*/

    //Serial.println(zeus.sonar[FRONT].ping_cm());
    //delay(1000);
    //zeus.hermes.moveForward(100);
    //zeus.avoid();
}

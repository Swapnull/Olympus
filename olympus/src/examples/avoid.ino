#include <zeus.h>


//setup the control system
Zeus zeus;

void setup()
{
    Serial.begin(9600);
    
    //motors
    int motors[4][2] = {{25, 8, 18}, {24, 9, 19}, {23, 10, 2}, {22, 11, 3}};
    zeus.initHermes(motors);

    //sonar
    zeus.addSonar(37, 36, 200);

}

void loop()
{
    if(analogRead(4) > 500){
        zeus.avoid();
        zeus.hermes.moveForward(50);
    }else{
        zeus.hermes.stop();
    }
        //Serial.println(zeus.sonar.ping_cm());
        //Serial.println("test");
        //zeus.hermes.moveBackward(200);
        //zeus.hermes.moveForward(200);

    //}
    delay(500);
}

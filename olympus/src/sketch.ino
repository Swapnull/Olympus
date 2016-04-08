#include <zeus.h>


//setup the control system
Zeus zeus;

void setup()
{
    Serial.begin(9600);
    
    //motors
    int motors[4][2] = {{25, 8}, {24, 9}, {23, 10}, {22, 11}};
    zeus.initHermes(motors);

    zeus.addSonar(37, 36, 200);

    attachInterrupt(digitalPinToInterrupt(2), turningInterrupt ,CHANGE);

}

void loop()
{
    //Serial.println(zeus.sonar.ping_cm());
    if(analogRead(4) > 500){
        zeus.wander();
    }else{
        zeus.hermes.stop();
    }
}

void turningInterrupt(){
   if(zeus.hermes.turning){
        if(zeus.hermes.steps % zeus.hermes.getAngleSteps() == 0){
            zeus.hermes.turning = false;
            zeus.hermes.stop();
        }
        zeus.hermes.steps++;
    }   
}

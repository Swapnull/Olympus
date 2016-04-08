#include <zeus.h>


//setup the control system
Zeus zeus;

void setup()
{
    Serial.begin(9600);
    
    //motors
    int motors[4][2] = {{25, 8}, {24, 9}, {23, 10}, {22, 11}};
    zeus.initHermes(motors);

    attachInterrupt(digitalPinToInterrupt(2), turningInterrupt, CHANGE);

}

void loop()
{
    if(analogRead(4) > 500){
        zeus.hermes.moveForward(200);
        delay(500);

        zeus.hermes.stop();
        delay(500);

        zeus.hermes.turn(CLOCKWISE, 90, 100);
        delay(3000);

        zeus.hermes.stop();
        delay(500);

        zeus.hermes.turn(ANTICLOCKWISE, 90, 100);
        delay(3000);

        zeus.hermes.stop();
        delay(500);

        zeus.hermes.moveBackward(200);
        delay(500);

        zeus.hermes.stop();
        delay(500);
    }else{
        zeus.hermes.stop();
    }
}

volatile int _steps = 0;

void turningInterrupt(){
   if(zeus.hermes.turning){
        if(zeus.hermes.steps % zeus.hermes.getAngleSteps() == 0){
            zeus.hermes.turning = false;
            zeus.hermes.stop();
        }
        zeus.hermes.steps++;
    }   
}

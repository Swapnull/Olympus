#include <zeus.h>


//setup the control system
Zeus zeus;

void setup()
{
    Serial.begin(9600);
    
    //motors
    int motors[4][2] = {{25, 8}, {24, 9}, {23, 10}, {22, 11}};
    zeus.initHermes(motors);

    attachInterrupt(digitalPinToInterrupt(2), turningInterrupt ,CHANGE);
    attachInterrupt(digitalPinToInterrupt(3), turningInterrupt ,CHANGE);
    attachInterrupt(digitalPinToInterrupt(18), turningInterrupt ,CHANGE);
    attachInterrupt(digitalPinToInterrupt(19), turningInterrupt ,CHANGE);

    //zeus.hermes.moveForward(200);


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
    delay(500);
}

volatile int _steps = 0;

void turningInterrupt(){
    Serial.print("steps: ");
    Serial.println(_steps);
    _steps++;

    if(_steps % 90 == 0){
        Serial.println("stop turning");
        zeus.hermes.stop();
    }else{
        zeus.hermes.turning = true;
    }
}

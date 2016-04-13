#include <zeus.h>


//setup the control system
Zeus zeus;

void setup()
{
    Serial.begin(9600);
    
    //motors
    int motors[4][2] = {{25, 4}, {24, 5}, {23, 6}, {22, 7}};
    zeus.initHermes(motors);
    zeus.hermes.setMaxSpeed(50);

    //sonar
    zeus.addSonar(37, 36, 200);


}

void loop()
{   
    if(analogRead(4) > 500){
        zeus.runThea();
        zeus.follow();
       // zeus.hermes.setLeftSpeed(200);
    }else{
        zeus.hermes.stop();
        zeus.thea.stop();
    }
}

/* Zeus is the control system*/

#include <zeus.h>

#define COLLISIONDISTANCE 10 // in cm


Zeus::Zeus(){}


void Zeus::addSonar(int trig, int echo, int maxDist){
    sonar[_sonarCount] = Anemoi(trig, echo, maxDist);   
    _sonarCount++;
}

void Zeus::initApollo(int pins[], int length){
    apollo = Apollo(pins, length);
}

void Zeus::initHermes(int pins[][2]) {
    for(int i=0; i < 4; i++){
        hermes.addMotor(pins[i][0], pins[i][1]);
    }
}

void Zeus::wander(){
    bool stuck = false;
    const int SAFEDIST = 10, MAXRETRY = 3, MAXSTUCK = 5;
    int pingDist = 0, total = 0, stuckCount = 0;

    while(!stuck){
        hermes.moveForward(200);
        pingDist = sonar[FRONT].ping_cm();
        while(pingDist <= SAFEDIST && pingDist > 0 ){
            // stop the motors            
            hermes.stop();

            // ping 3 more times, for accuracy.
            for(int i = 0; i < MAXRETRY; i++){
                total += sonar[FRONT].ping_cm();
                delay(500); 
            }

            // get an average of the 3 pings and check if its still below SAFEDIST
            if((total / 3) < SAFEDIST){
                //definitely an obstical, turn right to continue exploring
                hermes.moveForward(50);
                hermes.turnRight();
                delay(2500);
                hermes.stop();
                stuckCount++;
            }
            total = 0; // reset total counter

            if(stuckCount == MAXSTUCK){
                // if we have been stuck 5 times, assume we are not getting out and exit
                Serial.println("This bot is stuck and can no longer wander");
                stuck = true;
            }else{
                //not stuck so get the current reading.
                pingDist = sonar[FRONT].ping_cm();
            }
        }
        stuckCount = 0;
        delay(500);
    }
}
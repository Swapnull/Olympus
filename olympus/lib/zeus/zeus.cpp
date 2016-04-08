/* Zeus is the control system*/

#include <zeus.h>

#define COLLISIONDISTANCE 10 // in cm


Zeus::Zeus(){}


void Zeus::addSonar(int trig, int echo, int maxDist){
    sonar = NewPing(trig, echo, maxDist);   
}

/*void Zeus::initApollo(int pins[], int length){
    apollo = Apollo(pins, length);
}*/

void Zeus::runThea(){
   thea.followBlocks();
}

void Zeus::initHermes(int pins[][2]) {
    for(int i=0; i < 4; i++){
        hermes.addMotor(pins[i][0], pins[i][1]);
    }
}


bool Zeus::isObstructed(){
    int distance = sonar.ping_cm();

    return ((distance > 0) && (distance <= SAFEDIST));
}

bool Zeus::avoid(){
    bool wasObstructed = false;

    while(isObstructed()){

        wasObstructed = true;

        if(!hermes.turning){
            Serial.println(sonar.ping_cm());
            switch(_direction){
                case FRONT:
                    hermes.turn(CLOCKWISE, 90, 50); // turn to face right
                    _direction = RIGHT;
                    break;
                case RIGHT:
                    hermes.turn(ANTICLOCKWISE, 180, 50); // turn to face left
                    _direction = LEFT;
                    break;
                case LEFT :
                    hermes.turn(ANTICLOCKWISE, 90, 50); // turn to face back
                    _direction = BACK;
                    break;
                case BACK :
                    hermes.turn(ANTICLOCKWISE, 180, 50); // turn to face foward
                    _direction = FRONT;
                    break;
                default   :
                    Serial.println("There has been an error");
                    return false; 
            }
            delay(2000);
        }
    }
    _direction = FRONT; // whatever the new heading is, is now forward. 

    //return whether avoidance needed to happen
    return wasObstructed;
}

void Zeus::wander(){
    randomSeed(analogRead(6)); //shuffle the random number generator.

    unsigned int timeout = random(5)*1000;
    unsigned int timer = millis();
    bool contineWander = true;
    int turnAngle = 0;

    while(contineWander && analogRead(4) > 500){ //so potentiometer can stop movement
        if(!hermes.turning){ // dont do anything if a turn is happening
            if((millis() - timer) < timeout){
                //continue moving
                hermes.moveForward(100);

                //call avoid and if used, reset the timeout
                if(avoid()){
                    //reset
                    timeout = random(3, 7) * 1000;
                    timer = millis() ;
                }
           
            }else{
                turnAngle = random(45, 360);
                hermes.turn(CLOCKWISE, turnAngle, 100); //move a random angle at a random speed
                delay((turnAngle / 90) * 1000);

                timeout = random(3, 7) * 1000;
                timer = millis();
            }
        }
    }
} 

void Zeus::follow(){
    int32_t size = 200;
    int32_t followError = RCS_CENTER_POS - thea.panLoop.pos;  // How far off-center are we looking now?
    int maxSpeed = hermes.getMaxSpeed();

    // Size is the area of the object.
    // We keep a running average of the last 8.
    if(thea.pixy.getBlocks() && !isObstructed()){
        size += thea.pixy.blocks[0].width * thea.pixy.blocks[0].height; 
        size -= size >> 3;

        int forwardSpeed = constrain(maxSpeed - (size/256), -100, maxSpeed);
        int32_t differential = (followError + (followError * forwardSpeed))>>8;

     
        // Adjust the left and right speeds by the steering differential.
        int leftSpeed = abs(constrain(forwardSpeed + differential, -maxSpeed, maxSpeed));
        int rightSpeed = abs(constrain(forwardSpeed - differential, -maxSpeed, maxSpeed));

        Serial.print(leftSpeed);
        Serial.print(" ");
        Serial.println(rightSpeed);
        
        hermes.setLeftSpeed(leftSpeed);
        hermes.setRightSpeed(rightSpeed);
    }

}
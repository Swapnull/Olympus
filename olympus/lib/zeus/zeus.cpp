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
    Serial.println(distance);
    return ((distance >= 0) && (distance <= SAFEDIST));
}

void Zeus::avoid(){
    bool obstructed = isObstructed();

    while(obstructed){
        //hermes.moveForward(200);
        obstructed = isObstructed();
        // stop the motors            
        hermes.stop();

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
                return; 
        }
    }
    _direction = FRONT; // whatever the new heading is, is now forward. 
}

void Zeus::wander(){
    unsigned int timeout = random(15)*1000;
    unsigned int timer = millis();

    while((millis() - timer) < timeout){
        if(isObstructed()){
            avoid();
        }
    }

    //once timeout has completed, run code
    delay(random(15)*1000); // delay a random time between 0 and 15 seconds
    hermes.turn(CLOCKWISE, random(360), random(100)); //move a random angle at a random speed
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
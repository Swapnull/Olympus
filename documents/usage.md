# Usage

### Anemoi (Direction)
Anemoi is the class that gives us some direction using ultrasound.

##### *Basic usage*
Get the distance every 1 second.
``` cpp

#include "anemoi.h"

// Create pointer to Anemoi object
Anemoi* anemoi;

void setup(){
    // Open serial port for printing
    Serial.begin(9600);

    // Initialize Anemoi object where trig pin is 5, echo pin is 4, max distance is 200.
    anemoi = new Anemoi(5, 4, 200);
}

void loop(){
    // Get distance in cm and print it
    Serial.print(anemoi->getDistance()); // Use -> due to pointer
    Serial.println(" cm");

    // Wait 1 second before repeat
    delay(1000);
}

```

# Self Driving Car
This is a self driving car project that I will be undertaking for my final year project. It will use a microprocessor (Arduino) and single-board computer (Parallella) to control a base that I will build.

### Hardware used
- *Arduino Uno* - The basic version of the Arudino micro-controller board, a lot of the early development was done on these.
- *Arduino Due* - The largest version of the Arduino micro-controller board. Most of the later development was done using one of these.
- *HC-SR04 Ultrasonic Sensors* - The main sensing component that the prototype uses.
- *XBee v1.0 w/Sheild and Explorer* - The controller that allowed the Arduino to wirelessly speak to other devices, primarily, a laptop. 

### Software used
- *[Atom](https://github.com/atom/atom)* - A hackable text editor built by Github.
- *[PlatformIO](https://github.com/platformio/platformio)* - An open source ecosystem for IoT development. This is the build system that was used to build the source file needed. This is recommended due to been the only non-Arduino software that can compile and run on a Due reliably.
- <s>*[Arturo](https://github.com/scottdarch/Arturo)* - An extended version of amperka/ino, a build tool for Arduino projects in the command line.</s>

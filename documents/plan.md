# Plan
This document contains a more fleshed out plan than my spec. It should contain more technical information than the spec does.

## Overview
This project will contain 4 main projects
- _Collector:_
- _Processor:_
- _Front End:_
- _Hardware:_

## Sending Data
I will be sending data between the collector and processor using JSON. I will build a JSON object of sensor data on the arduino using something like [aJSON](https://github.com/interactive-matter/ajson) that will allow me to send just one object to the processor. The processor will then read this JSON object and process the data it has recieved. The processor will then build a JSON object of actions and send this to the collector. 

The front end is code that the user will be able to interact with. It will call the collector API to interact with the collector and processor and do most of the work. The front ends mainjob is to link the hardware to the collector.

## Feature List

### Movement 
### Distance Sensors
### Camera
### Lights




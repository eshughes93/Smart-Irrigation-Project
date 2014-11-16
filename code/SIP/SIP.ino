
/*
This file is using some preprocessor tricks to only compile/use the 
right combination of code for the desired Arduino. This could be split 
up into two different files, but we wanted to keep all the arduino 
code for this project in one directory. (And there can only be one 
.ino file which interfaces with the arduino per directory... )

Due to some limitations of the Arduino environment, all libraries that 
will be used need to be included in this file. Yes, even if it isn't 
used in this file. Kind of silly, but oh well. 

This file should be left very simple! Anything not having to do with 
include statements should be put into the sensor_arduino.cpp or 
water_sensor.cpp files.

For those who don't know, preprocessor commands are executed before code 
is compiled. I am using it to limit what will be compiled to ensure the 
Arduino is only getting what it needs. Variables (macros) essentially 
copy and paste code. Control flow statements turn off and on code, in 
a similar fasion to commenting out code. 

To use:
  For the sensor arduino:
    1 Plug in the Arduino that will be reading moisture data
    2 Set the preprocessor variable USING to SENSOR_ARDUINO

  For the water ardunio:
    1 Plug in the Arduino that will control the water
    2 Set the preprocessor variable USING to WATER_ARDUINO
*/
#define SENSOR_ARDUINO 0
#define  WATER_ARDUINO 1

// Preprocessor control for the type of arduino.
#define USING SENSOR_ARDUINO


// Include common libraries that will be used. 
#include <Arduino.h>
#include "generic_data_stream.h"
#include "data_streams.h"
#include "generic_communication_controller.h"
#include "serial_controller.h" // specific communication controller

// Code specific to each type of Arduino.
#if USING == SENSOR_ARDUINO
  // Include libraries specific to the sensor Arduino
  #include "sensor_arduino.cpp"
  #include "generic_moisture_sensor.h"

  // Include the specific moisture sensor that will be used. Don't forget 
  // to change the include in sensor_arduino.cpp if you change this one!
  // Current options are:
  //   test_sensor.h, slht5_adafruit_sensor.h
  //#include "test_sensor.h"
  #include <SHT1x.h>
  #include "slht5_adafruit_sensor.h"

  // Set the Arduino class that will be used.
  #define ARDUINO_CLASS SensorArduino

#elif USING == WATER_ARDUINO
  // Include libraries specific to the water Arduino
  #include "water_arduino.cpp"
  #include "generic_water_controller.h"
  #include "water_controllers.h"

  // Set the Arduino class that will be used.
  #define ARDUINO_CLASS WaterArduino
#endif  


// Provide the normal functions.

ARDUINO_CLASS* arduino;
void setup(){ arduino =  new ARDUINO_CLASS(); }
void loop(){ arduino->loop(); }


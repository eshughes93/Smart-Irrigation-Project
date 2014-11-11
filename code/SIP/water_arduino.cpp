// Smart Irrigation Project
// cmps 115 Fall 2014

#include <Arduino.h>

#include <generic_water_controller.h>
#include <water_controllers.h>



class WaterArduino {
  // Arduino variables
  int SLEEP_TIME; // 1 seconds
  int TESTING_PIN; // For testing... Light up the pin 13 blue LED

  // Components
  WaterController* water_controller;
  //... etc.

  WaterArduino(){
   SLEEP_TIME = 1000; // 1 seconds
   TESTING_PIN = 13; // For testing... Light up the pin 13 blue LED

    // Initialize the components of SIP
    water_controller = new TestWaterController(TESTING_PIN);
    // new solar controller? wifi_controller? etc.
  
  }

  void loop(){
    // Update the components if necessary.
    // Water the plants if the ground is too dry.
    // For testing purposes:
    // Double blink if the potentiometer reads higher values.
    // Single blink if it reads lower values

    // Somehow check the communication controller to see if watering is necessary!
    water_controller->water_plants();

    delay(SLEEP_TIME);
  }
};

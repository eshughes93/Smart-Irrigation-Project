#include <data_streams.h>
#include <generic_data_stream.h>

#include <generic_moisture_sensor.h>
#include <moisture_sensors.h>

// Smart Irrigation Project
// cmps 115 Fall 2014

#include "generic_moisture_sensor.h"
#include "moisture_sensors.h"

class SensorArduino {
  // Arduino variables
  int SLEEP_TIME = 1000; // 1 seconds
  const int TESTING_PIN = 13; // For testing... Light up the pin 13 blue LED

  // Components
  MoistureSensor* moisture_sensor;
  //... etc.

  void setup(){
    // Initialize the components of SIP
    moisture_sensor = new TestSensor(MOISTURE_SENSOR_PIN);
    // new solar controller? wifi_controller? etc.
  
  }

  void loop(){
    // Update the components if necessary.
    moisture_sensor->update();
  
    // Water the plants if the ground is too dry.
    // For testing purposes:
    // Double blink if the potentiometer reads higher values.
    // Single blink if it reads lower values
    if (moisture_sensor->is_dry()){
      water_controller->water_plants();
    }

    delay(SLEEP_TIME);
  }
};
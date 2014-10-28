// Smart Irrigation Project
// cmps 115 Fall 2014

#include "moisture_sensor.h"

// Arduino variables
const int MOISTURE_SENSOR_PIN = 0;
int SLEEP_TIME = 5000; // 5 seconds
const int TESTING_PIN = 13; // For testing... Light up the pin 13 blue LED

// Components
MoistureSensor* moisture_sensor;
// WaterController* water_controller... etc.

void setup(){
  // Initialize the components of SIP
  moisture_sensor = new MoistureSensor(MOISTURE_SENSOR_PIN);
  // new WaterController...
  // new solar controller? wifi_controller? etc.
  
  // Testing... Light up the pin 13 blue LED
  pinMode(TESTING_PIN, OUTPUT);
}

void loop(){
  // Update the components if necessary.
  moisture_sensor->update();
  
  // Water the plants if the ground is too dry.
  // For testing purposes:
  // Double blink if the potentiometer reads higher values.
  // Single blink if it reads lower values
  if (moisture_sensor->is_dry()){
    // release water!
  
    // Testing...
    digitalWrite(TESTING_PIN, HIGH);
    delay(100);
    digitalWrite(TESTING_PIN, LOW);
    delay(100);
    digitalWrite(TESTING_PIN, HIGH);
    delay(100);
    digitalWrite(TESTING_PIN, LOW);
  } else {
    // Testing...
    digitalWrite(TESTING_PIN, HIGH);
    delay(100);
    digitalWrite(TESTING_PIN, LOW);
  } 

  delay(SLEEP_TIME);
}

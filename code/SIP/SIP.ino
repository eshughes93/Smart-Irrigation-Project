#include "sensor_arduino.cpp"
//#include "water_arduino.cpp"
#include "moisture_sensors.h"
#include "water_controllers.h"

Sensor_Arduino* arduino_sensor;

void setup(){
  //Initialize the WaterSensor and ArduinoSensor
  //WaterSensor water_sensor = new WaterSensor();
  arduino_sensor =  new Sensor_Arduino();
}


void loop(){
  //water_sensor->loop();
  arduino_sensor->loop();
}




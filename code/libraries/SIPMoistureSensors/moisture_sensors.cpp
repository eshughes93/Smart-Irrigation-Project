#include <Arduino.h>
#include "moisture_sensors.h"
#include "generic_moisture_sensor.h"

/*** TestSensor functions ***/
TestSensor::TestSensor(int input_pin) : MoistureSensor(input_pin) {
}

void TestSensor::update() {
  // Do any required updating for the sensor. This will only be called 
  // once per loop.
	
  // Read in data from the sensor
  int new_data = analogRead(m_pin);

  // Add data to the data array
  if (m_data_count < m_max_data_count) {
    m_data[m_data_count] = new_data;
    m_data_count++;
  } else {
    // Data overflow... Ignore new data? Forget old data?
  }
}

boolean TestSensor::is_dry(){
  // Check the last moisture reading to see if the ground is too dry.
  // Return true if the soil is too dry and needs water.
  // Return false if the soil has enough water.
  //
  // Assumes that the update function was called recently. analogRead() 
  // is not called here to ensure data is collected at uniform 
  // intervals.

  // Do some actual calculations... the following code is for testing with a potentiometer.
  int last_data = m_data[m_data_count - 1];
  if (last_data < 512) {
    return true;
  } else {
    return false;
  }
}



/*** WatermarkSensor functions ***/
WatermarkSensor::WatermarkSensor(int input_pin) : MoistureSensor(input_pin){
}

void WatermarkSensor::update() {
}

boolean WatermarkSensor::is_dry(){
}
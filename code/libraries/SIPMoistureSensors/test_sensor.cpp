#include <Arduino.h>
#include "test_sensor.h"
#include "generic_moisture_sensor.h"
#include "../SIPDataStreams/generic_data_stream.h"
#include "../SIPDataStreams/data_streams.h"

/*** TestSensor functions ***/
TestSensor::TestSensor(int input_pin) : MoistureSensor() {
	m_pin = input_pin;
  m_data = new ArrayDataStream<float>(m_max_data_count);
	m_potentiometer_max = 1023.0;
}

void TestSensor::update() {
  // Do any required updating for the sensor. This will only be called 
  // once per loop.
  
  // Read in data from the sensor
  int new_data = analogRead(m_pin);
	float ratio = new_data / m_potentiometer_max;
  m_data->add_data(ratio);
}

boolean TestSensor::is_dry(){
  // Check the last moisture reading to see if the ground is too dry.
  // Return true if the soil is too dry and needs water.
  // Return false if the soil has enough water.
  //
  // Assumes that the update function was called recently. analogRead() 
  // is not called here to ensure data is collected at uniform 
  // intervals.

	// Do some actual calculations... For testing purposes, if it is 
	// greater than 50%, then it is dry.
  float last_data = m_data->get_last_data();
  if (last_data > 0.5 ) {
    return true;
  } else {
    return false;
  }
}

float TestSensor::get_saturation() {
	return m_data->get_last_data();
}

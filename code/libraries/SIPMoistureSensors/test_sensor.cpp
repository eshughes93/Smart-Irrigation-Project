#include <Arduino.h>
#include "test_sensor.h"
#include "generic_moisture_sensor.h"
#include "../SIPDataStreams/generic_data_stream.h"
#include "../SIPDataStreams/array_data_stream.h"

/*** TestSensor functions ***/
TestSensor::TestSensor(int data_count, int input_pin) : MoistureSensor(data_count) {
  m_pin = input_pin;
  m_data = new ArrayDataStream<float>(m_max_data_count);
  m_potentiometer_max = 1023.0;
}

void TestSensor::update() {
  // Do any required updating for the sensor. This will only be called 
  // once per loop.
  
  // Read in data from the sensor
  int new_data = analogRead(m_pin);
  float percent = 100.0 * new_data / m_potentiometer_max;
  float old_datum = m_data->add_data(percent);
  // old_datum is a float, don't need to delete
}

float TestSensor::get_saturation() {
  return m_data->get_last_data();
}

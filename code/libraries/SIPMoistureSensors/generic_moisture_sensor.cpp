#include <Arduino.h>
#include "generic_moisture_sensor.h"

MoistureSensor::MoistureSensor(int input_pin) {
  m_pin = input_pin;
  m_max_data_count = 100;
  m_data_count = 0;
  m_data = new int[m_max_data_count]; // Create the data array
}

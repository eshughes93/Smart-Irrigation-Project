#include <Arduino.h>
#include "generic_moisture_sensor.h"

MoistureSensor::MoistureSensor(int data_count) {
  m_max_data_count = data_count;
}

#include <Arduino.h>
#include <SHT1x.h>
#include "slht5_adafruit_sensor.h"
#include "generic_moisture_sensor.h"
#include "../SIPDataStreams/generic_data_stream.h"
#include "../SIPDataStreams/array_data_stream.h"
#include "../SIPDataStreams/stt_data_point.h"

// Define the data point variable types. Make sure it matches in the 
// slht5_adafruit_sensor.h file
typedef float SaturationType;
typedef float TemperatureType;
typedef time_t TimestampType;
#define STT_DATA_POINT STTDataPoint<SaturationType, TemperatureType, TimestampType>

/*** SLHT5Sensor functions ***/
SLHT5Sensor::SLHT5Sensor(int data_count, int data_pin, int clock_pin) : MoistureSensor(data_count) {
  m_data_pin = data_pin;
  m_clock_pin = clock_pin;
  m_data = new ArrayDataStream<STT_DATA_POINT*>(m_max_data_count);

  for (int i=0;  i<m_max_data_count; i++){
    STT_DATA_POINT* new_datum = new STT_DATA_POINT(i, i, i);
    m_data->add_data(new_datum);
  }

  m_sensor = new SHT1x(data_pin, clock_pin);
}

void SLHT5Sensor::update() {
  // Do any required updating for the sensor. This will only be called 
  // once per loop.
  
  // Read in data from the sensor
  SaturationType saturation = m_sensor->readHumidity();
  TemperatureType temperature = m_sensor->readTemperatureF();
  TimestampType timestamp = 0;

  STT_DATA_POINT* data_point = m_data->manually_update_next();
  data_point->set_saturation(saturation);
  data_point->set_temperature(temperature);
  data_point->set_timestamp(timestamp);
}

SaturationType SLHT5Sensor::get_saturation() {
  return m_data->get_last_data()->get_saturation();
}

TemperatureType SLHT5Sensor::get_temperature() {
  return m_data->get_last_data()->get_temperature();
}


TimestampType SLHT5Sensor::get_timestamp() {
  return m_data->get_last_data()->get_timestamp();
}


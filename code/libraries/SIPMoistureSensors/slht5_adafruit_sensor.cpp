#include <Arduino.h>
#include <SHT1x.h>
#include "slht5_adafruit_sensor.h"
#include "generic_moisture_sensor.h"
#include "../SIPDataStreams/generic_data_stream.h"
#include "../SIPDataStreams/array_data_stream.h"

// Define the data point variable types. Make sure it matches in the 
// slht5_adafruit_sensor.h file
typedef float SaturationType;
typedef float TemperatureType;
//typedef char TimestampType;


/*** SLHT5Sensor functions ***/
SLHT5Sensor::SLHT5Sensor(int data_pin, int clock_pin) : MoistureSensor() {
  m_data_pin = data_pin;
  m_clock_pin = clock_pin;
  m_saturation = new ArrayDataStream<SaturationType>(m_max_data_count);
  m_temperature = new ArrayDataStream<TemperatureType>(m_max_data_count);
	//m_timestamp = new ArrayDataStream<TimestampType>(m_max_data_count);
  m_sensor = new SHT1x(data_pin, clock_pin);
}

void SLHT5Sensor::update() {
  // Do any required updating for the sensor. This will only be called 
  // once per loop.
  
  // Read in data from the sensor
  SaturationType saturation = m_sensor->readHumidity();
  TemperatureType temperature = m_sensor->readTemperatureF();
	//TimestampType timestamp = '?';

  m_saturation->add_data(saturation);
	m_temperature->add_data(temperature);
	//m_timestamp->add_data(timestamp);
}

SaturationType SLHT5Sensor::get_saturation() {
	return m_saturation->get_last_data();
}

TemperatureType SLHT5Sensor::get_temperature() {
	return m_temperature->get_last_data();
}

/*
TimestampType SLHT5Sensor::get_timestamp() {
  return m_timestamp->get_last_data();
}
*/

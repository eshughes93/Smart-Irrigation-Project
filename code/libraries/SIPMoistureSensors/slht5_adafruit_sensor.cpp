#include <Arduino.h>
#include <SHT1x.h>
#include "slht5_adafruit_sensor.h"
#include "generic_moisture_sensor.h"
#include "../SIPDataStreams/generic_data_stream.h"
#include "../SIPDataStreams/data_streams.h"

/*** SLHT5Sensor functions ***/
SLHT5Sensor::SLHT5Sensor(int data_pin, int clock_pin) : MoistureSensor() {
	m_data_pin = data_pin;
	m_clock_pin = clock_pin;
  m_data = new ArrayDataStream<float>(m_max_data_count);
	m_sensor = new SHT1x(data_pin, clock_pin);
}

void SLHT5Sensor::update() {
  // Do any required updating for the sensor. This will only be called 
  // once per loop.
  
  // Read in data from the sensor
  float new_data = m_sensor->readHumidity();

  m_data->add_data(new_data);
}

float SLHT5Sensor::get_saturation() {
	return m_data->get_last_data();
}

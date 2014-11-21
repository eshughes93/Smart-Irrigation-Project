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
typedef char TimestampType;
#define STT_DATA_POINT STTDataPoint<SaturationType, TemperatureType, TimestampType>


/*** SLHT5Sensor functions ***/
SLHT5Sensor::SLHT5Sensor(int data_pin, int clock_pin) : MoistureSensor() {
	m_data_pin = data_pin;
	m_clock_pin = clock_pin;
  m_data = new ArrayDataStream<STT_DATA_POINT*>(m_max_data_count);
	m_sensor = new SHT1x(data_pin, clock_pin);
}

void SLHT5Sensor::update() {
  // Do any required updating for the sensor. This will only be called 
  // once per loop.
  
  // Read in data from the sensor
  float saturation = m_sensor->readHumidity();
  float temperature = m_sensor->readTemperatureF();
  char timestamp = '?';

	STT_DATA_POINT* new_datum = new STT_DATA_POINT(saturation,
																								temperature,
																								timestamp);

	// Add it to the data stream
  STT_DATA_POINT* old_datum = m_data->add_data(new_datum);

	// The old datum is a pointer. It needs to be deleted.
	delete old_datum;
}

SaturationType SLHT5Sensor::get_saturation() {
	STT_DATA_POINT* datum = m_data->get_last_data();
	return datum->get_saturation();
}

TemperatureType SLHT5Sensor::get_temperature() {
	STT_DATA_POINT* datum = m_data->get_last_data();
	return datum->get_temperature();
}

TimestampType SLHT5Sensor::get_timestamp() {
	STT_DATA_POINT* datum = m_data->get_last_data();
	return datum->get_timestamp();
}

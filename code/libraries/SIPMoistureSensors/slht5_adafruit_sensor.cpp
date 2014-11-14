#include <Arduino.h>
#include "slht5_adafruit_sensor.h"
#include "generic_moisture_sensor.h"
#include "../SIPDataStreams/generic_data_stream.h"
#include "../SIPDataStreams/data_streams.h"

/*** SLHT5Sensor functions ***/
SLHT5Sensor::SLHT5Sensor(int input_pin) : MoistureSensor() {
  m_data = new ArrayDataStream<float>(m_max_data_count);
}

void SLHT5Sensor::update() {
  // Do any required updating for the sensor. This will only be called 
  // once per loop.
  
  // Read in data from the sensor
  int new_data = analogRead(m_pin);

  m_data->add_data(float(new_data));
}

boolean SLHT5Sensor::is_dry(){
  // Check the last moisture reading to see if the ground is too dry.
  // Return true if the soil is too dry and needs water.
  // Return false if the soil has enough water.
  //
  // Assumes that the update function was called recently. analogRead() 
  // is not called here to ensure data is collected at uniform 
  // intervals.

  // Do some actual calculations... the following code is for testing with a potentiometer.
  float last_data = m_data->get_last_data();
  if (last_data < 512) {
    return true;
  } else {
    return false;
  }
}


#include <Arduino.h>
#include "watermark_sensor.h"
#include "generic_moisture_sensor.h"
#include "../SIPDataStreams/generic_data_stream.h"
#include "../SIPDataStreams/array_data_stream.h"

/*
 * This class was intended to interface with the Watermark soil 
 * moisture sensor. However, we were not able to find satisfactory 
 * documentation and could not implement it. This class is currently an 
 * empty, outdated shell of a class.
 *
 */


/*** WatermarkSensor functions ***/
WatermarkSensor::WatermarkSensor(int data_count, int input_pin) : MoistureSensor(data_count){
}

void WatermarkSensor::update() {
}

float WatermarkSensor::get_saturation() {
  return 0.0;
}

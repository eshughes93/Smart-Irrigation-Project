#include <Arduino.h>
#include "watermark_sensor.h"
#include "generic_moisture_sensor.h"
#include "../SIPDataStreams/generic_data_stream.h"
#include "../SIPDataStreams/array_data_stream.h"

/*** WatermarkSensor functions ***/
WatermarkSensor::WatermarkSensor(int input_pin) : MoistureSensor(){
}

void WatermarkSensor::update() {
}

float WatermarkSensor::get_saturation() {
	return 0.0;
}

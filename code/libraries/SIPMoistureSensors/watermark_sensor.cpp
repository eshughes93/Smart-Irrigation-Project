#include <Arduino.h>
#include "watermark_sensor.h"
#include "generic_moisture_sensor.h"
#include "../SIPDataStreams/generic_data_stream.h"
#include "../SIPDataStreams/data_streams.h"

/*** WatermarkSensor functions ***/
WatermarkSensor::WatermarkSensor(int input_pin) : MoistureSensor(){
}

void WatermarkSensor::update() {
}

boolean WatermarkSensor::is_dry(){
}

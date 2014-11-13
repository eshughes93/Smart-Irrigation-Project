#ifndef MOISTURE_SENSORS_H
#define MOISTURE_SENSORS_H

#include <Arduino.h>
#include "generic_moisture_sensor.h"
#include "../SIPDataStreams/generic_data_stream.h"
#include "../SIPDataStreams/data_streams.h"

class TestSensor : public MoistureSensor{
  // A test class assuming a simple analog sensor.
  private:
    int m_pin; // Arduino pin number.
    DataStream<float>* m_data;
  
  public:
    TestSensor(int input_pin);
    void update();
    boolean is_dry();
};

class WatermarkSensor : public MoistureSensor{
  // Controls the Watermark Sensor (Gypsum block).

  private:
    DataStream<float>* m_data;
  
  public:
    WatermarkSensor(int input_pin);
    void update();
    boolean is_dry();
};

#endif

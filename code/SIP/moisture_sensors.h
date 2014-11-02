#ifndef MOISTURE_SENSORS_H
#define MOISTURE_SENSORS_H

#include <Arduino.h>
#include "generic_sensor.h"

class TestSensor : public MoistureSensor{
  // A test class assuming a simple analog sensor.
  private:
  
  public:
    TestSensor(int input_pin);
    void update();
    boolean is_dry();
};

class WatermarkSensor : public MoistureSensor{
  // Controls the Watermark Sensor (Gypsum block).

  private:
  
  public:
    WatermarkSensor(int input_pin);
    void update();
    boolean is_dry();
};

#endif

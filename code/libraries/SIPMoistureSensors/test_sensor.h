#ifndef TEST_SENSOR_H
#define TEST_SENSOR_H

#include "generic_moisture_sensor.h"

// Forward declaring the DataStream class.
template<typename DataType> class DataStream;


class TestSensor : public MoistureSensor{
  // A test class assuming a simple analog sensor (a potentiometer).
  private:
    int m_pin; // Arduino pin number.
    float m_potentiometer_max;
    DataStream<float>* m_data;
  
  public:
    TestSensor(int input_pin);
    void update();
    float get_saturation();
};

#endif

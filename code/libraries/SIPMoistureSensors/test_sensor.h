#ifndef TEST_SENSOR_H
#define TEST_SENSOR_H

#include "generic_moisture_sensor.h"
#include <Time.h>

// Forward declaring the DataStream class.
template<typename DataType> class DataStream;


class TestSensor : public MoistureSensor{
  // A test class assuming a simple analog sensor (a potentiometer).
  private:
    int m_pin; // Arduino pin number.
    float m_potentiometer_max;
    DataStream<float>* m_data;
  
  public:
    TestSensor(int data_count, int input_pin);
    void update();
    float get_saturation();
    float get_temperature() { return 0; }
    time_t get_timestamp() { return 0; }
};

#endif

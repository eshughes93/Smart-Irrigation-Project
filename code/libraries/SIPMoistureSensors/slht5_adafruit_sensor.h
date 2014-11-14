#ifndef SLHT5_ADAFRUIT_SENSOR_H
#define SLHT5_ADAFRUIT_SENSOR_H

#include "generic_moisture_sensor.h"

// Forward declaring the DataStream class.
template<typename DataType> class DataStream;


class SLHT5Sensor : public MoistureSensor{
  // A test class assuming a simple analog sensor.
  private:
    int m_pin; // Arduino pin number.
    DataStream<float>* m_data;
  
  public:
    SLHT5Sensor(int input_pin);
    void update();
    boolean is_dry();
};

#endif

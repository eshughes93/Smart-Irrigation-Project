#ifndef SLHT5_ADAFRUIT_SENSOR_H
#define SLHT5_ADAFRUIT_SENSOR_H

#include "generic_moisture_sensor.h"

// Forward declaring the DataStream class.
template<typename DataType> class DataStream;

// Forward declaring the SHT1x class (The adafruit moisture sensor).
class SHT1x;


class SLHT5Sensor : public MoistureSensor{
  // A test class assuming a simple analog sensor.
  private:
    int m_data_pin, m_clock_pin;
    DataStream<float>* m_data;
		SHT1x* m_sensor;
  
  public:
    SLHT5Sensor(int data_pin, int clock_pin);
    void update();
    boolean is_dry();
		float get_saturation();
};

#endif

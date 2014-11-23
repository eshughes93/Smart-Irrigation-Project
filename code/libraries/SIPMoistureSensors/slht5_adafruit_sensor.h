#ifndef SLHT5_ADAFRUIT_SENSOR_H
#define SLHT5_ADAFRUIT_SENSOR_H

#include "generic_moisture_sensor.h"

// Forward declaring the SHT1x class (The adafruit moisture sensor).
class SHT1x;

// Forward declaring the DataStream class.
template<typename DataType> class DataStream;

// Define the data point variable types. Make sure it matches in the 
// slht5_adafruit_sensor.cpp file
typedef float SaturationType;
typedef float TemperatureType;
//typedef char TimestampType;


class SLHT5Sensor : public MoistureSensor{
  // A test class assuming a simple analog sensor.
  private:
    int m_data_pin, m_clock_pin;
    DataStream<SaturationType>* m_saturation;
    DataStream<TemperatureType>* m_temperature;
		//DataStream<TimstampType>* m_timestamp;
    SHT1x* m_sensor;
  
  public:
    SLHT5Sensor(int data_pin, int clock_pin);
    void update();
    SaturationType get_saturation();
    TemperatureType get_temperature();
    //TimestampType get_timestamp();
};

#endif

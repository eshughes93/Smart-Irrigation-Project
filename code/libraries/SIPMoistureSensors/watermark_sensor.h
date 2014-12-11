#ifndef WATERMARK_SENSOR_H
#define WATERMARK_SENSOR_H

#include "generic_moisture_sensor.h"

// Forward declaring the DataStream class.
template<typename DataType> class DataStream;


/*
 * This class was intended to interface with the Watermark soil 
 * moisture sensor. However, we were not able to find satisfactory 
 * documentation and could not implement it. This class is currently an 
 * empty, outdated shell of a class.
 *
 */

class WatermarkSensor : public MoistureSensor{
  // Controls the Watermark Sensor (Gypsum block).

  private:
    DataStream<float>* m_data;
  
  public:
    WatermarkSensor(int data_count, int input_pin);
    void update();
    float get_saturation();
};

#endif

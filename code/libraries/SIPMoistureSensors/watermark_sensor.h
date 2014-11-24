#ifndef WATERMARK_SENSOR_H
#define WATERMARK_SENSOR_H

#include "generic_moisture_sensor.h"

// Forward declaring the DataStream class.
template<typename DataType> class DataStream;


class WatermarkSensor : public MoistureSensor{
  // Controls the Watermark Sensor (Gypsum block).

  private:
    DataStream<float>* m_data;
  
  public:
    WatermarkSensor(int input_pin);
    void update();
    float get_saturation();
};

#endif

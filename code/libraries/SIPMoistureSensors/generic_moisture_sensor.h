#ifndef GENERIC_SENSOR_H
#define GENERIC_SENSOR_H

#include <Arduino.h>

class MoistureSensor{
  // Base class for all moisture sensors.

  protected:
    int m_max_data_count;
  
    MoistureSensor();
    //MoistureSensor(int input_pin_1, int input_pin_2, int input_pin_2);
  public:
    virtual void update()=0;
    virtual boolean is_dry()=0;
};

#endif

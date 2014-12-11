#ifndef GENERIC_SENSOR_H
#define GENERIC_SENSOR_H

#include <Time.h>

class MoistureSensor{
  // Base class for all moisture sensors.

  protected:
    int m_max_data_count;
  
    MoistureSensor(int data_count) { m_max_data_count = data_count; }
  public:
    virtual void update()=0;
    virtual float get_saturation()=0;
    virtual float get_temperature()=0;
    virtual time_t get_timestamp()=0;
};

#endif

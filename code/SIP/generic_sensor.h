#ifndef GENERIC_SENSOR_H
#define GENERIC_SENSOR_H

#include <Arduino.h>

class MoistureSensor{
  // Base class for all moisture sensors.

  protected:
    int m_pin; // Arduino pin number 
    int m_pin_1;
    int m_pin_2;
    int m_max_data_count; // Maximum size of the data array.
    int m_data_count; // Number of data entries and the next open array index too.
    int* m_data; // assuming the data will be integers
  
    MoistureSensor(int input_pin);
    //MoistureSensor(int input_pin_1, int input_pin_2, int input_pin_2);
  public:
    virtual void update()=0;
    virtual boolean is_dry()=0;
};

#endif

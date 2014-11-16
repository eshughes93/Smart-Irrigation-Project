#ifndef GENERIC_SENSOR_H
#define GENERIC_SENSOR_H

class MoistureSensor{
  // Base class for all moisture sensors.

  protected:
    int m_max_data_count;
  
    MoistureSensor();
  public:
    virtual void update()=0;
		virtual float get_saturation()=0;
};

#endif

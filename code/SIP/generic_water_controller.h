#ifndef GENERIC_WATER_CONTROLLER_H
#define GENERIC_WATER_CONTROLLER_H

#include <Arduino.h>

class WaterController{
  // Base class for all water controllers.
  protected:
    WaterController() {}
  public:
    virtual void water_plants()=0;
};


#endif

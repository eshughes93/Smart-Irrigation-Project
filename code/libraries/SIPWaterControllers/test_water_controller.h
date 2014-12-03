#ifndef WATER_CONTROLLER_H
#define WATER_CONTROLLER_H

#include <Arduino.h>
#include "generic_water_controller.h"

class TestWaterController : public WaterController {
  // Test class that blinks a light
  private:
    int m_pin;

  public:
    TestWaterController(int test_pin);
    void water_plants();
};


#endif

#include <Arduino.h>
#include "water_controllers.h"
#include "generic_water_controller.h"

TestWaterController::TestWaterController (int test_pin) : WaterController() {
  m_pin = test_pin;
}

void TestWaterController::water_plants(){
  // Double blink when it is time to water.
  digitalWrite(m_pin, HIGH);
  delay(100);
  digitalWrite(m_pin, LOW);
  delay(100);
  digitalWrite(m_pin, HIGH);
  delay(100);
  digitalWrite(m_pin, LOW);
}

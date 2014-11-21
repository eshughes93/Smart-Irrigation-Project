// Smart Irrigation Project
// cmps 115 Fall 2014

#include <Arduino.h>

#include <generic_moisture_sensor.h>
//#include <test_sensor.h>
#include "slht5_adafruit_sensor.h"
#include "generic_communication_controller.h"
#include "serial_controller.h"

class SensorArduino {
  public:
    // Arduino variables
    int m_sleep_time;

    // Components
    MoistureSensor* moisture_sensor;
    CommunicationController* communication_controller;
    //... etc.

    SensorArduino() {
      m_sleep_time = 100; // 1 seconds

      // Pins used by the SLHT5 moisture sensor.
      int data_pin = 10;
      int clock_pin = 11;
      
      // Initialize the components of SIP
      //moisture_sensor = new TestSensor(MOISTURE_SENSOR_PIN_1);
      moisture_sensor = new SLHT5Sensor(data_pin, clock_pin);
      communication_controller = new SerialController();
      // new solar controller? wifi_controller? etc.
    }

    void loop(){
      // Update the components.
      moisture_sensor->update();
      communication_controller->update();
      
      // Send the new saturation percent over the network.
      float saturation_percent = moisture_sensor->get_saturation();
      communication_controller->send_saturation_level(saturation_percent);
      //float temperature = moisture_sensor->get_temperature();
      //communication_controller->send_temperature(temperature);

      delay(m_sleep_time);
    }
};

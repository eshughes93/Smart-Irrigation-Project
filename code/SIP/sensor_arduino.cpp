// Smart Irrigation Project
// cmps 115 Fall 2014

#include <Arduino.h>

#include <generic_moisture_sensor.h>
//#include <test_sensor.h>
#include "slht5_adafruit_sensor.h"

class SensorArduino {
  public:
    // Arduino variables
    int SLEEP_TIME; // 1 seconds
    int MOISTURE_SENSOR_PIN_1;
    int MOISTURE_SENSOR_PIN_2;
    int MOISTURE_SENSOR_PIN_3;

    // Components
    MoistureSensor* moisture_sensor;
    // CommunicationController* communication_controller;
    //... etc.

    SensorArduino() {
      SLEEP_TIME = 1000; // 1 seconds
      MOISTURE_SENSOR_PIN_1 = 0;
      MOISTURE_SENSOR_PIN_2 = 1;
      MOISTURE_SENSOR_PIN_3 = 2;
      
      int data_pin = 10;
      int clock_pin = 11;
      
      // Initialize the components of SIP
			//moisture_sensor = new TestSensor(MOISTURE_SENSOR_PIN_1);
      moisture_sensor = new SLHT5Sensor(data_pin, clock_pin);
      // communition_controller = new CommunicationController();
      // new solar controller? wifi_controller? etc.
      
      Serial.begin(38400);
      Serial.println("Starting...");
    }

    void loop(){
      // Update the components if necessary.
      moisture_sensor->update();
      // communication_controller->update();
      
      if (moisture_sensor->is_dry()){
        // The ground is dry, send a message to water plants
        
        // water_needed = moisture_sensor->get_water_needed();
        // communication_controller->irrigate(water_needed);

        Serial.print("Soil is dry. ");
      } else {
        Serial.print("Soil is wet. ");
      }

      Serial.print(" Saturation: ");
      Serial.print(moisture_sensor->get_saturation());
      Serial.print("%\n");

      delay(SLEEP_TIME);
    }
};

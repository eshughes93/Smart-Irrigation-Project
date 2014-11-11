// Smart Irrigation Project
// cmps 115 Fall 2014

#include <Arduino.h>

#include <generic_moisture_sensor.h>
#include <moisture_sensors.h>



class Sensor_Arduino {
  public:
    // Arduino variables

    // Components
    MoistureSensor* moisture_sensor;
    // CommunicationController* communication_controller;
    //... etc.
    int SLEEP_TIME; // 1 seconds
    int MOISTURE_SENSOR_PIN_1;
    int MOISTURE_SENSOR_PIN_2;
    int MOISTURE_SENSOR_PIN_3;

    Sensor_Arduino() {
      SLEEP_TIME = 1000; // 1 seconds
      MOISTURE_SENSOR_PIN_1 = 0;
      MOISTURE_SENSOR_PIN_2 = 1;
      MOISTURE_SENSOR_PIN_3 = 2;
      
      // Initialize the components of SIP
      moisture_sensor = new TestSensor(MOISTURE_SENSOR_PIN_1);
      // communition_controller = new CommunicationController();
      // new solar controller? wifi_controller? etc.
    
    }

    void loop(){
      // Update the components if necessary.
      moisture_sensor->update();
      // communication_controller->update();
    
      if (moisture_sensor->is_dry()){
        // The ground is dry, send a message to water plants
        
        // water_needed = moisture_sensor->get_water_needed();
        // communication_controller->irrigate(water_needed);

      }

      delay(SLEEP_TIME);
    }
};

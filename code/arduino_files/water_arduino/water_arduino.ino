// Smart Irrigation Project
// cmps 115 Fall 2014

#include <Arduino.h>
#include <Time.h>
// Include Data Stream files
#include <array_data_stream.h>
#include <generic_data_stream.h>
#include <stt_data_point.h>

// Include Communication Controller files
#include <generic_communication_controller.h>
#include <serial_controller.h>
#include <xbee_controller.h>


// Include Water Controller files
#include <generic_water_controller.h>
#include <test_water_controller.h>


class WaterArduino {
  public:
    // Arduino variables
    int m_sleep_time; // 1 seconds
    int m_testing_pin; // For testing... Light up the pin 13 blue LED
    // Components
    WaterController* water_controller;
    XBee* xbee_receiver;
    CommunicationController* communication_controller;
    //... etc.
  
    WaterArduino(){
      m_sleep_time = 1000; // 1 seconds
      m_testing_pin = 13; // For testing... Light up the pin 13 blue LED
    
      // Initialize the components of SIP
      water_controller = new TestWaterController(m_testing_pin);
			//communication_controller = new SerialController();
			// new solar controller? wifi_controller? etc.
      xbee_receiver = new XBee();
    }

    void loop(){
      // Update the components if necessary.
      // Somehow check the communication controller for new data
      //Somehow check the moisture value to see if it is too dry.
      // Water the plants if the ground is too dry.
      water_controller->water_plants();
      
      //Check if package is received while calling receival function.            
      if(!xbee_receiver->receive_package()){
        Serial.println("No package received.");
      }
      delay(m_sleep_time);
    }
};

// Define the functions that the Arduino will call.
WaterArduino* arduino;
void setup(){ arduino =  new WaterArduino(); }
void loop(){ arduino->loop(); }


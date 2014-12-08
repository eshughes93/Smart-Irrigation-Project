// Smart Irrigation Project
// cmps 115 Fall 2014

#include <Arduino.h>

// Include Communication Controller files
#include "generic_communication_controller.h"
#include "serial_controller.h"
//#include "xbee_controller.h"
//#include <Time.h>

// Include Water Controller files
#include "generic_water_controller.h"
#include "test_water_controller.h"

// Include Data Stream files
#include "generic_data_stream.h"
#include "array_data_stream.h"
#include "stt_data_point.h"
// Define the data types
typedef float SaturationType;
typedef float TemperatureType;
typedef int TimestampType;
// Create a macro for the STTDataPoint
#define STT_DATA_POINT STTDataPoint<SaturationType, TemperatureType, TimestampType>


class WaterArduino {
  public:
    // Arduino variables
    int m_sleep_time; // 1 seconds
    int m_testing_pin; // For testing... Light up the pin 13 blue LED
    int m_max_data_count; // Amount of data to be stored.
  
    // Components
    WaterController* water_controller;
    CommunicationController* communication_controller;
    DataStream<STT_DATA_POINT_POINT>* m_data;
    //... etc.

    // Member functions
    void create_datastream();
  
    WaterArduino(){
      m_sleep_time = 1000; // 1 seconds
      m_testing_pin = 13; // For testing... Light up the pin 13 blue LED
      m_max_data_count = 50;

      create_data_stream()

      // Initialize the components of SIP
      water_controller = new TestWaterController(m_testing_pin);
      //communication_controller = new SerialController();
      // new solar controller? wifi_controller? etc.
  
    }

    void loop(){
      // Update the components if necessary.
  
      // Somehow check the communication controller for new data
      // Somehow check the moisture value to see if it is too dry.
      
      // Water the plants if the ground is too dry.
      water_controller->water_plants();

      delay(m_sleep_time);
    }
};

void WaterArduino::create_data_stream() {
  m_data = new ArrayDataStream<STT_DATA_POINT*>(m_max_data_count);
  for (int i=0;  i<m_max_data_count; i++){
    STT_DATA_POINT* new_datum = new STT_DATA_POINT(0, 0, 0);
    m_data->add_data(new_datum);
  }
}


// Define the functions that the Arduino will call.
WaterArduino* arduino;
void setup(){ arduino =  new WaterArduino(); }
void loop(){ arduino->loop(); }


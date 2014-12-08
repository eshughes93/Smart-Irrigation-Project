// Smart Irrigation Project
// cmps 115 Fall 2014

#include <Arduino.h>
#include <Time.h>

// Include Communication Controller files
#include <generic_communication_controller.h>
#include <serial_controller.h>
#include <xbee_controller.h>


// Include Water Controller files
#include <generic_water_controller.h>
#include <test_water_controller.h>

// Include Data Stream files
#include <array_data_stream.h>
#include <generic_data_stream.h>
#include <stt_data_point.h>

// Define the data types
typedef float SaturationType;
typedef float TemperatureType;
typedef time_t TimestampType;
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
    XBee* xbee_receiver;
    CommunicationController* communication_controller;
    DataStream<STT_DATA_POINT*>* m_data;
    //... etc.

    // Member functions
    void create_datastream();
    void print_updated_values();
    
    WaterArduino(){
      m_sleep_time = 2500; // 2.5 seconds
      m_testing_pin = 13; // For testing... Light up the pin 13 blue LED
      m_max_data_count = 5;

      create_datastream();

      // Initialize the components of SIP
      water_controller = new TestWaterController(m_testing_pin);
      //communication_controller = new SerialController();
      // new solar controller? wifi_controller? etc.
      xbee_receiver = new XBee();
    }

    void loop(){
      // Update the components if necessary.
      // Somehow check the communication controller for new data
      // Somehow check the moisture value to see if it is too dry.
      // Water the plants if the ground is too dry.
      water_controller->water_plants();
      
      //Check if package is received while calling receival function.            
      if(xbee_receiver->receive_package()){
        STT_DATA_POINT* data_point = m_data->manually_update_next();
        data_point->set_saturation(xbee_receiver->get_saturation());
        data_point->set_temperature(xbee_receiver->get_temperature());
        data_point->set_timestamp(xbee_receiver->get_timestamp());
        print_updated_values();
      } else {
        Serial.println("No package received.");
      }
      delay(m_sleep_time);
    }
};

void WaterArduino::print_updated_values(){
    Serial.println("Last updated values read: ");
    Serial.print("Saturation: ");
    Serial.println(m_data->get_last_data()->get_saturation());
    Serial.print("Temperature: ");
    Serial.println(m_data->get_last_data()->get_temperature());
    Serial.print("Timestamp: ");
    Serial.println(m_data->get_last_data()->get_timestamp());
}
void WaterArduino::create_datastream() {
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


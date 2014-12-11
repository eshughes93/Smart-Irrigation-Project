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

// Include Moisture Sensor files
#include <generic_moisture_sensor.h>
#include <slht5_adafruit_sensor.h>
#include <watermark_sensor.h>
#include <SHT1x.h>


class SensorArduino {
public:
  // Arduino variables
  int m_sleep_time;
  time_t timestamp;
  // Components
  MoistureSensor* moisture_sensor;
  XBee* xbee_transmitter;
  //... etc.

  SensorArduino() {
    m_sleep_time = 5000; // 5 seconds
    timestamp = 0; 
    /* Start at 0
     * Timestamp value should later be updated to reflect actual time
     * rather than time passed since arduino was turned on
     */

    //Pins used by the SLHT5 moisture sensor.
    int data_pin = 10;
    int clock_pin = 11;

    // Initialize the components of SIP
    //moisture_sensor = new TestSensor(MOISTURE_SENSOR_PIN_1);
    moisture_sensor = new SLHT5Sensor(10, data_pin, clock_pin);
    xbee_transmitter = new XBee();
    // new solar controller? etc.
  }

  void loop(){
    // Update the components.
    moisture_sensor->update();

    //Serial.println("In main loop!");
    // Send the new saturation percent over the network.
    float saturation_percent = moisture_sensor->get_saturation();
    float temperature = moisture_sensor->get_temperature();
    xbee_transmitter->send_package(saturation_percent, temperature, timestamp);
    timestamp += m_sleep_time/1000;
    delay(m_sleep_time);
  }
};

// Define the functions that the Arduino will call.
SensorArduino* arduino;
void setup(){ arduino =  new SensorArduino(); }
void loop(){ arduino->loop(); }



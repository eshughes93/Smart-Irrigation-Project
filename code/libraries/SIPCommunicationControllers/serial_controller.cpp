#include <Arduino.h>
#include <Time.h>
#include "serial_controller.h"

SerialController::SerialController() : CommunicationController() {
  m_iteration = 0;
  // Set up the communication link.
  Serial.begin(9600);
  Serial.println("Starting...");
}

void SerialController::update() {
  m_iteration++;
}

void SerialController::send_iteration(){
  Serial.print("[");
  Serial.print(m_iteration);
  Serial.print("]");
}


void SerialController::send_package(float sat, float temp, time_t time) {
	send_saturation_level(sat);
	send_temperature(temp);
	send_timestamp(time);
}

void SerialController::send_saturation_level(float saturation_percent) {
  // Print the saturation percent to the serial port.
	send_iteration();
  Serial.print("Saturation: ");
  Serial.print(saturation_percent);
  Serial.print("%\n");
}

void SerialController::send_temperature(float temperature) {
	// Print the temperature to the serial port.
	send_iteration();
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.print("F\n");
}

void SerialController::send_timestamp(time_t timestamp) {
	// Print the timestamp to the serial port.
	send_iteration();
  Serial.print("Timestamp: ");
  Serial.print(timestamp);
  Serial.print("F\n");
}

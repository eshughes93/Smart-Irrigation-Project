#include <Arduino.h>
#include "serial_controller.h"

SerialController::SerialController() : CommunicationController() {
	// Set up the communication link.
	Serial.begin(38400);
	Serial.println("Starting...");
}

void SerialController::update() {
	;
}

void SerialController::send_saturation_level(float saturation_percent) {
	// Print the saturation percent to the serial port.
	Serial.print("Saturation: ");
	Serial.print(saturation_percent);
	Serial.print("%\n");
}

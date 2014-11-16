#ifndef SERIAL_CONTROLLER_H
#define SERIAL_CONTROLLER_H

#include "generic_communication_controller.h"

/*
 * The SerialController is a derived class of the 
 * CommunicationController class. The primary purpose of the 
 * SerialController is to send data over the serial connection to your 
 * computer for testing purposes. This tests the communication 
 * controller architecture and allows any sensors to be tested easily.
 *
 */

class SerialController : public CommunicationController {
  public:
		SerialController();
		void update();
		void send_saturation_level(float saturation_percent);
};

#endif

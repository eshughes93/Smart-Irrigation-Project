#ifndef SERIAL_CONTROLLER_H
#define SERIAL_CONTROLLER_H

#include <Time.h>
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
  private:
    int m_iteration;

		void send_iteration();

  public:
    SerialController();
    void update();
		void send_package(float sat, float temp, time_t time);
    void send_saturation_level(float saturation_percent);
    void send_temperature(float temperature);
    void send_timestamp(time_t time);

		bool receive_package() { return false; }
		float get_saturation() { return 0; }
		float get_temperature() { return 0; }
		time_t get_timestamp() { return 0; }
};

#endif

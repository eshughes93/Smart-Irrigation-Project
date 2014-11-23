#ifndef GENERIC_COMMUNICATION_CONTROLLER_H
#define GENERIC_COMMUNICATION_CONTROLLER_H

class CommunicationController{
  // Base class for all forms of communication. Provides a standardized 
  // interface for our Arduinos to use. The actual networking device 
  // (be it wired, WiFi, radio, etc.) is hidden.

  protected:
    CommunicationController() {}

  public:
		virtual void update()=0;
		virtual void send_saturation_level(float saturation_percent)=0;
		//virtual void send_temperature(float saturation_percent)=0;
    // Interface commands...
    // Should have a way to register callbacks? What happens when a 
    // message is received? How to alert the receiving arduino?
};

#endif

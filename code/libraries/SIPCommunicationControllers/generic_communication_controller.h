#ifndef GENERIC_COMMUNICATION_CONTROLLER_H
#define GENERIC_COMMUNICATION_CONTROLLER_H

#include <Time.h>

class CommunicationController{
  // Base class for all forms of communication. Provides a standardized 
  // interface for our Arduinos to use. The actual networking device 
  // (be it wired, WiFi, radio, etc.) is hidden.

  protected:
    CommunicationController() {}

  public:
		//General updating
		virtual void update(){};
   
    //Transmitting
    virtual void send_package(float sat, float temp, time_t time)=0;
    
    //Receiving
    virtual bool receive_package()=0;
    
		//Get data after package has been received
    virtual float get_saturation()=0;
    virtual float get_temperature()=0;
    virtual time_t get_timestamp()=0;

};

#endif

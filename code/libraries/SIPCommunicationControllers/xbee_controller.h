#ifndef XBEE_CONTROLLER_H
#define XBEE_CONTROLLER_H

#include "generic_communication_controller.h"
#include <time.h>


class XBee: public CommunicationController {
  // Class to interface with the XBee.
  public:
    //Constructor
      XBee();
    
    //Transmitting functions
      void send_package(float sat, float temp, time_t time);

    //Receiving functions
      void receive_package();

   /*
     These getter functions only work if a package has been 
     received, and information has been stored to the XBee class's
     data. 
   */
      float get_saturation();
      float get_temperature();
      time_t get_timestamp();


  private:

      void interpret_data();
      void clear_data();	
      void update_last(float sat, float temp, time_t stamp);
      void parse_package();
      char data_in[150]; //incoming data stream
      char temp_buffer[50]; //buffer to store temperature
      char sat_buffer[50]; //buffer to store saturation
      char time_buffer[50]; //buffer to store timestamp
      float last_temp;
      float last_sat;
      time_t last_time;
      int data_size;
      int data_index;
      char char_in;
};

#endif

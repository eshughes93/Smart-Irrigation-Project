#ifndef XBEE_CONTROLLER_H
#define XBEE_CONTROLLER_H

#include <Time.h>
#include "generic_communication_controller.h"

class XBee: public CommunicationController {
  // Class to interface with the XBee.
  public:
    //Constructor
      XBee();
    
    //Transmitting functions
      void send_package(float sat, float temp, time_t time);

    //Receiving functions
      bool receive_package();

   /*
     These getter functions only work if a package has been 
     received, and information has been stored to the XBee class's
     data. 
   */
      float get_saturation();
      float get_temperature();
      time_t get_timestamp();


  private:
      //Translates member values from char arrays to useful data types.
      void interpret_data(); 
      //Clears data_in buffer
      void clear_data();	
      //Updates member sat, temp, and timestamp values.
      void update_last(float sat, float temp, time_t stamp);
      //Translates data_in buffer into respective sat, temp, and timestamp buffers.
      void parse_package();
      
      char data_in[150]; //incoming data stream
      char temp_buffer[50]; //buffer to store temperature
      char sat_buffer[50]; //buffer to store saturation
      char time_buffer[50]; //buffer to store timestamp
      //Member values holding temperature, saturation, and timestamp
      float last_temp;
      float last_sat;
      time_t last_time;
      
      //These values are used in the receive_package() function
      //Size of the data_in buffer
      int data_size;
      //Current index for reading in Serial data
      int data_index;
      //Holds current char being read by Serial data
      char char_in;
};

#endif

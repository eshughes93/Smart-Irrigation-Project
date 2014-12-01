#ifndef XBEE_CONTROLLER_H
#define XBEE_CONTROLLER_H

#include <time.h>

class XBee {
  // Class to interface with the XBee.
  public:
    //Constructor
      XBee();
    //Transmitting functions
      void send_int(int val);
      void send_float(float val);
      
      void send_package(float sat, float temp, time_t time);
      void parse_package(int packet_piece);
      void receive_package();
    //Receiving functions
      void interpret_data();
      void clear_data();		
      void fill_temp(int s_index, int fill);
      void fill_sat(int s_index, int fill);
      void fill_tstamp(int s_index, int fill);
  
  private:
      char data_in[150]; //incoming data stream
      char temperature[50];
      char saturation[50];
      char timestamp[50];
      int data_size;
      int data_index;
      char char_in;
      char data_type;
};

#endif

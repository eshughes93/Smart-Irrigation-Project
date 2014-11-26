#ifndef XBEE_CONTROLLER_H
#define XBEE_CONTROLLER_H

class XBee {
  // Class to interface with the XBee.
  public:
  //Transmitting functions
  void send_int(int val);
  void send_float(float val);
  
  //Receiving functions
  void receive_data();
  void interpret_data();
  void clear_data();
  
  private:
  char data_in[100]; //incoming data stream
  int data_size;
  int data_index;
  char char_in;
  char data_type;
};

#endif

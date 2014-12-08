//Implementation for xbee controller

#include "xbee_controller.h"
#include <Arduino.h>
#include <stdlib.h>
#include <../Time/Time.h>

XBee::XBee(){
  data_index = 0;
}

/*========================================================
  @name   send_page - sends the data packet 

  @prama  sat  - moisture saturation level 
          temp - temperature reading
          time - time stamp 

  @return none
  @package  format - <[saturation][temperature][timestamp]>
*/
void XBee::send_package(float sat, float temp, time_t time){
    Serial.print('<');
    Serial.print('[');
    Serial.print(sat);
    Serial.print(']');
    Serial.print('[');
    Serial.print(temp);
    Serial.print(']');
    Serial.print('[');
    Serial.print(time);
    Serial.print(']');
    Serial.print('>');
}

/*========================================================
  @name   parse_package - parses the data packet recieved 

  @prama  none

  @return none
  
  parses the package form the format "<[saturation][temperature][timestamp]>""
  to read the saturation, temperature and timestamp into individual buffers
*/
void XBee::parse_package(){
    for(int i = 0; i < data_size; i++){
        Serial.print(data_in[i]);
    }
    Serial.println();
   char curr = '\0';
   int packet_piece = 0;
   int buffer_index = 0;
   for(int i = 0; i < data_size; i++){
      curr = data_in[i];
      if( curr == '['){
         packet_piece++;
         buffer_index = 0;
      } else if( curr != ']' && curr != '>'){
         switch(packet_piece){
               case 1: //saturation
                   sat_buffer[buffer_index++] = curr;
                   sat_buffer[buffer_index] = '\0';
                   break;
               case 2: //temperature
                   temp_buffer[buffer_index++] = curr;
                   temp_buffer[buffer_index] = '\0';
                   break;
               case 3: //timestamp
                   time_buffer[buffer_index++] = curr;
                   time_buffer[buffer_index] = '\0';
                   break;
               default:
                   break;
         }
      }
   }
}

/*========================================================
  @name   receive_package - gets data packet sent via wifi

  @prama  none

  @return none
  
  If data is available, the function loops and retrieves the 
  data packet sent and stores the packet in a buffer
*/
void XBee::receive_package(){
    bool packet_start = false;
    bool packet_end = false;
    clear_data();
    data_index = 0;
    data_size = 150;
    while(Serial.available() > 0){
        char_in = Serial.read();
        if(char_in == '<'){
            Serial.println("Packet began");
            data_index = 0;
            packet_start = true;
        } else if(char_in == '>'){
            packet_end = true;
            Serial.println("Packet end reached ");
            break;
        } else if(data_index < data_size){
            data_in[data_index++] = char_in;
            data_in[data_index] = '\0';
        }
    }
    if(packet_start && packet_end){
        Serial.println("Packet interpretation imminent");
        parse_package();
        interpret_data();
        packet_start = false;
        packet_end = false;
    }

}

/*========================================================
  @name  updates_last - update global variables

  @prama  sat  - moisture saturation level 
          temp - temperature reading
          time - time stamo

  @return none
  
  updates global variabes used to store moisture level, temperature
  and time stamp
*/
void XBee::update_last(float sat, float temp, time_t stamp){
   last_sat = sat;
   last_temp = temp;
   last_time = stamp;
}

/*
  gets private variable
*/
float XBee::get_saturation(){
    return last_sat;
}
/*
  gets private variable
*/
float XBee::get_temperature(){
    return last_temp;
}
/*
  gets private variable
*/
time_t XBee::get_timestamp(){
    return last_time;
}

/*========================================================
  @name   interpret_dat - converts char to float

  @prama  none

  @return none
  
  converts the data values stored in the buffers to 
  floating point values
*/
void XBee::interpret_data(){
   float sat = atof(sat_buffer);
   float temp = atof(temp_buffer);
   time_t t_stamp = atoi(time_buffer);
   Serial.println("Package indicates: ");
   Serial.print("Saturation: ");
   Serial.println(sat);
   Serial.print("Temperature: ");
   Serial.println(temp);
   Serial.print("Timestamp: ");
   Serial.println(t_stamp);
   update_last(sat,temp,t_stamp);
}

/*========================================================
  @name   clear_data - clears buffers

  @prama  none

  @return none
  
  clears the buffer thats used to store the incoming packet
*/
void XBee::clear_data(){
   for(int i = 0; i < data_size; i++){
      data_in[i] = '\0';
   }
}


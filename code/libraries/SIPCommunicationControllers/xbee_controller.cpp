//Implementation for xbee controller

#include <Arduino.h>
#include <Time.h>
#include "./xbee_controller.h"

/*
The constructor for the XBee class. 
Initializes the data index to 0 for reading packets,
and sets the baud rate for the Serial transceiving.
Ideally, the baud rate should be set as a parameter 
for the constructor in the future, but we only ever
used 9600 when we were developing. 
*/
XBee::XBee(){
    Serial.begin(9600); //Set baud rate for XBees
    data_index = 0;
}

/*
 <[saturation][temperature][timestamp]>
 Above is the format in which the package is sent and received. 
 Ultimately, more paramaters could be added. Ideally, 
 once set up as a mesh network with multiple transmitters and one
 receiver, the packages would also transmit which module the package 
 is coming from, so on the receiving end the water controller would know
 which zone the package is referring to. 
 
 The send_package function takes three parameters:
 sat - the saturation of the soil taken from the sensors
 temp - the temperature of the environment when the sensors are read
 time - the timestamp for which the readings were taken
*/
void XBee::send_package(float sat, float temp, time_t time){
    digitalWrite(13, HIGH);

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
    
    digitalWrite(13, LOW);

}

/*
This function reads through the xbee's member 
buffer data_in which is holding the most recently
updated package. This is separate from reading the 
package so that the module isn't reading input and
interpreting at the same time.

Future development could potentially store multiple
data packages instead of one at a time,
then parse them only when needed.

It breaks up the data_in buffer into three separate
buffers holding the serial data for the saturation,
temperature, and timestamp. 
*/
void XBee::parse_package(){
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

/*
This function essentially acts as a listener module.
It waits for Serial input and then stores all incoming chars
into the data_in buffer. 

The data_size is hard coded here due to a bug we ran into
where the data_size would be changed although we
were not setting it anywhere but the constructor. 
We set it here for the sake of fixing that. 

The function checks to make sure that the '<' and '>' 
chars are read in at the beginning and end to indicate
the beginning and end of the package.

Once the package is succesfully read from beginning
to end, the package is parsed, and the separate package
pieces are stored into separate buffers. Those buffers are then
interpreted using the interpret_data() function. 

Ultimately, the return value is a boolean to indicate whether
or not the package was received successfully.
*/
bool XBee::receive_package(){
    bool packet_success = false;
    bool packet_start = false;
    bool packet_end = false;
    clear_data();
    data_index = 0;
    data_size = 150;
    while(Serial.available() > 0){
        char_in = Serial.read();
        if(char_in == '<'){
            //Serial.println("Packet began");
            data_index = 0;
            packet_start = true;
        } else if(char_in == '>'){
            packet_end = true;
            //Serial.println("Packet end reached ");
            break;
        } else if(data_index < data_size){
            data_in[data_index++] = char_in;
            data_in[data_index] = '\0';
        }
    }
    if(packet_start && packet_end){
        //Serial.println("Packet interpretation imminent");
        parse_package();
        interpret_data();
        packet_start = false;
        packet_end = false;
        packet_success = true;
    }
    return packet_success;
}

/*
Updates member values holding saturation, temperature,
and timestamp from package values.
*/
void XBee::update_last(float sat, float temp, time_t stamp){
   last_sat = sat;
   last_temp = temp;
   last_time = stamp;
}

/*
Getter functions to retrieve latest 
values held by XBee class.
*/ 
float XBee::get_saturation(){
    return last_sat;
}
float XBee::get_temperature(){
    return last_temp;
}
time_t XBee::get_timestamp(){
    return last_time;
}

/*
Interprets data stored in buffers from package
into actual values.

Because the XBees send data in bytes,
we chose to store the values in char arrays
then convert into the appropriate values.
*/
void XBee::interpret_data(){
   float sat = atof(sat_buffer);
   float temp = atof(temp_buffer);
   time_t t_stamp = atoi(time_buffer);
   update_last(sat,temp,t_stamp);
}

/*
This function just clears the data_in buffer
to null values.
*/
void XBee::clear_data(){
   for(int i = 0; i < data_size; i++){
      data_in[i] = '\0';
   }
}


//Implementation for xbee controller

#include "xbee_controller.h"
#include <Arduino.h>
#include <stdlib.h>
#include <time.h>

XBee::XBee(){
  data_index = 0;
  data_size = sizeof(data_in);
}

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

void XBee::parse_package(int packet_piece){
    data_index = 0;
    while(Serial.available() > 0){
        char_in = Serial.read();
        if(char_in == ']'){
            break;
        }
        switch(packet_piece){
            case 1: //saturation
                //Serial.println("In case 1");
                saturation[data_index++] = char_in;
                saturation[data_index] = '\0';
                break;
            case 2: //temperature
                Serial.println("In case 2");
                temperature[data_index++] = char_in;
                temperature[data_index] = '\0';
                break;
            case 3: //timestamp
                Serial.println("In case 3");
                timestamp[data_index++] = char_in;
                timestamp[data_index] = '\0';
                break;
            default:
                break;
        }
    }
}
void XBee::receive_package(){
    bool packet_start = false;
    bool packet_end = false;
    int packet_piece = 0;
    //Serial.println("Restarting package receival");
    while(Serial.available() > 0){
        //Serial.print("READING PACKAGE");
        char_in = Serial.read();
        if(char_in == '<'){
            Serial.println("Packet began");
            data_index = 0;
            packet_start = true;
        } else if(char_in == '['){
            Serial.print("Reading subpacket ");
            packet_piece++;
            Serial.println(packet_piece);
            parse_package(packet_piece);
        } else if(char_in == ']'){
        
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
        interpret_data();
        packet_start = false;
        packet_end = false;
    }
}
/* Function to read data over XBee Serial. 
 * Packets should begin with a '<' char, and
 * end with a '>' char.
 * Each piece of the packet is read one char
 * at a time.
 */


void XBee::interpret_data(){
    float sat = atof(saturation);
    float temp = atof(temperature);
    time_t t_stamp = atoi(timestamp);
    Serial.println("Package indicates: ");
    Serial.print("Saturation: ");
    Serial.println(sat);
    Serial.print("Temperature: ");
    Serial.println(temp);
    Serial.print("Timestamp: ");
    Serial.println(t_stamp);
}

void XBee::clear_data(){
   for(int i = 0; i < data_size; i++){
      data_in[i] = '\0';
   }
}


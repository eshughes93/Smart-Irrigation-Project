#include <Arduino.h>

class MoistureSensor{

  private:
    int m_pin; // Arduino pin number 
    int m_max_data_count; // Maximum size of the data array.
    int m_data_count; // Number of data entries and the next open array index too.
    int* m_data; // assuming the data will be integers
  
  public:
    MoistureSensor(int input_pin);
    void update();
    boolean is_dry();
};

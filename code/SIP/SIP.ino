
#define TRUE 1
#define FALSE 0
#define USING_SENSOR_ARDUINO FALSE
#define USING_WATER_ARDUINO (USING_SENSOR_ARDUINO == FALSE)

#if USING_SENSOR_ARDUINO
  #include "sensor_arduino.cpp"
  #include "moisture_sensors.h"
  
  Sensor_Arduino* arduino_sensor;
  
  void setup(){
    //Initialize the WaterSensor and ArduinoSensor
    arduino_sensor =  new Sensor_Arduino();
  }
    
  void loop(){
    arduino_sensor->loop();
  }

#else  
  #include "water_arduino.cpp"
  #include "water_controllers.h"
  
  WaterArduino* arduino_water;
  
  void setup(){
    //Initialize the WaterSensor and ArduinoSensor
    arduino_water = new WaterArduino();
  }
  
  
  void loop(){
    arduino_water->loop();
  }

#endif

void setup(){
  //Initialize the WaterSensor and ArduinoSensor
  //WaterSensor water_sensor = new WaterSensor();
  ArduinoSensor arduino_sensor =  new ArduinoSensor();
}


void loop(){
  water_sensor.loop();
}




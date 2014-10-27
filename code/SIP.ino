
// Smart Irrigation Project

const int MOISTURE_PIN = 0;
int DELAY_TIME = 15000; // 15 seconds


void setup(){
}

void loop(){

  // Grab data from the moisture sensor
  int moisture_reading = analogRead(MOISTURE_PIN);

  // Water the plants if the ground is too dry.
  if (is_dry(moisture_reading)){
    release_water();
  }

  delay(DELAY_TIME);
}

boolean is_dry(int moisture_reading){
  // Check the moisture reading to see if the ground is too dry.
  // Return true if the soil is too dry and needs water.
  // Return false if the soil has enough water.

  // Do some actual calculations...
  return false;
}

void release_water(){
  // Release water!
  // Should it use: a timer? ground saturation? other?
  
  // Do stuff...
}

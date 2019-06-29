

/*
  NodeMCU v3 Arduino/Physical pinout map
  
  Arduino | NodeMCU | Available for use
  0       | D3      | SCK
  1       | TX      | 
  2       | D4      | 
  3       | RX      | 
  4       | D2      | 
  5       | D1      | 
  6       |         | 
  7       |         | 
  8       |         | 
  9       | S2      | can't
  10      | S3      | can't
  11      |         | 
  12      | D6      | used
  13      | D7      | used
  14      | D5      | DT
  15      | D8      | used
  16      | D0      | 
 */
#define LOAD_SENSOR_DATA 14
#define LOAD_SENSOR_CLOCK 0

#include <Q2HX711.h>


Q2HX711 load_sensor(LOAD_SENSOR_DATA, LOAD_SENSOR_CLOCK);

void setup() {
  Serial.begin(9600);
  Serial.println("setup");
  delay(5000);
  Serial.println("after delay");
}

void loop(){
  int curr_weight = (load_sensor.read() / 1000);
    Serial.println(curr_weight);
//  digitalWrite(LOAD_SENSOR_CLOCK, LOW);
//  Serial.println("ok");
}

/*
  NodeMCU v3 Arduino/Physical pinout map
  
  Arduino | NodeMCU | Available for use
  0       | D3      | 
  1       | TX      | X
  2       | D4      | 
  3       | RX      | X
  4       | D2      | 
  5       | D1      | 
  6       |         | X
  7       |         | X
  8       |         | X
  9       | S2      | X
  10      | S3      | X
  11      |         | X
  12      | D6      | 
  13      | D7      | 
  14      | D5      | 
  15      | D8      | 
  16      | D0      | 
 */
#define RELAY_1 0

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);

  pinMode(RELAY_1, OUTPUT);

  
}

void loop() {
  digitalWrite(RELAY_1, LOW);

  delay(5000);

  digitalWrite(RELAY_1, HIGH);

  delay(5000);
  // put your main code here, to run repeatedly:

  
}

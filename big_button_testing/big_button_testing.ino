#define MULTIPLEXER_SIGNAL 12

#define MULTIPLEXER_S0 15
#define MULTIPLEXER_S1 13
#define MULTIPLEXER_S2 2
#define MULTIPLEXER_S3 16

int MULTIPLEX_PINS[] = {MULTIPLEXER_S0, MULTIPLEXER_S1, MULTIPLEXER_S2, MULTIPLEXER_S3};

//  Arduino | NodeMCU | Used
//  0       | D3     
//  1       | TX     
//  2       | D4      | M_S2
//  3       | RX     
//  4       | D2     
//  5       | D1    
//  6       |
//  7       | 
//  8       |      
//  9       | S2
//  10      | S3
//  11      |    
//  12      | D6      | M_SIG
//  13      | D7      | M_S1
//  14      | D5      | 
//  15      | D8      | M_S0
//  16      | D0      | M_S3


boolean isOn = false;

void setup() {
  pinMode(MULTIPLEXER_SIGNAL, OUTPUT);

//  digitalWrite(MULTIPLEXER_SIGNAL, HIGH);

  pinMode(MULTIPLEXER_S0, OUTPUT);
  pinMode(MULTIPLEXER_S1, OUTPUT);
  pinMode(MULTIPLEXER_S2, OUTPUT);
  pinMode(MULTIPLEXER_S3, OUTPUT);

  Serial.begin(9600);

  setMultiplex(15);
}

void loop() {

//  delay(500);

  boolean input = digitalRead(MULTIPLEXER_SIGNAL);

  if(input){
    Serial.println("pressed");
  }
  
  Serial.println("loop");
}

void setMultiplex(int activeChannel){
  for(int b=0; b<4; b++){
    boolean result = bitRead(activeChannel, b);

    if(result){
      digitalWrite(MULTIPLEX_PINS[b], HIGH);
    }else{
      digitalWrite(MULTIPLEX_PINS[b], LOW);
    }
  }

  Serial.println("Channel "+String(activeChannel)+" active");

 
}

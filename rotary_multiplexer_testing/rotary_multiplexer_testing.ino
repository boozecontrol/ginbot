#define MULTIPLEXER_SIGNAL 12

#define MULTIPLEXER_S0 15
#define MULTIPLEXER_S1 13
#define MULTIPLEXER_S2 2
#define MULTIPLEXER_S3 16

int MULTIPLEX_PINS[] = {MULTIPLEXER_S0, MULTIPLEXER_S1, MULTIPLEXER_S2, MULTIPLEXER_S3};

#define ROTARY_BUTTON 12
#define ROTARY_CLK 14
#define ROTARY_DT 13

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

int prevCounter = 0;
long counter = 0;
boolean aState;
boolean aLastState;
boolean buttonState = false;


void setup() {
  pinMode(MULTIPLEXER_SIGNAL, INPUT);

  pinMode(MULTIPLEXER_S0, OUTPUT);
  pinMode(MULTIPLEXER_S1, OUTPUT);
  pinMode(MULTIPLEXER_S2, OUTPUT);
  pinMode(MULTIPLEXER_S3, OUTPUT);

  Serial.begin(9600);

  aLastState = rotaryA();
}

void loop() {
  aState = rotaryA();


  if(aState != aLastState){
    if(rotaryB() != aState) {
      counter++;
      
    }else{
      counter--;
    }

    if(counter > prevCounter){
      Serial.println("Next");
      
    }
    if(counter < prevCounter){
      Serial.println("Previous");
    }

    prevCounter= counter;

    delay(200);
  }

  boolean buttonPress = rotaryButton();

  if(buttonPress){
    
    if(!buttonState){
      buttonState = true;
      Serial.println("button pressed");
    }
    
  }else{

    if(buttonState){
      buttonState = false;
    }
    
  }

  aState = aLastState;
}

boolean rotaryButton(){
  setMultiplex(ROTARY_BUTTON);
  return digitalRead(MULTIPLEXER_SIGNAL);
}

boolean rotaryA(){
  setMultiplex(ROTARY_CLK);
  return digitalRead(MULTIPLEXER_SIGNAL);
}

boolean rotaryB(){
  setMultiplex(ROTARY_DT);
  return digitalRead(MULTIPLEXER_SIGNAL);
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
}

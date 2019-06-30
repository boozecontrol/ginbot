#define inputA 6
#define inputB 7

#define button 12

int prevCounter = 0;
int counter = 0;
int aState;
int aLastState;

boolean buttonState = false;

void setup(){

pinMode(inputA, INPUT);
pinMode(inputB, INPUT);
pinMode(button, INPUT);

Serial.begin(9600);

aLastState = digitalRead(inputA);
  
}


void loop(){

  aState = digitalRead(inputA);


  if(aState != aLastState){
    if(digitalRead(inputB) != aState) {
      counter++;
      
    }else{
      counter--;
    }

Serial.println(counter);

    if(counter > prevCounter){
      Serial.println("Next");
      
    }
    if(counter < prevCounter){
      Serial.println("Previous");
    }

    prevCounter= counter;

//    Serial.print("Position:");
//    Serial.println(counter);
    delay(200);
  }

  boolean buttonPress = !digitalRead(button);

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

#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,20,4);  // set the LCD address to 0x27 for a 16 chars and 2 line display

#define inputA 6
#define inputB 7

#define button 12

int prevCounter = 0;
int counter = 0;
int aState;
int aLastState;

boolean buttonState = false;

void setup(){

lcd.init();
lcd.backlight();

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
      writeToLCD("next      ");
      
    }
    if(counter < prevCounter){
      writeToLCD("previous");
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
      Serial.println("buttön preßed");
      writeToLCD("buttön preßed");
    }
    
  }else{

    if(buttonState){
      buttonState = false;
    }
    
  }

  aState = aLastState;
}

void writeToLCD(String title){

  lcd.setCursor(0,0);
  lcd.print(title);
  lcd.setCursor(0,1);
  lcd.print("---");
  lcd.setCursor(0,2);
  lcd.print("Seems");
  lcd.setCursor(0,3);
  lcd.print("To work");
}

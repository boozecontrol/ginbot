/* Arduino Tutorial: Learn how to use an LCD 16x2 screen
   More info: http://www.ardumotive.com/how-to-use-an-lcd-dislpay-en.html  */

//Include LCD library
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

const int panel1 = 9;
const int panel3 = 10;
const int contrastPin = 6;
const int contrastReadPin = A0;

void setup() {
  Serial.begin(9600);
  // set up the LCD's number of columns and rows: 
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("Contrast");

  pinMode(panel1, INPUT);
  pinMode(panel3, INPUT);

  pinMode(contrastPin, OUTPUT);

  analogWrite(contrastPin, 90);
}

void loop() {
//  double contrastSwitch = (double)analogRead(contrastReadPin);

//  int brightnessFactor = (int) (contrastSwitch / 1000 * 255);  
  
  int panel1State = digitalRead(panel1);
  int panel3State = digitalRead(panel3);

  if(panel1State != 0 ){
    Serial.println("1");
  }

  if(panel3State != 0 ){
    Serial.println("3");
  }
  
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(0, 1);

  
//  lcd.print((String)brightnessFactor+"     ");
//  analogWrite(contrastPin, brightnessFactor);
  //Print a message to second line of LCD
  
}

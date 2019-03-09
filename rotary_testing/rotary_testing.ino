
#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

const int contrastPin = 6;
const int rotaryPin = A5;

void setup() {
  pinMode(contrastPin, OUTPUT);
  analogWrite(contrastPin, 90);
  
  lcd.begin(16, 2);
  lcd.print("Rotary Pin");

  pinMode(rotaryPin, INPUT);
}

void loop() {
//  double contrastSwitch = (double)analogRead(contrastReadPin);

  int rotaryPosition = analogRead(rotaryPin);
//  int brightnessFactor = (int) (contrastSwitch / 1000 * 255);  
 
  
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(0, 1);
  lcd.print((String)rotaryPosition+"    ");
  
//  lcd.print((String)brightnessFactor+"     ");
//  analogWrite(contrastPin, brightnessFactor);
  //Print a message to second line of LCD
  
}

#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

const int contrastPin = 6;

const int bigButton = A0;
const int resetButton = A1;

int bigButtonState = 0;
int resetButtonState = 0;

enum MACHINE_STATE {
  RESET,
  CONFIRM_EMPTY_TRAY,
  MENU_TITLE,
  CHOOSE_MENU,
  CONFIRM_COCKTAIL,
  WAIT_FOR_GLASS,
  BALANCING,
  CONFIRM_WEIGHT,
  DISPENSE_COCKTAIL,
  COCKTAIL_READY,
  NONE
};

enum COCKTAIL_CHOICE{
  NO_DRINK,
  GIN_TONIC,
  VODKA_TONIC,
  RUM_COKE,
  RADLER
};

MACHINE_STATE desired_state = RESET;
MACHINE_STATE rendered_state = NONE;

COCKTAIL_CHOICE chosen_drink = NO_DRINK; 

void setup() {
  pinMode(bigButton, INPUT);
  pinMode(resetButton, INPUT);
    
  lcd.begin(16, 2);
  lcd.print("ON");
  
  pinMode(contrastPin, OUTPUT);
  analogWrite(contrastPin, 90);
}

void loop() {
  bigButtonState = digitalRead(bigButton);
  resetButtonState = digitalRead(resetButton);
  
  handle_input();

  render_state(desired_state);
  
}

void render_state(MACHINE_STATE toRender){
  if(rendered_state != toRender){
    switch(toRender){
      case RESET: state_reset(); break;
      case CONFIRM_EMPTY_TRAY: state_confirm_empty_tray(); break;
      case MENU_TITLE: state_menu_title(); break;
    }

    rendered_state = toRender;

    delay(1000);
  }
  
}

void handle_input(){
  if(resetButtonState == HIGH){
    desired_state = RESET;
    return;
  }

  switch(rendered_state){
    case RESET: handle_reset_input(); break;
    case CONFIRM_EMPTY_TRAY: handle_confirm_empty_tray_input(); break;
    case MENU_TITLE: handle_menu_input(); break;
  }
  
}

/**
 * RESET state
 */
void state_reset(){
  lcdPrint("Ginbot ON", "HIT to start!");
}

void handle_reset_input(){
  if(bigButtonState == HIGH){
    desired_state = CONFIRM_EMPTY_TRAY;
  }
}

/**
 * Confirm the empty tray
 */
void state_confirm_empty_tray(){
  lcdPrint("Tray is empty?", "HIT to confirm!");
}

void handle_confirm_empty_tray_input(){
  if(bigButtonState == HIGH){
    desired_state = MENU_TITLE;
  }
}

/**
 * Display the menu welcome screen
 */

void state_menu_title(){
  lcdPrint("Menu", "SELECT Cocktail!");
  chosen_drink = NO_DRINK;
}

void handle_menu_input(){
  
}



void lcdPrint(String line1, String line2){
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(line1);
  lcd.setCursor(0, 1);
  lcd.print(line2);
}

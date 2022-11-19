#include <LiquidCrystal_I2C.h>

int totalColumns = 16;
int totalRows = 2;

LiquidCrystal_I2C lcd(32, totalColumns, totalRows);  

String staticMessage = "NTUT";
String scrollingMessage = "Welcome to National Taipei University of Technology! This is a scrolling message.";

void scrollMessage(int row, String message, int delayTime, int totalColumns) {
  for (int i=0; i < totalColumns; i++) {
    message = " " + message;  //before after space
  } 
  message = message + " "; 
  for (int position = 0; position < message.length(); position++) {
    lcd.setCursor(0, row);
    lcd.print(message.substring(position, position + totalColumns));
    delay(delayTime);
  }
}

void setup(){
  lcd.init();                    
  lcd.backlight();
}

void loop(){
  lcd.setCursor(6, 0);
  lcd.print(staticMessage);
  scrollMessage(1, scrollingMessage, 250, totalColumns);
}
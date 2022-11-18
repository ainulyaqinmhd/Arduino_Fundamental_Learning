// ===== library declaration =====
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>


// ===== variable pin declaration =====
// === pin LED ===
int buzzer = 12;

//Begin - leds
int Led_blue = 5;
int Led_green = 4;
int Led_yellow = 3;
int Led_red = 2;

// === ultrasonic Pin ===
int triggerPin = 10;
int echoPin = 11;
int inches = 0;

float cm = 0;

// === LCD Pin ===
// Set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27, 16, 2);



// readUltraSonic function
long readUltrasonicDistance(int triggerPin, int echoPin) // Trig & Echo responsible function
{

  //pinmode -> Configures the specified pin to behave either as an input or an output
  //digitalWrite -> The code makes the digital pin 13 an OUTPUT and toggles it by alternating between HIGH and LOW at one second pace
  //delayMicroseconds -> Pauses the program for the amount of time (in microseconds) specified by the parameter
  //pulseIn -> Reads a pulse (either HIGH or LOW ) on a pin
  
  pinMode(triggerPin, OUTPUT);  // Trig pin
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  
  // put the wheat pin on high logic level for 10 us
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  
  //  Reads the Echo pin, and returns the wave travel time in microseconds
  return pulseIn(echoPin, HIGH);
}



void setup() {
  // put your setup code here, to run once:
  // === LED pinSETUP ===
  pinMode(Led_blue,OUTPUT);
  pinMode(Led_green,OUTPUT);
  pinMode(Led_yellow,OUTPUT);
  pinMode(Led_red,OUTPUT);
  //buzzer
  // === Buzzer pinSETUP ===
  pinMode(buzzer, OUTPUT);
  Serial.begin(9600);

  // === LCD pinSETUP ===
    // initialize the LCD
  lcd.begin();
  // Turn on the blacklight and print a message.
  lcd.backlight();

}

void loop() {
  // put your main code here, to run repeatedly:

  // signal measurement in cm
  cm = 0.01723 * readUltrasonicDistance(10,11);
  // cm to inch conversion
  inches = (cm / 2.54);
  
 /* NOTES
minimum distance 3
maximum distance 336
range 333
Number of LEDs 8
*/
  // begin - conditions LEDS
  if ((cm >= 3) && (cm <= 86)) {
    
   // === set cursor (row, column) ===
    lcd.clear();
    lcd.setCursor(0, 1);
    lcd.print("TOO CLOSE!!");
    Serial.print("RED LIGHT ON");
    tone(12, 1000); // Send 1KHz sound signal...
    delay(1000);        // ...for 1 sec
    noTone(12);  
    
    digitalWrite(Led_red, HIGH);
    digitalWrite(Led_yellow, LOW);
    digitalWrite(Led_green, LOW);
    digitalWrite(Led_blue, LOW);
  }
  
  else if ((cm >= 87) && (cm <= 170)) {
     // === set cursor (row, column) ===
    lcd.clear();
    lcd.setCursor(0, 1);
    lcd.print("IT IS APPROACHING!");
    Serial.print("YELLOW LIGHT ON");
    tone(12, 800); // Send 1KHz sound signal...
    delay(1000);        // ...for 1 sec
    noTone(12); 
     
    digitalWrite(Led_red, LOW);
    digitalWrite(Led_yellow, HIGH);
    digitalWrite(Led_green, LOW);
    digitalWrite(Led_blue, LOW);
  }
  
  else if ((cm >= 171) && (cm <= 253)) {
    // === set cursor (row, column) ===
    lcd.clear();
    lcd.setCursor(0, 1);
    lcd.print("NORMAL DISTANCE");
    Serial.print("GREEN LIGHT ON");
    tone(12, 500); // Send 1KHz sound signal...
    delay(1000);        // ...for 1 sec
    noTone(12);  
    
    digitalWrite(Led_red, LOW);
    digitalWrite(Led_yellow, LOW);
    digitalWrite(Led_green, HIGH);
    digitalWrite(Led_blue, LOW);
  }
  
  else if ((cm >= 254) && (cm <= 336)) {
    // === set cursor (row, column) ===
    lcd.clear();
    lcd.setCursor(0, 1);
    lcd.print("SAFE DISTANCE");
    tone(12, 100); // Send 1KHz sound signal...
    delay(1000);        // ...for 1 sec
    noTone(12);
     
    Serial.print("BLUE LIGHT ON");
    digitalWrite(Led_red, LOW);
    digitalWrite(Led_yellow, HIGH);
    digitalWrite(Led_green, LOW);
    digitalWrite(Led_blue, LOW);
  }
  
  else {
    // === set cursor (row, column) ===
    lcd.clear();
    lcd.setCursor(0, 1);
    lcd.print("NO OBJECT DETECTED");
    Serial.print("NO LIGHTS TRIGGERED");
    digitalWrite(Led_red, LOW);
    digitalWrite(Led_yellow, HIGH);
    digitalWrite(Led_green, LOW);
    digitalWrite(Led_blue, LOW);
    }
    
  //end - conditions LEDS
  inches = (cm / 2.54);
  Serial.println(" ");
  Serial.print(inches);
  Serial.print("in, ");
  Serial.print(cm);
  Serial.println("cm");
  delay(1000); // wait 100 milliseconds


}

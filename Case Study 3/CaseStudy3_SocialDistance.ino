
int buzzer = 12;

//Begin - leds
int Led_blue1 = 2;
int Led_blue2 = 3;
int Led_green1 = 4;
int Led_green2 = 5; 
int Led_yellow1 = 6;
int Led_yellow2 = 7;
int Led_red1 = 8;
int Led_red2 = 9;

//End - leds

int inches = 0;

float cm = 0;

int triggerPin = 10;
int echoPin = 11;

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

void setup()
{
  pinMode(Led_blue1,OUTPUT);
  pinMode(Led_blue2,OUTPUT);
  pinMode(Led_green1,OUTPUT);
  pinMode(Led_green2,OUTPUT);
  pinMode(Led_yellow1,OUTPUT);
  pinMode(Led_yellow2,OUTPUT);
  pinMode(Led_red1,OUTPUT);
  pinMode(Led_red2,OUTPUT);
  //buzzer
  pinMode(buzzer, OUTPUT);
  Serial.begin(9600);
  
  
}

void loop()
{
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
  if ((cm >= 3) && (cm < 46)) {
    Serial.print("Red 2 condition");
    tone(12, 1000); // Send 1KHz sound signal...
    delay(1000);        // ...for 1 sec
    noTone(12);  
    
    digitalWrite(Led_red2, HIGH);
    digitalWrite(Led_red1, LOW);
    digitalWrite(Led_yellow2, LOW);
    digitalWrite(Led_yellow1, LOW);
    digitalWrite(Led_green2, LOW);
    digitalWrite(Led_green1, LOW);
    digitalWrite(Led_blue2, LOW);
    digitalWrite(Led_blue1, LOW);
  }
  
  else if ((cm > 45) && (cm < 88)) {
    Serial.print("Red 1 condition");
    tone(12, 800); // Send 1KHz sound signal...
    delay(1000);        // ...for 1 sec
    noTone(12); 
     
    digitalWrite(Led_red2, LOW);
    digitalWrite(Led_red1, HIGH);
    digitalWrite(Led_yellow2, LOW);
    digitalWrite(Led_yellow1, LOW);
    digitalWrite(Led_green2, LOW);
    digitalWrite(Led_green1, LOW);
    digitalWrite(Led_blue2, LOW);
    digitalWrite(Led_blue1, LOW);
  }
  
  else if ((cm >87) && (cm < 129)) {
    Serial.print("Yellow 2 condition");
    tone(12, 500); // Send 1KHz sound signal...
    delay(1000);        // ...for 1 sec
    noTone(12);  
    
    digitalWrite(Led_red2, LOW);
    digitalWrite(Led_red1, LOW);
    digitalWrite(Led_yellow2, HIGH);
    digitalWrite(Led_yellow1, LOW);
    digitalWrite(Led_green2, LOW);
    digitalWrite(Led_green1, LOW);
    digitalWrite(Led_blue2, LOW);
    digitalWrite(Led_blue1, LOW);
  }
  
  else if ((cm >128) && (cm < 171)) {
    tone(12, 100); // Send 1KHz sound signal...
    delay(1000);        // ...for 1 sec
    noTone(12);
     
    Serial.print("Yellow 1 condition");
    digitalWrite(Led_red2, LOW);
    digitalWrite(Led_red1, LOW);
    digitalWrite(Led_yellow2, LOW);
    digitalWrite(Led_yellow1, HIGH);
    digitalWrite(Led_green2, LOW);
    digitalWrite(Led_green1, LOW);
    digitalWrite(Led_blue2, LOW);
    digitalWrite(Led_blue1, LOW);
  }
  
  else if ((cm >170) && (cm < 213)) {
   Serial.print("Green 2 condition");
   digitalWrite(Led_red2, LOW);
    digitalWrite(Led_red1, LOW);
    digitalWrite(Led_yellow2, LOW);
    digitalWrite(Led_yellow1, LOW);
    digitalWrite(Led_green2, HIGH);
    digitalWrite(Led_green1, LOW);
    digitalWrite(Led_blue2, LOW);
    digitalWrite(Led_blue1, LOW);
  
  }
  
  else if ((cm >212) && (cm < 254)) {
    Serial.print("Green 1 condition");
    digitalWrite(Led_red2, LOW);
    digitalWrite(Led_red1, LOW);
    digitalWrite(Led_yellow2, LOW);
    digitalWrite(Led_yellow1, LOW);
    digitalWrite(Led_green2, LOW);
    digitalWrite(Led_green1, HIGH);
    digitalWrite(Led_blue2, LOW);
    digitalWrite(Led_blue1, LOW);
  }
  
  else if ((cm >253) && (cm < 296)) {
   Serial.print("Blue  2 condition");
   digitalWrite(Led_red2, LOW);
    digitalWrite(Led_red1, LOW);
    digitalWrite(Led_yellow2, LOW);
    digitalWrite(Led_yellow1, LOW);
    digitalWrite(Led_green2, LOW);
    digitalWrite(Led_green1, LOW);
    digitalWrite(Led_blue2, HIGH);
    digitalWrite(Led_blue1, LOW);
  }
  
  else if ((cm >295) && (cm < 336)) {
    Serial.print("Blue 1 condition");
    digitalWrite(Led_red2, LOW);
    digitalWrite(Led_red1, LOW);
    digitalWrite(Led_yellow2, LOW);
    digitalWrite(Led_yellow1, LOW);
    digitalWrite(Led_green2, LOW);
    digitalWrite(Led_green1, LOW);
    digitalWrite(Led_blue2, LOW);
    digitalWrite(Led_blue1, HIGH);
  }
  
  else {
    Serial.print("You are in safe distance with others");
    digitalWrite(Led_red2, HIGH);
    digitalWrite(Led_red1, HIGH);
    digitalWrite(Led_yellow2, HIGH);
    digitalWrite(Led_yellow1, HIGH);
    digitalWrite(Led_green2, HIGH);
    digitalWrite(Led_green1, HIGH);
    digitalWrite(Led_blue2, HIGH);
    digitalWrite(Led_blue1, HIGH);
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

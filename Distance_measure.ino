/*Sensor:
  VCC 5V 
  GND GND 
  TRIG A7
  ECHO A8

LCD Screen:
  VCC 5V
  GND GND
  SDA A4
  SCL A5
*/



const int trigPin = 7;
const int echoPin = 8;
const int redLED = 9;
const int greenLED = 10;

#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  lcd.begin();
  lcd.backlight();
  Serial.begin(9600);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(redLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
}

void loop() {
  long duration, cm;
  
  // Send the ultrasonic pulse
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read the echo time
  duration = pulseIn(echoPin, HIGH);

  // Convert to cm
  cm = duration / 29 / 2;

  // Print to Serial Monitor
  Serial.print("Distance: ");
  Serial.print(cm);
  Serial.println(" cm");

  // Update LCD
  lcd.setCursor(0, 0);
  lcd.print("Distance: ");
  lcd.print(cm);
  lcd.print(" cm  ");

  // LED Logic
  if (cm > 10) {
    // Safe distance -> Green LED ON, Red LED OFF
    digitalWrite(greenLED, HIGH);
    digitalWrite(redLED, LOW);
  } else {
    // Close distance -> Green LED OFF, Red LED Blinking Faster
    digitalWrite(greenLED, LOW);
    
    int blinkSpeed = map(cm, 0, 10, 50, 500); // Closer = Faster blinking
    digitalWrite(redLED, HIGH);
    delay(blinkSpeed);
    digitalWrite(redLED, LOW);
    delay(blinkSpeed);
  }
}

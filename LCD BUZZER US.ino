#include <LiquidCrystal.h>

#define TRIG_PIN 7
#define ECHO_PIN 6
#define BUZZER_PIN 8

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  
  lcd.begin(16, 2);
  lcd.print("Distance: ");
}

void loop() {
  // Send a pulse to the ultrasonic sensor
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  // Measure the time it takes for the echo to return
  long duration = pulseIn(ECHO_PIN, HIGH);

  // Convert the duration to distance
  float distance = duration / 58.0;

  // Display the distance on the LCD screen
  lcd.setCursor(0, 1);
  lcd.print(distance);
  lcd.print(" cm");

  // Sound the buzzer if the distance is less than 10 cm
  if (distance < 10) {
    digitalWrite(BUZZER_PIN, HIGH);
  } else {
    digitalWrite(BUZZER_PIN, LOW);
  }

  // Wait a little bit before taking the next measurement
  delay(100);
}

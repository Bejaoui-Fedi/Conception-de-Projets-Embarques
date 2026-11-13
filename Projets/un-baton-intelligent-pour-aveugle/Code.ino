 #include "LiquidCrystal.h"  // Inclure la bibliothèque LCD

LiquidCrystal lcd(2, 3, 4, 5, 6, 7); // Paramètres de l'objet LCD : (rs, enable, d4, d5, d6, d7)
const int trigPin = 12; // Connexion du pin trig
const int echoPin = 11; // Connexion du pin echo
const int buzzerPin = 10; // Connexion du pin buzzer
const int vibrationMotorPin = 9; // Connexion du pin moteur de vibration

long duration;
int distanceCm;

void setup() {
  lcd.begin(16, 2);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(vibrationMotorPin, OUTPUT);

  lcd.setCursor(0, 0);
  lcd.print("  Distance    ");
  lcd.setCursor(0, 1);
  lcd.print("  Measurement  ");
  delay(2000);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("    Made By    ");
  lcd.setCursor(0, 1);
  lcd.print("    Fedi.BJ    ");
  delay(2000);

  lcd.clear();
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distanceCm = duration * 0.034 / 2;

  lcd.setCursor(0, 0);
  lcd.print("Distance Measur.");
  delay(10);
  lcd.setCursor(0, 1);
  lcd.print("Distance:");
  lcd.print(distanceCm);
  lcd.print(" Cm ");
  delay(10);

  // Vérifier si la distance est inférieure à 50 cm
  if (distanceCm < 50) {
    digitalWrite(buzzerPin, HIGH); // Activer le buzzer
    digitalWrite(vibrationMotorPin, HIGH); // Activer le moteur de vibration
  } else {
    digitalWrite(buzzerPin, LOW); // Désactiver le buzzer
    digitalWrite(vibrationMotorPin, LOW); // Désactiver le moteur de vibration
  }
}
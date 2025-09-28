#include <LiquidCrystal.h>

// Initialiser la bibliothèque avec les numéros des broches de l'interface
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);

const int gasSensorPin = A0;  // Capteur de gaz MQ-4 connecté à la broche numérique A0
const int buzzerPin = 1;     // Buzzer connecté à la broche numérique 1
const int ledPin = 10;         // LED rouge connectée à la broche numérique 10

void setup() {
  lcd.begin(16, 2);             // Configurer l'écran LCD avec 16 colonnes et 2 lignes
  pinMode(gasSensorPin, INPUT); // Définir la broche du capteur de gaz comme entrée
  pinMode(buzzerPin, OUTPUT);   // Définir la broche du buzzer comme sortie
  pinMode(ledPin, OUTPUT);       // Définir la broche de la LED rouge comme sortie
  lcd.print("Gas Sensor Init");
  delay(100);  // Afficher le message d'initialisation pendant 2 secondes
  lcd.clear();
}

void loop() {
  int gasState = digitalRead(gasSensorPin);  // Lire la valeur numérique du capteur de gaz

  // Effacer l'affichage précédent
  lcd.clear();

  lcd.setCursor(0, 0);
  lcd.print("Gas Sensor: ");
  
  // Vérifier l'état du capteur de gaz
  lcd.setCursor(0, 1);
  if (gasState == HIGH) {  // Gaz détecté (HIGH)
    lcd.print("Gas Detected   ");  // Afficher "Gas Detected" sur l'écran LCD
    digitalWrite(buzzerPin, HIGH); // Activer le buzzer
    digitalWrite(ledPin, HIGH);    // Allumer la LED rouge
    delay(100);                    // Attendre 500 ms
    digitalWrite(ledPin, LOW);     // Éteindre la LED rouge
    delay(100);                    // Attendre 500 ms
  } else {               // Gaz non détecté (LOW)
    lcd.print("Gas No Detected");  // Afficher "Gas No Detected" sur l'écran LCD
    digitalWrite(buzzerPin, LOW);  // Désactiver le buzzer
     digitalWrite(ledPin, LOW);     // Éteindre la LED rouge
  }

  delay(100);  // Actualiser la lecture toutes les secondes
}
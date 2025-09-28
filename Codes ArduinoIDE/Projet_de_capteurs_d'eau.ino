#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(7, 6, 5, 4, 3, 2); 

int resval = 0;  // holds the value
int respin = A3; // sensor pin used

// Définir les broches des LED
const int led1Pin = 8;  // LED pour Niveau Vide
const int led2Pin = 9;  // LED pour Niveau Faible
const int led3Pin = 10;  // LED pour Niveau Moyen
const int led4Pin = 11;  // LED pour Niveau Haut

void setup() { 
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2); 
  
  // Print a message to the LCD.
  lcd.print("  WATER LEVEL : "); 
   // Configurer les broches des LED comme sorties
  pinMode(led1Pin, OUTPUT);
  pinMode(led2Pin, OUTPUT);
  pinMode(led3Pin, OUTPUT);
  pinMode(led4Pin, OUTPUT);
} 

void loop() { 
  // set the cursor to column 0, line 1
  lcd.setCursor(0, 1); 
    
  resval = analogRead(respin); // Read data from analog pin and store it to resval variable
   
  if (resval <= 100) { 
    lcd.print("     EMPTY     "); 
      digitalWrite(led1Pin, HIGH);  // Allumer LED1
  } else if (resval > 100 && resval <= 300) { 
    lcd.print("      LOW      "); 
     digitalWrite(led2Pin, HIGH);  // Allumer LED2
  } else if (resval > 300 && resval <= 330) { 
    lcd.print("     MEDIUM    "); 
    digitalWrite(led3Pin, HIGH);  // Allumer LED3
  } else if (resval > 330) { 
    lcd.print("      HIGH     "); 
      digitalWrite(led4Pin, HIGH);  // Allumer LED4
  }

  delay(1000); 
}
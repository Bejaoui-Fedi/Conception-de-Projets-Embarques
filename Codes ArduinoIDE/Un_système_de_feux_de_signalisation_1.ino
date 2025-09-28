#include <LiquidCrystal.h> 
 
// Initialiser la bibliothèque avec les broches de l'interface 
LiquidCrystal lcd(8, 9, 10, 11, 12, 13); 
 
// Définir les numéros de broche pour les feux de signalisation 
const int feuRouge = 5; 
const int feuJaune = 6; 
const int feuVert = 7; 
 
// Définir le numéro de broche pour le panneau d'avertissement 
 
const int avertissement = 4; 
 
// Définir les numéros de broche pour l'afficheur BCD 
const int bcdA = 1; 
const int bcdB = 2; 
const int bcdC = 3; 
const int bcdD = 4; 
 
// Intervalles de temps pour chaque lumière en secondes 
const int tempsVert = 5;    // Durée du feu vert 
const int tempsJaune = 2;   // Durée du feu jaune 
const int tempsRouge = 5;   // Durée du feu rouge 
const int tempsAvertissement = 3;  // Durée du panneau d'avertissement 
 
void setup() { 
  // Initialiser les broches des feux de signalisation comme sorties 
  pinMode(feuRouge, OUTPUT); 
  pinMode(feuJaune, OUTPUT); 
  pinMode(feuVert, OUTPUT); 
   
  // Initialiser la broche du panneau d'avertissement comme sortie 
  pinMode(avertissement, OUTPUT); 
   
  // Initialiser les broches BCD comme sorties 
  pinMode(bcdA, OUTPUT); 
  pinMode(bcdB, OUTPUT); 
  pinMode(bcdC, OUTPUT); 
  pinMode(bcdD, OUTPUT); 
   
 
  // Initialiser l'afficheur LCD 
  lcd.begin(16, 2); 
  lcd.clear(); 
} 
 
void loop() { 
  // Feu vert allumé, autres feux éteints 
  allumerFeu(feuVert, tempsVert, "Bonne route"); 
 
  // Feu jaune allumé, autres feux éteints 
  allumerFeu(feuJaune, tempsJaune, "Prends soi de toi"); 
 
  // Feu rouge allumé, autres feux éteints 
  allumerFeu(feuRouge, tempsRouge, "Arrete"); 
 
  // Feu rouge et panneau d'avertissement allumés 
  digitalWrite(feuRouge, HIGH); 
  digitalWrite(avertissement, HIGH); 
  lcd.clear(); 
  lcd.setCursor(0, 0); 
  lcd.print("Arrête"); 
  afficherTemps(tempsAvertissement); 
  delay(tempsAvertissement * 1000); 
} 
 
// Fonction pour allumer un feu et afficher un message 
void allumerFeu(int feu, int temps, String message) { 
  digitalWrite(feuRouge, feu == feuRouge ? HIGH : LOW); 
  digitalWrite(feuJaune, feu == feuJaune ? HIGH : LOW); 

  digitalWrite(feuVert, feu == feuVert ? HIGH : LOW); 
  digitalWrite(avertissement, LOW); 
  lcd.clear(); 
  lcd.setCursor(0, 0); 
  lcd.print(message); 
  afficherTemps(temps); 
  delay(temps * 1000); 
  digitalWrite(feu, LOW); 
} 
 
// Fonction pour afficher le temps restant sur l'afficheur BCD 
void afficherTemps(int temps) { 
  for (int i = temps; i >= 0; i--) { 
    digitalWrite(bcdA, i & 0x01); 
    digitalWrite(bcdB, (i >> 1) & 0x01); 
    digitalWrite(bcdC, (i >> 2) & 0x01); 
    digitalWrite(bcdD, (i >> 3) & 0x01); 
    delay(1000); // Attendre une seconde avant de décrémenter 
  } 
} 
 #include <LiquidCrystal.h>

// Initialiser la bibliothèque avec les broches de l'interface
LiquidCrystal lcd(8, 9, 10, 11, 12, 13);

// Définir les numéros de broche pour les feux de signalisation
const int feuRouge = 5;
const int feuJaune = 6;
const int feuVert = 7;

// Définir le numéro de broche pour le panneau d'avertissement
const int avertissement = 0; // Nouvelle broche pour éviter la confusion

// Définir les numéros de broche pour l'afficheur BCD
const int bcdA = 1;
const int bcdB = 2;
const int bcdC = 3;
const int bcdD = 4;

// Définir les broches pour le capteur à ultrasons
const int trigPin = A1;
const int echoPin = A0;

// Seuil de détection de distance (en cm)
const int seuilDistance = 300;

// Nombre de mesures pour le lissage
const int nombreMesures = 10;

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

  // Initialiser les broches du capteur à ultrasons
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
  // Initialiser l'afficheur LCD
  lcd.begin(16, 2);
  lcd.clear();
}

void loop() {
  if (detecterVehicule()) {
    // Feu vert allumé, autres feux éteints
    allumerFeu(feuVert, tempsVert, "Bonne route");

    // Feu jaune allumé, autres feux éteints
    allumerFeu(feuJaune, tempsJaune, "Prends soin de toi");

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
    digitalWrite(avertissement, LOW);
  } else {
    // Si aucun véhicule n'est détecté, éteindre tous les feux
    eteindreFeux();
  }
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

// Fonction pour détecter un véhicule avec le capteur à ultrasons
bool detecterVehicule() {
  long totalDistance = 0;
  int validMesures = 0;

  for (int i = 0; i < nombreMesures; i++) {
    long distance = mesurerDistance();
    // Ignorer les mesures aberrantes
    if (distance > 0 && distance < 400) {
      totalDistance += distance;
      validMesures++;
    }
    delay(50); // Attendre un peu entre chaque mesure
  }

  if (validMesures > 0) {
    long moyenneDistance = totalDistance / validMesures;
    return moyenneDistance <= seuilDistance;
  } else {
    return false;
  }
}

// Fonction pour mesurer la distance avec le capteur à ultrasons
long mesurerDistance() {
  // Envoyer une impulsion ultrasonique
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Lire la durée de l'impulsion de retour
  long duration = pulseIn(echoPin, HIGH);

  // Calculer la distance en centimètres
  long distance = duration * 0.034 / 2;

  return distance;
}

// Fonction pour éteindre tous les feux
void eteindreFeux() {
  digitalWrite(feuRouge, LOW);
  digitalWrite(feuJaune, LOW);
  digitalWrite(feuVert, LOW);
  digitalWrite(avertissement, LOW);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("En attente...");
}
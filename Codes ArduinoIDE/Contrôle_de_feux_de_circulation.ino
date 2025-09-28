//Define PIN Number

const int R1 = 0;   // Pin LED RED EAST
const int Y1 = 1;   // Pin LED YELLLOW EAST
const int G1 = 2;   // Pin LED GREEN EAST
const int R2 = 3;   // Pin LED RED SOUTH
const int Y2 = 4;   // Pin LED YELLLOW SOUTH
const int G2 = 5;   // Pin LED GREEN SOUTH
const int R3 = 6;   // Pin LED RED WEST
const int Y3 = 7;   // Pin LED YELLLOW WEST
const int G3 = 8;   // Pin LED GREEN WEST
const int R4 = 9;   // Pin LED RED NORTH
const int Y4 = 10;  // Pin LED YELLLOW NORTH
const int G4 = 11;  // Pin LED GREEN NORTH
const int BZ = 12;  // Pin Buzzer

int looping = 0; 

//Define PIN Mode

void setup (){
  pinMode(R1, OUTPUT);
  pinMode(Y1, OUTPUT);
  pinMode(G1, OUTPUT);
  pinMode(R2, OUTPUT);
  pinMode(Y2, OUTPUT);
  pinMode(G2, OUTPUT);
  pinMode(R3, OUTPUT);
  pinMode(Y3, OUTPUT);
  pinMode(G3, OUTPUT);
  pinMode(R4, OUTPUT);
  pinMode(Y4, OUTPUT);
  pinMode(G4, OUTPUT);
  pinMode(BZ, OUTPUT);
}

void loop(){
  
LEDEAST();
LEDSOUTH();
LEDWEST();
LEDNORTH();
looping = looping +1;
}

void LEDEAST(){
  digitalWrite(G1, HIGH);
  digitalWrite(R2, HIGH);
  digitalWrite(R3, HIGH);
  digitalWrite(R4, HIGH);
  delay(3000);    // nyala lampu hijau 3 detik

  digitalWrite(G1, LOW);
  digitalWrite(Y1, HIGH);
  digitalWrite(Y2, HIGH);
  digitalWrite(R2, LOW);
  digitalWrite(BZ, HIGH);
  delay(500);   // nyala lampu kuning 1/2 detik
  digitalWrite(Y1, LOW);
  digitalWrite(Y2, LOW);
  digitalWrite(BZ, LOW);
  delay(100);
  digitalWrite(R1, HIGH);
  
}

void LEDSOUTH(){
  digitalWrite(G2, HIGH);
  digitalWrite(R2, LOW);
  digitalWrite(R3, HIGH);
  digitalWrite(R4, HIGH);
  delay(3000);    // nyala lampu hijau 3 detik

  digitalWrite(G2, LOW);
  digitalWrite(Y2, HIGH);
  digitalWrite(Y3, HIGH);
  digitalWrite(R3, LOW);
  digitalWrite(BZ, HIGH);
  delay(500);   // nyala lampu kuning 1/2 detik
  digitalWrite(Y3, LOW);
  digitalWrite(Y2, LOW);
  digitalWrite(BZ, LOW);
  delay(100);
  digitalWrite(R2, HIGH);
  
}

void LEDWEST(){
  digitalWrite(G3, HIGH);
  digitalWrite(R1, HIGH);
  digitalWrite(R3, LOW);
  digitalWrite(R4, HIGH);
  delay(3000);    // nyala lampu hijau 3 detik

  digitalWrite(G3, LOW);
  digitalWrite(Y3, HIGH);
  digitalWrite(Y4, HIGH);
  digitalWrite(R4, LOW);
  digitalWrite(BZ, HIGH);
  delay(500);   // nyala lampu kuning 1/2 detik
  digitalWrite(Y3, LOW);
  digitalWrite(Y4, LOW);
  digitalWrite(BZ, LOW);
  delay(100);
  digitalWrite(R3, HIGH);
  
}

void LEDNORTH(){
  digitalWrite(G4, HIGH);
  digitalWrite(R1, HIGH);
  digitalWrite(R2, HIGH);
  digitalWrite(R3, HIGH);
  digitalWrite(R4, LOW);
  delay(3000);    // nyala lampu hijau 3 detik

  digitalWrite(G4, LOW);
  digitalWrite(Y4, HIGH);
  digitalWrite(Y1, HIGH);
  digitalWrite(R1, LOW);
  digitalWrite(BZ, HIGH);
  delay(500);   // nyala lampu kuning 1/2 detik
  digitalWrite(Y4, LOW);
  digitalWrite(Y1, LOW);
  digitalWrite(BZ, LOW);
  delay(100);
  digitalWrite(R4, HIGH);
  
}
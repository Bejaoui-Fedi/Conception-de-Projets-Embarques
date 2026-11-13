#include <LiquidCrystal.h>
#define ir1 3
#define ir2 4
#define lamp1 5
#define lamp2 2
#define lamp3 6
#define fan 7
#define lm35 A0

//variables
int temp=0;
boolean irVal1;
boolean irVal2;
int peopleInside=0;
int peopleIn=0;
int peopleOut=0;

LiquidCrystal lcd(13,12,11,10,9,8);


void setup() {
 lcd.begin(20,4);
 pinMode(ir1,INPUT);
  pinMode(ir2,INPUT);

  pinMode(lamp1,OUTPUT);
  pinMode(lamp2,OUTPUT);
  pinMode(lamp3,OUTPUT);
  pinMode(fan,OUTPUT);
pinMode( lm35 ,INPUT);

 digitalWrite(lamp1,LOW);
 digitalWrite(lamp2,LOW);
}

void loop() {
irVal1=digitalRead(ir1);
irVal2=digitalRead(ir2);
temp=analogRead(lm35)*500/1023; // 1mv/1c
lcd.setCursor(0,0);
lcd.print("ROOM LIGHT CONTROL");
lcd.setCursor(0,1);
lcd.print("People In= ");
lcd.print(peopleIn);
lcd.setCursor(0,2);
lcd.print("People Out= ");
lcd.print(peopleOut);
lcd.setCursor(0,3);
lcd.print("People Inside= ");
lcd.print(peopleInside);
temperature();
counting ();
  peopleInside=peopleIn- peopleOut;
  if (peopleInside==1){
  digitalWrite(lamp1,HIGH);
  digitalWrite(lamp2,LOW);
  digitalWrite(lamp3,LOW);
  }
else if (peopleInside>=2&&peopleInside<5){
  digitalWrite(lamp1,HIGH);
  digitalWrite(lamp2,LOW);
  digitalWrite(lamp3,LOW);
}
 else if (peopleInside==5){
  digitalWrite(lamp1,HIGH);
    digitalWrite(lamp2,HIGH);
 digitalWrite(lamp3,LOW);
  }
else if (peopleInside>=5&&peopleInside<10){
  digitalWrite(lamp1,HIGH);
  digitalWrite(lamp2,HIGH);
  digitalWrite(lamp3,LOW);
}
 else if (peopleInside>=10){
  digitalWrite(lamp1,HIGH);
    digitalWrite(lamp2,HIGH);
  digitalWrite(lamp3,HIGH);
  }
else {
digitalWrite(lamp1,LOW);
    digitalWrite(lamp2,LOW);
  digitalWrite(lamp3,LOW);
}
}

void counting (){
  if (irVal1==HIGH){
delay(1000);
if(irVal1==HIGH){
    peopleIn++;}
  }
  if (irVal2==HIGH){
delay(1000);
if (irVal2==HIGH){
    peopleOut++;}
  }

}


void temperature(){
if (temp>=30){
digitalWrite(fan,HIGH);
}
else {
digitalWrite(fan,LOW);
}
}
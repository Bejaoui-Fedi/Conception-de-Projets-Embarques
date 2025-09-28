#include <LiquidCrystal.h>
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);
#define FlamePin A0
#define buzzer 1
void setup() {
   lcd.begin(16, 2);
   pinMode(FlamePin, INPUT_PULLUP);
   pinMode(buzzer, OUTPUT);
    lcd.setCursor(5, 0);
    lcd.print("FLAME");
    lcd.setCursor(3, 1);
    lcd.print("DETECTOR");
    delay(1000);
    lcd.clear();
}
void loop() {
int Flame = digitalRead(FlamePin);
if(Flame==HIGH)
{
  digitalWrite(buzzer, HIGH);
  lcd.setCursor(5, 0);
  lcd.print("FLAME");
   lcd.setCursor(3, 1);
  lcd.print("DETECTED");
  delay(200);
  lcd.clear();
  delay(200);
}
else
{
 digitalWrite(buzzer, LOW); 
 lcd.setCursor(3,0);
 lcd.print("No FLAME");
 lcd.setCursor(3,1);
 lcd.print("DETECTED");
}
}
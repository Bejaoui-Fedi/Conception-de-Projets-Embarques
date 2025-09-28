#include "LiquidCrystal.h"         
const int rs = 2, en = 3, d4 = 4, d5 = 5, d6 = 6, d7 = 7;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
float temp;            
void setup() {
  Serial.begin(9600);
  analogReference(INTERNAL);
  lcd.begin (16,2);                                    
  lcd.setCursor(0, 0);
  lcd.print("   Made by    ");      
  lcd.setCursor(0, 1);
  lcd.print("   Fedi.BJ   ");
  delay (100);
  lcd.clear();                                        
}
void loop() {
  temp = analogRead(A1);                                                   
  temp=temp*1100/(1024*10);
  lcd.print("TEMP: ");
  lcd.print(temp);
  lcd.println("C");
  delay(500);
  lcd.clear();                                       
}
const int IR1=A0;
const int IR2=A1;
const int LedPin[]={0,2,3,4,5,6,7,8,9,10,11,12,13};
int i,j;
int D=100;
void setup() 
{
  // put your setup code here, to run once:
  Serial.begin(9600);
  //Serial.println("LedPin[]");
  for(i=0;i<=12;i++)
  {
    pinMode(LedPin[i],OUTPUT);
    //Serial.println(LedPin[i]);
    //delay(100);
  }
  pinMode(IR1,INPUT);
  pinMode(IR2,INPUT);
}

void loop() 
{
  // put your main code here, to run repeatedly:
  if(digitalRead(IR1)==HIGH)
  {
    LedsUpON();
  }
  else if(digitalRead(IR2)==HIGH)
  {
    LedsDownON();
  }
  else
  {
    LedsOFF();
  }
}


void LedsUpON()
{
  digitalWrite(0,HIGH);
  delay(D);
  digitalWrite(2,HIGH);
  delay(D);
  digitalWrite(3,HIGH);
  delay(D);
  digitalWrite(4,HIGH);
  delay(D);
  digitalWrite(5,HIGH);
  delay(D);
  digitalWrite(6,HIGH);
  delay(D);
  digitalWrite(7,HIGH);
  delay(D);
  digitalWrite(8,HIGH);
  delay(D);
  digitalWrite(9,HIGH);
  delay(D);
  digitalWrite(10,HIGH);
  delay(D);
  digitalWrite(11,HIGH);
  delay(D);
  digitalWrite(12,HIGH);
  delay(D);
  digitalWrite(13,HIGH);
  delay(D);
}


void LedsDownON()
{
  digitalWrite(13,HIGH);
  delay(D);
  digitalWrite(12,HIGH);
  delay(D);
  digitalWrite(11,HIGH);
  delay(D);
  digitalWrite(10,HIGH);
  delay(D);
  digitalWrite(9,HIGH);
  delay(D);
  digitalWrite(8,HIGH);
  delay(D);
  digitalWrite(7,HIGH);
  delay(D);
  digitalWrite(6,HIGH);
  delay(D);
  digitalWrite(5,HIGH);
  delay(D);
  digitalWrite(4,HIGH);
  delay(D);
  digitalWrite(3,HIGH);
  delay(D);
  digitalWrite(2,HIGH);
  delay(D);
  digitalWrite(0,HIGH);
  delay(D);
}


void LedsOFF()
{
  for(i=0;i<=12;i++)
  {
    digitalWrite(LedPin[i],LOW);
  }
} 
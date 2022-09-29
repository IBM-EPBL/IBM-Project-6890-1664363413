#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 13, 11, 10, 9, 8);
int pirPin=7;
int pirInput=0;
int bulbPin=6;
int photoValue=0;
int tempReading=0,temp1=0,temperature=0;
int fanPin=5;
int gasReading=0;
int greenLed=4;
int yellowLed=3;
int redLed=2;
int piezoPin=0;
void scrollScreenSaver() {
	
	lcd.clear() ;
  	lcd.setCursor(15, 0);            
	lcd.print("Welcome");   
	lcd.setCursor(15, 1); 
	lcd.print("to my home");	
	
    for (int positionCounter = 0; positionCounter < 22; positionCounter++) {
		lcd.scrollDisplayLeft();
		delay(50);    
	}
}  
void setup()
{
  lcd.begin(16, 2);
  lcd.print("hello, world!");
  pinMode(pirPin, INPUT);
  pinMode(bulbPin, OUTPUT);
  pinMode(greenLed,OUTPUT);
  pinMode(yellowLed,OUTPUT);
  pinMode(redLed,OUTPUT);
  pinMode(piezoPin,OUTPUT);
  
  Serial.begin(9600);
  
}

void loop()
{
  lcd.setCursor(0, 1);
  lcd.print(millis() / 1000);
  pirInput=digitalRead(pirPin);
  photoValue=analogRead(A0);
  Serial.println(photoValue);
  tempReading=analogRead(A1);
  temperature=(5000.0/1024.0*tempReading/10.0);
  Serial.println(temperature);
  
  gasReading=analogRead(A2);
  Serial.println(gasReading);
  Serial.println(".........................");
  digitalWrite(greenLed,gasReading>100 ? HIGH : LOW);
  digitalWrite(yellowLed,gasReading>200 ? HIGH : LOW);
  digitalWrite(redLed,gasReading>300 ? HIGH : LOW);
  
  
  if(pirInput==HIGH)
  {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Motion Detected");
    if(photoValue<300)
    {
      digitalWrite(bulbPin,HIGH);
      lcd.setCursor(0,1);
      lcd.print("Light is on");
      delay(1000);
    }
    if(temperature>25)
    {
      digitalWrite(fanPin,HIGH);
      lcd.setCursor(0,1);
      lcd.print("                         ");
      lcd.setCursor(0,1);
      lcd.print("Fan is on");
      delay(1000);
    }
        
  }
  else
  {
    scrollScreenSaver() ;
  }
  /*digitalWrite(13, HIGH);
  delay(1000); 
  digitalWrite(13, LOW);
  delay(1000); 
}
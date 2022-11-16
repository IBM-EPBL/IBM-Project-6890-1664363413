#include <Servo.h>

int output1Value = 0;
int sen1Value = 0;
int sen2Value = 0;
int const gas_sensor = A1;
int const LDR = A0;
int limit = 400;

long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);  
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  return pulseIn(echoPin, HIGH);
}

Servo servo_7;

void setup()
{
   Serial.begin(9600);		
  pinMode(A0, INPUT);		
  pinMode(A1,INPUT);      	
  pinMode(13, OUTPUT);		
  servo_7.attach(7, 500, 2500); 

  pinMode(8,OUTPUT);     	
  pinMode(9, INPUT);		
  pinMode(10, OUTPUT);		
  pinMode(4, OUTPUT);		
  pinMode(3, OUTPUT);		
 
}

void loop()
{
 
    int val1 = analogRead(LDR);
  if (val1 > 500) 
  	{
    	digitalWrite(13, LOW);
    Serial.print("Bulb ON = ");
    Serial.print(val1);
  	} 
  else 
  	{
    	digitalWrite(13, HIGH);
     Serial.print("Bulb OFF = ");
    Serial.print(val1);
  	}

  sen2Value = digitalRead(9);
  if (sen2Value == 0) 
  	{
    	digitalWrite(10, LOW); 
    	digitalWrite(4, HIGH); 
    	digitalWrite(3, LOW); 
    Serial.print("     || NO Motion Detected    " );
  	}
 
  if (sen2Value == 1) 
  	{
    	digitalWrite(10, HIGH);//npn as switch ON
    delay(5000);
    	digitalWrite(4, LOW); 
    	digitalWrite(3, HIGH);
     Serial.print(" 	   || Motion Detected!      " );
  	
int val = analogRead(gas_sensor);      
  Serial.print("|| Gas Sensor Value = ");
  Serial.print(val);				   
//val = map(val, 300, 750, 0, 100); 
  if (val > limit)
  	{
    	tone(8, 650);
  	}
 	delay(300);
 	noTone(8);
 
  sen1Value = 0.01723 * readUltrasonicDistance(6, 6);

  if (sen1Value < 100) 
  	{
    	servo_7.write(90);
    Serial.print(" 	  || Door Open!  ; Distance = ");
    Serial.print(sen1Value);
   Serial.print("\n");
 
  	} 
  else 
  	{
    	servo_7.write(0);
    Serial.print(" 	  || Door Closed! ; Distance =  ");
    Serial.print(sen1Value);
    Serial.print("\n");
  }
  delay(10); 
}
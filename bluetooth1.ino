int brightness = 0;    // how bright the LED is
int fadeAmount = 5; 
int led = 3;
int inPin = 4;
int inPin2 = 7;
int ledPin = 6;
int val2 = 0;
int val = 0; 
const int motorPin1  = 11;  
const int motorPin2  = 10; 
const int motorPin3  = 8;  
const int motorPin4  = 9; 
int state; int flag=0;
void setup()
{
 pinMode(motorPin1, OUTPUT);
 pinMode(motorPin2, OUTPUT);
 pinMode(motorPin3, OUTPUT);
 pinMode(motorPin4, OUTPUT);
 pinMode(ledPin, OUTPUT);
 pinMode(inPin, INPUT); 
 pinMode(inPin2, INPUT); 
 pinMode(led, OUTPUT);
Serial.begin(9600);
delay(1000); }

void loop(){
  
  analogWrite(led, brightness);
   brightness = brightness + fadeAmount;
   
   if (brightness <= 0 || brightness >= 255) {
    fadeAmount = -fadeAmount;
  }
  delay(30);

val = digitalRead(inPin);
val2 = digitalRead(inPin2);


if(Serial.available() > 0)

{

state = Serial.read();

flag=0;

} 

if (state == 'U')

{

digitalWrite(motorPin1, 0);
digitalWrite(motorPin2, HIGH);
digitalWrite(motorPin3, HIGH);
digitalWrite(motorPin4, 0);
delay(2000);
digitalWrite(motorPin1, 0);
digitalWrite(motorPin2, 0);
digitalWrite(motorPin3, 0);
digitalWrite(motorPin4, 0);
Serial.println("Both Up");
state = 0;
}

else if (state == 'D')
{

digitalWrite(motorPin1, HIGH);
digitalWrite(motorPin2, 0);
digitalWrite(motorPin3, 0);
digitalWrite(motorPin4, HIGH);
delay(2000);
digitalWrite(motorPin1, 0);
digitalWrite(motorPin2, 0);
digitalWrite(motorPin3, 0);
digitalWrite(motorPin4, 0);

Serial.println("Both Down");
state = 0;
}
if (state == 'W')

{

digitalWrite(motorPin1, 0);
digitalWrite(motorPin2, HIGH);
delay(2000);
digitalWrite(motorPin1, 0);
digitalWrite(motorPin2, 0);
Serial.println("Right Up");
state = 0;
}

else if (state == 'L')
{

digitalWrite(motorPin1, HIGH);
digitalWrite(motorPin2, 0);
delay(2000);
digitalWrite(motorPin1, 0);
digitalWrite(motorPin2, 0);                                    

Serial.println("Right Down");
state = 0;
}
if (state == 'K')

{

digitalWrite(motorPin3, HIGH);
digitalWrite(motorPin4, 0);
delay(2000);
digitalWrite(motorPin3, 0);
digitalWrite(motorPin4, 0);
Serial.println("Left Up");
state = 0;
}

else if (state == 'I')
{

digitalWrite(motorPin3, 0);
digitalWrite(motorPin4, HIGH);
delay(2000);
digitalWrite(motorPin3, 0);
digitalWrite(motorPin4, 0);

Serial.println("Left Down");
state = 0;
}
if (state == 'E')

{

digitalWrite(motorPin1, 0);
digitalWrite(motorPin2, HIGH);
digitalWrite(motorPin3, HIGH);
digitalWrite(motorPin4, 0);
delay(1000);
digitalWrite(motorPin1, 0);
digitalWrite(motorPin2, 0);
digitalWrite(motorPin3, 0);
digitalWrite(motorPin4, 0);
Serial.println("Both Up");
state = 0;
}
if (state == 'R')

{

digitalWrite(motorPin1, HIGH);
digitalWrite(motorPin2, 0);
digitalWrite(motorPin3, 0);
digitalWrite(motorPin4, HIGH);
delay(1000);
digitalWrite(motorPin1, 0);
digitalWrite(motorPin2, 0);
digitalWrite(motorPin3, 0);
digitalWrite(motorPin4, 0);
Serial.println("Both Up");
state = 0;
}
if (state == 'P')
{
  digitalWrite(ledPin, HIGH);
  state = 0;
}
if (state == 'A')
{
  digitalWrite(ledPin, LOW);
  state = 0;
}
}

#include<SoftwareSerial.h>
SoftwareSerial mySerial(10,11);
int x=0;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
mySerial.begin(9600);
pinMode(8,OUTPUT);
}

void loop() {
String stringSix;
String stringSeven;
  // put your main code here, to run repeatedly:
String stringOne=String("AT+C00");
String stringTwo=String("AT+C0");
String stringThree=String("AT+C");
String stringFive=String();
for(x=0;x<128;x++){
digitalWrite(8,LOW);
mySerial.println("AT");
if(x<10){
stringFive=stringOne + x;
Serial.println(stringFive);
mySerial.println(stringFive);
digitalWrite(8,HIGH);
delay(100);
if(mySerial.available()){
stringSix="channel detected";
stringSeven=stringSix + x;
Serial.println(stringSeven);
}
}
if(x>10 && x<100){
stringFive=stringTwo+ x;
mySerial.println(stringFive);
Serial.println(stringFive);
digitalWrite(8,HIGH);
delay(100);
if(mySerial.available()){
stringSix="channel detected";
stringSeven=stringSix + x;
Serial.println(stringSeven);
}
}
if(x>99){
stringFive=stringThree+ x;
mySerial.println(stringFive);
Serial.println(stringFive);
digitalWrite(8,HIGH);
delay(100);
if(mySerial.available()){
stringSix="channel detected";
stringSeven=stringSix + x;
Serial.println(stringSeven);
}
}
}
  if(mySerial.available()){
Serial.write(mySerial.read());
}

if(Serial.available())
{
  mySerial.write(Serial.read());
}

}

#include<SoftwareSerial.h>
SoftwareSerial mySerial(10,11);
void setup() {
  // put your setup code here, to run once:
Serial.begin(2400);
mySerial.begin(2400);
pinMode(13, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
mySerial.write('1');
delay(1000);
mySerial.write('0');
delay(1000);
  if(mySerial.available()){
digitalWrite(13,0);
Serial.write(mySerial.read());
}
if(Serial.available())
{
  mySerial.write(Serial.read());
}
} 

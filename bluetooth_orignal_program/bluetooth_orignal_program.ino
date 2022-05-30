#include<SoftwareSerial.h>
SoftwareSerial mySerial(10,11);
void setup() {
  // put your setup code here, to run once:
Serial.begin(1200);
mySerial.begin(1200);
pinMode(13, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
int y=0;
mySerial.write('y');
delay(1000);
y=1;
mySerial.write('y');
  if(mySerial.available()){
digitalWrite(13,y);
Serial.write(mySerial.read());
}
if(Serial.available())
{
  mySerial.write(Serial.read());
}
} 

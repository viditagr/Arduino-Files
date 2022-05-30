#include<SoftwareSerial.h>
SoftwareSerial mySerial(10,11);
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
mySerial.begin(9600);
pinMode(13,OUTPUT);
}

void loop() {
while(mySerial.available()){
char data=mySerial.read();
  if(data=='1'){
    digitalWrite(13,HIGH);
  }
  if(data=='0'){
    digitalWrite(13,LOW);
  }
}
if(Serial.available())
{
  mySerial.write(Serial.read());
}

  
  // put your main code here, to run repeatedly:

}

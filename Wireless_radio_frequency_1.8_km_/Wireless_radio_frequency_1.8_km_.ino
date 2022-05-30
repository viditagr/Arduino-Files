#include<SoftwareSerial.h>
SoftwareSerial mySerial(10,11);
void setup() {
  // put your setup code here, to run once:
Serial.begin(2400);
mySerial.begin(2400);
}

void loop() {
while(mySerial.available()){
char data=mySerial.read();
 
  }
 
  }

if(Serial.available())
{
  mySerial.write(Serial.read());
}

  
  // put your main code here, to run repeatedly:

}

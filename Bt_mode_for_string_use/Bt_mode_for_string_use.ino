#include<SoftwareSerial.h>
SoftwareSerial BTSerial(10,11);
String data"";
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  BTSerial.begin(9600);
pinMode(13,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
char C;
while(BTSerial.available()){
  delay(10);
  c=BTSerial.read();
  data=data+c;
}
if(data.length()>0){
  Serial.println(data);
  if(data=="ON"){
    digitalWrite(13,HIGH);
  }
  if(data=="OFF"){
    digitalWrite(13,LOW);
  }
  data="";
}
if(Serial.available()){
  BTSerial.write(Serial.read());
}
}

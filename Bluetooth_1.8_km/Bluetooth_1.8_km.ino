#include<SoftwareSerial.h>
SoftwareSerial mySerial(10,11);
int x=0;

void setup() {
  // put your setup code here, to run once:
Serial.begin(1200);
mySerial.begin(1200);
}

void loop() {
  // put your main code here, to run repeatedly:
String stringOne=String("AT+C00");
String stringTwo=String("AT+C0");
String stringThree=String("AT+C");
String stringFive=String();
//for(x=0;x<128;x++){
//if(x<9){
//stringFive=stringOne+ x;
//mySerial.println(stringFive);
//Serial.println(stringFive);
//}
//if(x>9 && x<99){
//stringFive=stringTwo+ x;
//mySerial.println(stringFive);
//Serial.println(stringFive);
//}
//if(x>99){
//stringFive=stringThree+ x;  

//mySerial.println(stringFive);
    //Serial.println(stringFive);
    //}
   //}
mySerial.write("AT+C009");

  if(mySerial.available()){
Serial.write(mySerial.read());
}
if(Serial.available())
{
  mySerial.write(Serial.read());
}

}

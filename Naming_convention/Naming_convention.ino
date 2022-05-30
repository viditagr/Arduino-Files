#include <SoftwareSerial.h>
SoftwareSerial mySerial(10, 11);
 String input;
 int why;
 int why2;
 String inputreal;
void setup() {
  // put your setup code here, to run once:
pinMode(8,OUTPUT);
digitalWrite(8,HIGH);
Serial.begin(9600);
mySerial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
while(mySerial.available()){
input =  mySerial.readStringUntil("!");
why = input.indexOf("TEMPS#");
why2 = input.indexOf("#TEMPE");
inputreal = input.substring(why+6,why2);
Serial.print("Temperature = ");
Serial.println(inputreal); 
input =  mySerial.readStringUntil("@");
why = input.indexOf("HUMS#");
why2 = input.indexOf("#HUME");
inputreal = input.substring(why+5,why2);
Serial.print("Humidity = ");
Serial.println(inputreal); 
input =  mySerial.readStringUntil("*");
why = input.indexOf("PRES#");
why2 = input.indexOf("#PREE");
inputreal = input.substring(why+5,why2);
Serial.print("Pressure = ");
Serial.println(inputreal); 
input =  mySerial.readStringUntil("$");
why = input.indexOf("ALTS#");
why2 = input.indexOf("#ALTE");
inputreal = input.substring(why+5,why2);
Serial.print("Altitude = ");
Serial.println(inputreal); 
input =  mySerial.readStringUntil("%");
why = input.indexOf("AQS#");
why2 = input.indexOf("#AQE");
inputreal = input.substring(why+4,why2);
Serial.print("Air Quality = ");
Serial.println(inputreal); 
input =  mySerial.readStringUntil("^");
why = input.indexOf("LIS#");
why2 = input.indexOf("#LIE");
inputreal = input.substring(why+4,why2);
Serial.print("Light Intensity = ");
Serial.println(inputreal); 
}
}

#include <SoftwareSerial.h>
SoftwareSerial mySerial(2, 3);
#include "DHT.h"
#define DHTPIN 4
#define DHTTYPE 11
DHT dht(DHTPIN, DHTTYPE);
 float h = dht.readHumidity();
  float t = dht.readTemperature();
void setup() {
  // put your setup code here, to run once:
pinMode(4,INPUT);
pinMode(A0,INPUT);
pinMode(A3,INPUT);
pinMode(A4,INPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
float l = analogRead(A0);
int m = 1;
int u = 1;
mySerial.print("TEMPS#");
mySerial.print(t);
mySerial.println("#TEMPSE");
mySerial.print("HUMS#");
mySerial.print(h);
mySerial.println("#HUMSE");
mySerial.print("PRES#");
mySerial.print(m);
mySerial.println("#PRESE");
mySerial.print("ALTS#");
mySerial.print(u);
mySerial.println("#ALTSE");
mySerial.print("AQS#");
mySerial.print(l);
mySerial.println("#AQSE");
delay(1000);
}

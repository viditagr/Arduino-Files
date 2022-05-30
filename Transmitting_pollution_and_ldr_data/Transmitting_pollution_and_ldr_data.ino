#include<SoftwareSerial.h>
SoftwareSerial mySerial(2,3);
#include "DHT.h"
#define DHTPIN 4
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);
int MQ135_analog_pin = A0;
int MQ135_digital_pin = 2;
int LDR= A2;
int RX= 2;
int TX= 3;
int Setpin = 8;
void setup() {
  // put your setup code here, to run once:
dht.begin();
Serial.begin(9600);
mySerial.begin(9600);
pinMode(MQ135_analog_pin,INPUT);
pinMode(MQ135_digital_pin,INPUT);
pinMode(LDR,INPUT);
pinMode(Setpin,OUTPUT);
pinMode(A4,INPUT);
pinMode(A3,INPUT);
}


void loop() {
  // put your main code here, to run repeatedly:
int MQ135_analog_data=analogRead(MQ135_analog_pin);
int MQ135_digital_data=digitalRead(MQ135_digital_pin);
//int LDR_data=analogRead(LDR);
float Humidity_data = dht.readTemperature();
float Temperature_data = dht.readHumidity();
String stringMQ135_analogdata=String("AQS#") + MQ135_analog_data + String("#AQE");
String stringhumidity_data=String("HUMS#") + Humidity_data + String("#HUME");
//String stringLDR_data=String("LIS#") + LDR_data + String("#LIS");
String stringtemperature_data=String("TEMPS#") + Temperature_data + String("#TEMPE");
float pressure_data=1.1;
float Altitude_data=202.5;
String stringpressure_data=String("PRES#") + pressure_data + String("#PREE");
String stringAltitude_data=String("ALTS#") + Altitude_data + String("#ALTE");
mySerial.println(stringtemperature_data);
mySerial.println(stringhumidity_data);
mySerial.println(stringpressure_data);
mySerial.println(stringAltitude_data);
mySerial.println(stringMQ135_analogdata);
delay(1000);
/*Serial.println(stringtemperature_data);
Serial.println(stringhumidity_data);
Serial.println(stringpressure_data);
Serial.println(stringAltitude_data);
Serial.println(stringMQ135_analogdata);
Serial.println(stringLDR_data);
delay(1000);
if(mySerial.available()){
Serial.write(mySerial.read());

if(Serial.available())
{
  mySerial.write(Serial.read());
}

}*/
}

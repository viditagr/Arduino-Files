#include "UbidotsMicroESP8266.h"
#define TOKEN "A1E-u1T1iUhVI2U8HqGJ7ly9091NSVdwAR"
#define WIFISSID "Technomentis"
#define PASSWORD "usetmswifi"



Ubidots client(TOKEN);
void setup() {
  // put your setup code here, to run once:
Serial.begin(115200);
delay(10);
client.wifiConnection(WIFISSID, PASSWORD);
}

void loop() {
  // put your main code here, to run repeatedly:
int value = analogRead(A0);
client.add("light intensity", value);
client.sendAll(true);
}

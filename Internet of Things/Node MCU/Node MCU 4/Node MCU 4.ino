#include <ESP8266WiFi.h>

String apiKey = "C5KYNFGY0K742PKS";

const char *ssid = "Technomentis";
const char *pass = "usetmswifi";
const char *server = "api.thingspeak.com";

WiFiClient client;
void setup() {
  // put your setup code here, to run once:
Serial.begin(115200);
delay(10);
pinMode(A0, INPUT);

Serial.println("Connecting to");
Serial.println(ssid);
WiFi.begin(ssid,pass);

while (WiFi.status() != WL_CONNECTED){
  delay(500);
  Serial.println(".");
  
}
Serial.println("");
Serial.println("WiFi connected");
}

void loop() {
  // put your main code here, to run repeatedly:
int light=analogRead(A0);
Serial.println(client.connect(server,80));
if(client.connect(server,80)){
  String postStr = apiKey;
  postStr += "&field1=";
  postStr += String(light);

  postStr += "\r\n\r\n";

  client.println("POST /update HTTP/1.1\n");
  client.println("Host: api.thingspeak.com\n");
  client.println("Connection: close\n");
  client.println("X-THINGSPEAKAPIKEY: "+apiKey+"\n");
  client.println("Content-Type: application/x-www-form-urlencoded\n");
  client.println("Content-Length: ");
  client.println(postStr.length());
  client.println("\n\n");
  client.println(postStr);

  Serial.print("Light Instensity: ");
  Serial.print(light);

  Serial.println("%. Send To Thingspeak.");
}
client.stop();

Serial.println("Waiting....");

delay(16000);
}

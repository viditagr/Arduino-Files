#include<ESP8266WiFi.h>
const char* ssid = "Technomentis";
const char* password = "usetmswifi";
WiFiServer server(80);
void setup() {
  // put your setup code here, to run once:
Serial.begin(115200);
delay(10);
Serial.println("Connecting to....");
Serial.print(ssid);
WiFi.begin(ssid,password);
pinMode(A0, INPUT);
while(WiFi.status()!= WL_CONNECTED){
  delay(50);
  Serial.print(".");
  
}
Serial.println(".....Connecting to the");
server.begin();
Serial.println("Server started");
Serial.println("Use this URL to start");
Serial.print(WiFi.localIP());
Serial.print("/");
}

void loop() {
  // put your main code here, to run repeatedly:
float x;
WiFiClient client = server.available();
if(!client){
  return;
}
x = analogRead(A0);

Serial.println(x);
client.println("HTTP/1.1 200 OK");
client.println("Content-Type: text/html");
client.println("Refresh:1");
client.println("");
client.println("<!DOCTYPE HTML>");
client.println("<HTML>");
float y =(x/1024.0)*100;

client.println("<h1>");
client.println("LIGHT INTENSITY BY LDR");
client.println("<h1>");

client.print("<link rel=\"stylesheet\" href=\"https://www.w3schools.com/w3css/4/w3.css\">");
client.println("<body>");
client.println("<div class=\"w3-container\">");
client.println("<div class=\"w3-light-blue\">");
client.println("<div class=\"w3-container w3-green w3-center\" style=\"width:");

client.print(y);
client.print("%\">");
client.print(y);
client.print("%");
client.println("</div>");
client.println("</div><br>");
client.println("</body>");
client.println("</html>");

Serial.println(x);
delay(1);
}

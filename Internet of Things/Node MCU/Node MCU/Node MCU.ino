#include <ESP8266WiFi.h>
#include <Wire.h>
const char* ssid ="Technomentis";
const char* password= "usetmswifi";
WiFiServer server(80);
String web_response, readString1;
void setup() {
  // put your setup code here, to run once:
Serial.begin(115200);
delay(10);
pinMode(D0, OUTPUT);
Serial.println();
Serial.print ("Connecting to :");
Serial.println(ssid);
WiFi.begin(ssid, password);
while (WiFi.status() != WL_CONNECTED){
  delay(200);
  Serial.print(".");
}
Serial.println("");
Serial.println("WiFi connected");

server.begin();
Serial.println("Server started");

Serial.print("Use this URL to connect:");
Serial.print("https://");
Serial.print(WiFi.localIP());
Serial.println("/");

}
void loop() {
  // put your main code here, to run repeatedly:
WiFiClient client = server.available();
if(client){
  Serial.println("new client");

  boolean currentLineIsBlank = true;
  while (client.connected()) {
    if(client.available()){
      char c = client.read();
      web_response +=c;
      if(c == '\n' && currentLineIsBlank){
        host_server(client);
        Serial.println(web_response);
        if (web_response.indexOf("GET /?Bulb=ON")> -1){
        readString1="BulbON";
      }
      else if (web_response.indexOf("GET /?Bulb=OFF") > -1){
        readString1="BulbOFF";
      }
      web_response = "";
      break;
      
    }
    if(c=='\n'){
      currentLineIsBlank = true;
    }
    else if(c != '\r'){
      currentLineIsBlank = false;
    }
   }
  }
  delay(1);
  client.stop();
  Serial.println("client disconnected");
  
  
}
readData();
}
void host_server(WiFiClient client){
client.println("HTTP/1.1 200 OK");
client.println("Content-Type: text/html");
client.println("Connection: close");
client.println();
client.println("<!DOCTYPE HTML>");
client.println("<html>");
client.println("<head>");
client.println("<title>Explorato Smart Solutions</title>");
client.println("</head>");
client.println("<body>");
client.println("<br><h4>BULB</h4>");
client.println("<div><form>Bulb &nbsp<button name=\"Bulb\" value=\"ON\" type=\"submit\">ON</button>");
client.println("<button name=\"Bulb\" value=\"OFF\" type=\"submit\">OFF</button></form>");
client.print("</div></body>");
client.print("</html>");
}
void readData(){
  if(readString1.length()>0){
    Serial.println(readString1);
    if(readString1=="BulbON"){
      Serial.println("Bulb is ON NOW");
      digitalWrite(D0,HIGH);
    }
    else if (readString1=="BulbOFF"){
      Serial.println("Bulb is ON NOW");
      digitalWrite(D0,LOW);
    }
    readString1="";
    }
}







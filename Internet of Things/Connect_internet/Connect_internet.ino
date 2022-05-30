#include <ESP8266WiFi.h>

#include <SPI.h>
#include <MFRC522.h>
const int pinRST = D1;
const int pinSDA = D2;
String content = "";
int counter = -1;
MFRC522 mfrc522(pinSDA, pinRST);

const char* ssid = "Technomentis";
const char* password = "usetmswifi";
WiFiServer server(80);

String Tag_arrays[10];
void setup() {
  // put your setup code here, to run once:
Serial.begin(115200);  //Connect to Serial Monitor
delay(10);
SPI.begin();
mfrc522.PCD_Init();
Serial.println();  //Show WiFi ssid
Serial.print("Connecting to:  ");
Serial.println(ssid);

WiFi.begin(ssid, password);  //Connecting to WiFi

while (WiFi.status() != WL_CONNECTED) {   //Check for WiFi status
  delay(500);
  Serial.print(".");
}

Serial.println("");               //Confirm WiFi connection
Serial.print("WiFi connected");
Serial.println();

server.begin();                   //Begin server connection

Serial.println("Server started"); 
Serial.println(WiFi.localIP());     //Print IP Address

}

void loop() {
  // put your main code here, to run repeatedly:
WiFiClient client = server.available();

if(!client) {
  return;
}
while (client.connected()){
  if (client.available()){
  if (mfrc522.PICC_IsNewCardPresent()) {
    content = "";
    if(mfrc522.PICC_ReadCardSerial()) {
      Serial.print("RFID TAG ID:");
      for (byte i = 0; i < mfrc522.uid.size; ++i) {
        content.concat(String(mfrc522.uid.uidByte[i], HEX));
        //content.concat(String(byte[i] < 0x10 ? "0" : " "));
      }
      counter += 1;
    }
  }
      
Serial.println(content);
counter % 
client.println("HTTP/1.1 200 OK");
client.println("Content-Type: text/html");
client.println("<!DOCTYPE HTML>");
client.println("");
client.println("<html>");
client.println("<title>TAG IDS</title>");
client.println("<body>");
client.println("<meta http-equiv=\"refresh\" content=\"1\">");
client.println(content);
client.println("</body>");
client.println("</html>");
delay(1);
  client.stop();
  }
  
}
Serial.println("Client Disconnected");
}

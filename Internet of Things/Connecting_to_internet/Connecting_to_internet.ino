#include <SPI.h>
#include <MFRC522.h>
#define SDA D2
#define RST D1
#include <ESP8266WiFi.h>

const char* ssid = "Technomentis";
const char* pass = "usetmswifi";
String web_response, string1;
WiFiServer server(80);
String content = "";

MFRC522 mfrc522(D2, D1);

void setup() {
  // put your setup code here, to run once:
SPI.begin();
mfrc522.PCD_Init();
Serial.begin(9600);
delay(10);
Serial.println("");
Serial.print("connecting to ");
Serial.print("ssid");

WiFi.begin(ssid, pass);
while (WiFi.status() != WL_CONNECTED){
  delay(200);
  Serial.print(".");
}
Serial.print("");
Serial.println("WiFi Connecetd");

server.begin();
Serial.println("Server Started");
Serial.println("use this IP address to connect");
Serial.print("http://");
Serial.print(WiFi.localIP());
Serial.println("/");
}


void loop() {
  // put your main code here, to run repeatedly:

if (mfrc522.PICC_IsNewCardPresent()){
  //Serial.print("tag present");
  if(mfrc522.PICC_ReadCardSerial()){
    Serial.print("TAG UID:");
    for(byte i = 0;i < mfrc522.uid.size;i++){
      Serial.print(mfrc522.uid.uidByte[i]< 0*10 ? "0":"");
      Serial.print(mfrc522.uid.uidByte[i], HEX);
      content.concat(String(mfrc522.uid.uidByte[i]< 0*10 ? "0":""));
      content.concat(String(mfrc522.uid.uidByte[i], HEX));
}
Serial.println();
Serial.println(content);
Serial.println();
mfrc522.PICC_HaltA();
}
}

WiFiClient RFID = server.available();

if (RFID) {                             // If a new client connects,
    Serial.println("New Client.");          // print a message out in the serial port
    String currentLine = "";                // make a String to hold incoming data from the client
    while (RFID.connected()){              // loop while the client's connected
      if (RFID.available()) {             // if there's bytes to read from the client,
        char c = RFID.read();             // read a byte, then
        Serial.write(c);                    // print it out the serial monitor
        String header;
        header += c;
        if (c == '\n') {                    // if the byte is a newline character
          // if the current line is blank, you got two newline characters in a row.
          // that's the end of the client HTTP request, so send a response:
          if (currentLine.length() == 0) {
          
            RFID.println("HTTP/1.1 200 OK");
            RFID.println("Content-type:text/html");
            RFID.println("Connection: close");
            RFID.println("");
            RFID.println("<html>");
            RFID.println("<head>");
            RFID.println("<title> tag ids </title>");
            RFID.println("</head><body>");
            RFID.println(content);
            RFID.println("</body>");
            RFID.println("</html>");
RFID.stop();            
}
}
}
  
}

}
}
/*void host_server(WiFiClient RFID){
RFID.println("HTTP/1.1 200 OK");
RFID.println("Content-Type:text/html");
RFID.println("");
RFID.println("<html>");
RFID.println("<head>");
RFID.println("<title> tag ids </title>");
RFID.println("</head><body>");
RFID.println("Hello World");
RFID.println("</body>");
RFID.println("</html>");



}*/

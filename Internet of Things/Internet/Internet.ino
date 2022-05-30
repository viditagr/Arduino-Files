#include <ESP8266WiFi.h>
#include <time.h>
#include <SPI.h>
#include <MFRC522.h>
#define SDA D2
#define RST D1
String Old_ID = "";
MFRC522 mfrc522(D2, D1);

int j;
int counter = -1;

String Tag_array[10];
//String Time_array[10];

int count_numbers;

int ledPin = D0;

int timezone = 7 * 3600;
int dst = 0;


String content = "";

const char* ssid = "Technomentis";
const char* pass = "usetmswifi";
String web_response, string1;
WiFiServer server(80);


void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin,OUTPUT);

  digitalWrite(ledPin,LOW);
  
Serial.begin(9600);
delay(10);
Serial.println("");
Serial.print("connecting to ");
Serial.print("ssid");

SPI.begin();
mfrc522.PCD_Init();
Serial.println("RFID reading UID");

WiFi.begin(ssid, pass);
while (WiFi.status() != WL_CONNECTED){
  delay(200);
  Serial.print(".");
}
digitalWrite( ledPin , HIGH);


Serial.print("");
Serial.println("WiFi Connected");

server.begin();
Serial.println("Server Started");
Serial.println("use this IP address to connect");
Serial.print("http://");
Serial.print(WiFi.localIP());
Serial.println("/");

configTime(timezone, dst, "pool.ntp.org","time.nist.gov");


  while(!time(nullptr)){

     Serial.print("*");

     delay(100);

  }
  

}


void loop() {
  // put your main code here, to run repeatedly:

time_t now = time(nullptr);

  struct tm* p_tm = localtime(&now);

WiFiClient RFID = server.available();

if (RFID) {                             // If a new client connects,
    Serial.println("New Client.");          // print a message out in the serial port
    String currentLine = "";                // make a String to hold incoming data from the client
    while (RFID.connected()){              // loop while the client's connected
      if (RFID.available()) {             // if there's bytes to read from the client
        char c = RFID.read();             // read a byte, then
        Serial.print(c);                    // print it out the serial monitor
        String header;
        header += c;
        if (c == '\n') {
          if (mfrc522.PICC_IsNewCardPresent()){
  if(mfrc522.PICC_ReadCardSerial()){
    //Serial.print("TAG UID:");
    content = "";
    for(byte i = 0;i < mfrc522.uid.size;i++){
      //Serial.print(mfrc522.uid.uidByte[i]< 0*10 ? "0":"");
      //Serial.print(mfrc522.uid.uidByte[i], HEX);
      content.concat(String(mfrc522.uid.uidByte[i]< 0*10 ? "0":""));
      content.concat(String(mfrc522.uid.uidByte[i], HEX));
      
}
}
          }

counter += 1;
int y = counter % 10;
Tag_array[y] = content;
            /*for(j = 0; j < 11; j++){
            Tag_array[j] = content;
             Time_array[j] = p_tm->tm_mday + "/" + p_tm->tm_mon + 1 + "/" + p_tm->tm_year + 1900 + " " + p_tm->tm_hour - 1 + ":" + p_tm->tm_min - 30;
int day = p_tm->tm_mday;
int month = p_tm->tm_mon + 1;
int year = p_tm->tm_year + 1900;
int hour = p_tm->tm_hour - 1;
int minute = p_tm->tm_min - 30;
          }
          if (counter == 11){
          j = 0;
          }
          if(j = 0){
            for(j = 0; j < 11; j++){
            Tag_array[j] = content;
           // Time_array[j] = p_tm->tm_mday + "/" + p_tm->tm_mon + 1 + "/" + p_tm->tm_year + 1900 + " " + p_tm->tm_hour - 1 + ":" + p_tm->tm_min - 30;
          }
         }*/
          
            // if the byte is a newline character
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
            RFID.println("<meta http-equiv=\"refresh\" content=\"1\" >");
            if(content != Old_ID){
              /*int y = counter % 10;
              //Tag_array[y] = content;
              //for(j = 0; j < 11; j++){*/
              RFID.println(content);
              RFID.print(p_tm->tm_mday);
              RFID.print("/");
              RFID.print(p_tm->tm_mon + 1);
              RFID.print("/");
              RFID.print(p_tm->tm_year + 1900);
              RFID.print(" ");
              RFID.print(p_tm->tm_hour);
              RFID.print(":");
              RFID.print(p_tm->tm_min);
            
            }
            RFID.print("<form>exit<button name=\"exit\" value=\"ON\" type=\"submit\"ON</button></form>")
            //RFID.println("Hello World");
            RFID.println("</body>");
            RFID.println("</html>");
            if (web_response.indexOf("GET /?exit=ON") > -1) {
                  for (int j = 0; j < 10; j++){
                     RFID.println(Tag_array[j]);
      } 
          }
            content = Old_ID;
            
            
            RFID.stop();
            Serial.println("Connection closed");
}
}


}
}
}
}

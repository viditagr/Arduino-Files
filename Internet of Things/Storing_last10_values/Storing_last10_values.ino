#include <SPI.h>
#include <MFRC522.h>
#define SDA D2
#define RST D1
MFRC522 mfrc522(D2, D1);
String content;
int counter = -1;

#include <ESP8266WiFi.h>

#include <time.h>

float timezone = 7 * 3600;
int dst = 0;

const char* ssid = "Technomentis";

const char* password = "usetmswifi";


String Tag_array[10];
String Tag_times[10];
void setup() {
  // put your setup code here, to run once:

  
Serial.begin(9600);

Serial.println();

  Serial.print("Wifi connecting to ");

  Serial.println( ssid );



  WiFi.begin(ssid,password);



  Serial.println();

  

  Serial.print("Connecting");



  while( WiFi.status() != WL_CONNECTED ){

      delay(10);

      Serial.print(".");        

  }

Serial.print("NodeMCU IP Address : ");

  Serial.println(WiFi.localIP() );



  configTime(timezone, dst, "pool.ntp.org","time.nist.gov");

  Serial.println("\nWaiting for Internet time");



  while(!time(nullptr)){

     Serial.print("*");

     delay(100);

  }

  Serial.println("\nTime response....OK");   

}

SPI.begin();
mfrc522.PCD_Init();
Serial.println("RFID reading UID");
}
char rx_byte = 0;
void loop() {
  time_t now = time(nullptr);

  struct tm* p_tm = localtime(&now);
long day = p_tm->tm_mday * 10000000000;
long month = p_tm->tm_mon + 1 * 100000000;
int year = p_tm->tm_year + 1900 * 10000;
int hour = p_tm->tm_hour * 100;
int minute = p_tm->tm_min;
long final_time = day + month + year + minute + hour;
if (mfrc522.PICC_IsNewCardPresent()){
  //Serial.print("tag present");
  if(mfrc522.PICC_ReadCardSerial()){
    Serial.print("TAG UID:");
    content = "";
    for(byte i = 0;i < mfrc522.uid.size;i++){
      //Serial.print(mfrc522.uid.uidByte[i]< 0*10 ? "0":"");
      //Serial.print(mfrc522.uid.uidByte[i], HEX);
      content.concat(String(mfrc522.uid.uidByte[i]< 0*10 ? "0":""));
      content.concat(String(mfrc522.uid.uidByte[i], HEX));
    }
      counter += 1;
int y = counter % 10;
Tag_array[y] = content;
Tag_times[y] = final_time;
Serial.println(Tag_array[y]);
Serial.print(Tag_times[y]);
mfrc522.PICC_HaltA();
}
}
if (Serial.available() > 0) {    // is a character available?
    rx_byte = Serial.read();       // get the character
    // check if a number was received
    if ((rx_byte >= '0') && (rx_byte <= '9')) {
      Serial.print("Number received: ");
      for (int j = 0; j < 10; j++){
        Serial.println(Tag_array[j]);
        Serial.print(Tag_times[j]);
      }      
}
    }
    }

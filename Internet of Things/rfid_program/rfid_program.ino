#include <SPI.h>
#include <MFRC522.h>
const int pinRST = D1;
const int pinSDA = D2;
String content = "";
MFRC522 mfrc522(pinSDA, pinRST);
void setup() {
  SPI.begin();
  mfrc522.PCD_Init();
  Serial.begin(9600);
}
void loop() {
  if (mfrc522.PICC_IsNewCardPresent()) {
    content = "";
    if(mfrc522.PICC_ReadCardSerial()) {
      Serial.print("RFID TAG ID:");
      for (byte i = 0; i < mfrc522.uid.size; ++i) {
        content.concat(String(mfrc522.uid.uidByte[i], HEX));
        //content.concat(String(byte[i] < 0x10 ? "0" : " "));
      }
      Serial.println(content);
      Serial.println();
    }
  }
}

#include <SPI.h>
#include <MFRC522.h>
#define SDA D2
#define RST D1
MFRC522 mfrc522(D2, D1);
String content;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
SPI.begin();
mfrc522.PCD_Init();
Serial.println("RFID reading UID");
}

void loop() {
  // put your main code here, to run repeatedly:
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

mfrc522.PICC_HaltA();
}
}

Serial.println(content);
}

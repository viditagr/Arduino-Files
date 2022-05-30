#include <ESP8266WiFi.h>

#include <time.h>



const char* ssid = "Technomentis";

const char* password = "usetmswifi";



int ledPin = D0;



float timezone = 7 * 3600;
int dst = 0;



void setup() {

  

  pinMode(ledPin,OUTPUT);

  digitalWrite(ledPin,LOW);



  Serial.begin(115200);

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



  digitalWrite( ledPin , HIGH);

  Serial.println();



  Serial.println("Wifi Connected Success!");

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



void loop() {

  

  time_t now = time(nullptr);

  struct tm* p_tm = localtime(&now);

  Serial.print(p_tm->tm_mday);

  Serial.print("/");

  Serial.print(p_tm->tm_mon + 1);

  Serial.print("/");

  Serial.print(p_tm->tm_year + 1900);

  

  Serial.print(" ");

  

  Serial.print(p_tm->tm_hour);

  Serial.print(":");

  Serial.println(p_tm->tm_min);

  //Serial.print(":");

  //Serial.println(p_tm->tm_sec);

  

  delay(60000);



}

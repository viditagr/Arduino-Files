#include<ESP8266WiFi.h>

int state1=0;
int y=0;
String web_response, readString1;
const char* ssid = "Technomentis";
const char* password = "usetmswifi";
WiFiServer server(80);

IPAddress ip(192,168,1,53);
IPAddress subnet(255,255,255,0);
IPAddress gateway(192,168,1,1);
void setup() {
  // put your setup code here, to run once:
pinMode(D0,INPUT);
pinMode(D1,OUTPUT);
Serial.begin(115200);

WiFi.config(ip,gateway,subnet);
Serial.print("Connecting to:");
Serial.println(ssid);
WiFi.begin(ssid , password);
while(WiFi.status()!=WL_CONNECTED){
  delay(200);
  Serial.println(".");
}
Serial.println(".");
Serial.println("WiFi Connected");
server.begin();
Serial.print("Use this URL to connect:");
Serial.print("http://");
Serial.print(WiFi.localIP());
Serial.println("/");
}

void loop() {
  // put your main code here, to run repeatedly:
int x=digitalRead(D0);
if(x==1 && y==0){
  y=1;
changestate();
}
 else if(x==0){
  y=0;
}
WiFiClient client = server.available();

if(client){
  Serial.println("New client");
  boolean currentLineIsBlank = true;
  while(client.connected()){
    if(client.available()){
      char c = client.read();
      web_response+=c;

      if(c=='\n' && currentLineIsBlank){
        host_server(client);
        Serial.println(web_response);
        if(web_response.indexOf("GET /?Socket1=ON")>-1){
          readString1="Socket1ON";
        }
        else if(web_response.indexOf("GET /?Socket1=OFF")>-1){
        readString1="Socket1OFF";
        }
        web_response = "";
        break;
      }
      if(c == '\n'){
        currentLineIsBlank=true;
      }
      else if(c!='\r'){
        currentLineIsBlank=false;
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
client.println("Content-Type:text/html");
client.println("Connection: close");
client.println();
client.println("<!DOCTYPE HTML>");
client.println("<html>");
client.println("<head>");
client.println("<title>Explorato Smart Solutions</title>");
client.println("</head>");
client.println("<body>");
client.println("</h3><br><h4>SOCKETS</h4>");
client.println("<div><form>Socket1 &nbsp<button name = \"Socket1\" value=\"ON\" type=\"submit\">ON</button>");
client.println("<button name = \"Socket1\" value=\"OFF\" type=\"submit\">OFF</button></form>");
client.println("</div>");
client.println("</body>");
client.println("</html>");
}
void readData(){
  if(readString1.length()>0){
    Serial.println(readString1);
    if(readString1=="Socket1ON"){
      digitalWrite(D1,HIGH);
      state1=1;
      Serial.println("I am On");
    }
    else if(readString1=="Socket1OFF"){
      digitalWrite(D1,LOW);
      state1=0;
       Serial.println("I am OFF");
    }
  }
readString1="";
}
void changestate(){
  if(state1==1){
    digitalWrite(D1,LOW);
    state1=0;
  }
  else if(state1==0){
    digitalWrite(D1,HIGH);
    state1=1;
  }
}


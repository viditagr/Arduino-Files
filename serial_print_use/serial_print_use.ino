int x;
int y;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}


void loop() {

  // put your main code here, to run repeatedly:
for(x=1;x<101;x++){
int y=17*x;
Serial.print("17*");
Serial.print(x);
Serial.print("=");
Serial.println(y);
delay(20);
}}

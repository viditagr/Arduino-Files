unsigned long y;
unsigned long x=2;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
 

}

void loop() {
  // put your main code here, to run repeatedly:
for (int z=1;z<32;z++){
  y=x;
x=2*y;
Serial.println(y);
delay(1000);
}
  

}

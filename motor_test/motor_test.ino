int x;
void setup() {
  // put your setup code here, to run once:
pinMode(9,OUTPUT);
pinMode(10,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
for(x=0; x<256 ;x++){
analogWrite(9,x);
analogWrite(10,255-x);
delay(100);
}
for(x=0; x<256 ;x++){
analogWrite(10,x);
analogWrite(9,255-x);
delay(100);
}


}

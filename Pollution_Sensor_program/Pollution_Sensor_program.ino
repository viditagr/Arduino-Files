void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(A1,INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
int x=analogRead(A1);
Serial.println(x);
delay(1000);
}

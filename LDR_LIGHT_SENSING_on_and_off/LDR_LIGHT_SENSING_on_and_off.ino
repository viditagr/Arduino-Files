void setup() {
  // put your setup code here, to run once:
pinMode(A0,INPUT);
pinMode(9,OUTPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
int x = analogRead(A0);
if (x>700)
{
digitalWrite(9,HIGH);
}
else if (x<700)
{
digitalWrite(9,LOW);
}
}

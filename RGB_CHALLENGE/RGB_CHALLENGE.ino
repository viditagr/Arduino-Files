void setup() {
  // put your setup code here, to run once:
pinMode(A0,INPUT);
pinMode(9,OUTPUT);   //green
pinMode(10,OUTPUT);   //blue
pinMode(11,OUTPUT);   //red
Serial.begin(9600);
}

void loop() {
int x=analogRead(A0);
  // put your main code here, to run repeatedly:
  Serial.println(x);
if (x>500){
  digitalWrite(11,HIGH);
  delay(60);
  digitalWrite(11,LOW);
  digitalWrite(10,HIGH);
  delay(60);
  digitalWrite(10,LOW);
  digitalWrite(9,LOW);}
if (x<500){
digitalWrite(9,HIGH);
  delay(60);
  digitalWrite(9,LOW);
  digitalWrite(10,HIGH);
  delay(60);
  digitalWrite(10,LOW);
  digitalWrite(11,LOW);

}

}

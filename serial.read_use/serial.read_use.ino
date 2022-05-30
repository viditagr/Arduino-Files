char y;
String z="";
void setup() {
  // put your setup code here, to run once:
pinMode(9,OUTPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
while(Serial.available())
{
y = Serial.read();
z=z+y;
delay(3);
}
Serial.println(z);
if(z.length()>0)
{
if(z=="yes"){
digitalWrite(9,HIGH);
}
else if(z=="no"){
digitalWrite(9,LOW);
}
z="";
}
}


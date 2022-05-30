int y=0;
int z=0;
int x;
void setup() {
  // put your setup code here, to run once:
pinMode(A0,INPUT);
pinMode(9,OUTPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
x=analogRead(A0);
Serial.println(x);
if (x>500){
y+1=z;
z=y;}
if (z<6){
digitalWrite(9,HIGH);
delay(10000);


}
}



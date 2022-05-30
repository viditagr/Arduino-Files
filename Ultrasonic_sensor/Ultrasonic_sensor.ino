int D2;
int help;
int distance;
int duration;
void setup() {
  // put your setup code here, to run once:
pinMode(10,OUTPUT);
pinMode(11,INPUT);
Serial.begin(9600);


}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(10,LOW);
delayMicroseconds(2);
digitalWrite(10,HIGH);
delayMicroseconds(10);
duration=pulseIn(11,HIGH);
distance=duration/58.8;
delay(200);
D2=duration/58.8;
duration=help/2;
int what=(distance*(1000000*2))/help;
if(distance>=150){
  Serial.println("--");
}
delay(50);
Serial.println(what);
delay(100);
}

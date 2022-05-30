int x=5000;
int y;
void setup() {
  // put your setup code here, to run once:
pinMode(9,INPUT);
Serial.begin(9600);
}


void loop() {
int x=digitalRead(9);
  // put your main code here, to run repeatedly:
if (x==HIGH){
Serial.println("Obstacle on");
y+
}
}

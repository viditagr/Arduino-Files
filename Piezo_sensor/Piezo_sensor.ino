int x=analogRead(A0);
int y
void setup() {
  // put your setup code here, to run once:
pinMode(A0,INPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  x=analogRead(A0);
Serial.println(x);
if x>900;
y=y+1;
}

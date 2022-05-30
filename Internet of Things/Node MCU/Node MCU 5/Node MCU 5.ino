int counter=0;
int y=0;


void setup() {
  // put your setup code here, to run once:
pinMode(D0,INPUT);
pinMode(D1,OUTPUT);
Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
int x=digitalRead(D0);
if(x==1 && y==0){
  y=1;
  counter=counter+1;
}
if(x==0){
  y=0;
}
if(counter % 2 ==0)
{
  digitalWrite(D1,LOW);
}
else if(counter % 2 !=0)
{
  digitalWrite(D1,HIGH);
}

}

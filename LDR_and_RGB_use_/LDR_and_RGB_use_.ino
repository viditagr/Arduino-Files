


void setup() {
  // put your setup code here, to run once:
pinMode(A0, INPUT);
pinMode(9, OUTPUT);        //green
pinMode(10, OUTPUT);      //blue
pinMode(11,OUTPUT);      //red
Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
int x=analogRead(A0);
if (x>800){
digitalWrite(11,HIGH);
digitalWrite(10,LOW);
digitalWrite(9,LOW);
}
if (x<=800 && x>=300){
digitalWrite(9,HIGH);
digitalWrite(10,LOW);
digitalWrite(11,LOW);
}
if (x<300){
digitalWrite(10,HIGH);
digitalWrite(9,LOW);
digitalWrite(11,LOW);
}
Serial.println(x);


}




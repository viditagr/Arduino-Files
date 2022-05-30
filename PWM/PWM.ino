int x;
void setup(){ 
  // put your setup code here, to run once:
pinMode(9,OUTPUT);

}

void loop() 

 { // put your main code here, to run repeatedly:
for(x=0;x<256;x++){
analogWrite(9,x);
delay(100);
}
for(x=256;x>-1;x--){
analogWrite(9,x);
delay(100);
}}

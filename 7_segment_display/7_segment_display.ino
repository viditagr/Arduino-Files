int z;
int y;
int v=0;
void setup() {
  // put your setup code here, to run once:
  pinMode(9,OUTPUT); //E
  pinMode(10,OUTPUT);//D
  pinMode(11,OUTPUT);//C
  pinMode(12,OUTPUT);//DP
  pinMode(13,OUTPUT);//B
  pinMode(8,OUTPUT); //F
  pinMode(6,OUTPUT); //A
  pinMode(7,OUTPUT); //G
  pinMode(5,INPUT);  
  Serial.begin(9600);
} 

void loop() {
  // put your main code here, to run repeatedly:
 delay(100);
 y=digitalRead(5);
  Serial.println(y);
if (y==1){
v=v+1;
segment(v);
delay(100);
}
segment(v);
delay(500);
if(v==9){
v=0;
}
}
void segment(int x)
{
  int a=6;
  int b=13;
  int c=11;
  int d=10;
  int e=9;
  int f=8;
  int g=7;
switch(x){
  case 0:
digitalWrite(a,1);
digitalWrite(b,1);
digitalWrite(c,1);
digitalWrite(d,1);
digitalWrite(e,1);
digitalWrite(f,1);
digitalWrite(g,0);
break;
  case 1:
  digitalWrite(a,0);
  digitalWrite(b,1);
  digitalWrite(c,1);
  digitalWrite(d,0);
  digitalWrite(e,0);
  digitalWrite(f,0);
  digitalWrite(g,0);
  break;
  case 2:
  digitalWrite(a,1);
  digitalWrite(b,1);
  digitalWrite(c,0);
  digitalWrite(d,1);
  digitalWrite(e,1);
  digitalWrite(f,0);
  digitalWrite(g,1);
  break;
  case 3:
  digitalWrite(a,1);
  digitalWrite(b,1);
  digitalWrite(c,1);
  digitalWrite(d,1);
  digitalWrite(e,0);
  digitalWrite(f,0);
  digitalWrite(g,1);
  break;
  case 4:
  digitalWrite(a,0);
  digitalWrite(b,1);
  digitalWrite(c,1);
  digitalWrite(d,0);
  digitalWrite(e,0);
  digitalWrite(f,1);
  digitalWrite(g,1);
  break;
  case 5:
  digitalWrite(a,1);
  digitalWrite(b,0);
  digitalWrite(c,1);
  digitalWrite(d,1);
  digitalWrite(e,0);
  digitalWrite(f,1);
  digitalWrite(g,1);
  break;
  case 6:
  digitalWrite(a,1);
  digitalWrite(b,0);
  digitalWrite(c,1);
  digitalWrite(d,1);
  digitalWrite(e,1);
  digitalWrite(f,1);
  digitalWrite(g,1);
  break;
  case 7:
  digitalWrite(a,1);
  digitalWrite(b,1);
  digitalWrite(c,1);
  digitalWrite(d,0);
  digitalWrite(e,0);
  digitalWrite(f,0);
  digitalWrite(g,0);
  break;
  case 8:
  digitalWrite(a,1);
  digitalWrite(b,1);
  digitalWrite(c,1);
  digitalWrite(d,1);
  digitalWrite(e,1);
  digitalWrite(f,1);
  digitalWrite(g,1);
  break;
  case 9:
  digitalWrite(a,1);
  digitalWrite(b,1);
  digitalWrite(c,1);
  digitalWrite(d,1);
  digitalWrite(e,0);
  digitalWrite(f,1);
  digitalWrite(g,1);
  break;
}
}


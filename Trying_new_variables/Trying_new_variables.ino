
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
String one="I love to sleep for 200000 minutes";
int a=one.indexOf("for");
int b=one.indexOf("minutes");
String two=one.substring(a+4,b-1);
Serial.println(two);





}

#include<LiquidCrystal.h>
const int rs=7, en=6, d4=5, d5=4, d6=3, d7=2;
LiquidCrystal lcd(rs,en,d4,d5,d6,d7);
void setup() {
  // put your setup code here, to run once:
 lcd.begin(16,2);

}

void loop() {
  // put your main code here, to run repeatedly:

lcd.display();
delay(500);


lcd.setCursor(0,0);
lcd.print("Vidit");
  
lcd.setCursor(0,1);
lcd.print("Rohan");


lcd.noDisplay();
delay(500);

lcd.display();
delay(500);
lcd.setCursor(0,0);
lcd.print("");
  
lcd.setCursor(0,1);
lcd.print("");
lcd.display();
delay(500);
lcd.clear();

lcd.display();
delay(500);


lcd.setCursor(0,0);
lcd.print("Sayak");

lcd.setCursor(0,1);
lcd.print("Yash");

lcd.display();
delay(500);
lcd.setCursor(0,0);
lcd.print("");
  


}

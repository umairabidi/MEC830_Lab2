#include <LiquidCrystal.h>
const int rs = A0, en = A1, d4 = A2, d5 = A3, d6 = A4, d7 = A5;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
	lcd.begin(16,2);
	lcd.print("Hello World!");
}

void loop() {
	lcd.setCursor(0,1);
	lcd.print("Bottom Text");
}

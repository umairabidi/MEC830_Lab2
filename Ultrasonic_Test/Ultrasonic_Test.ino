#include <LiquidCrystal.h>

const int RS = A0, enable = A1, d4 = A2, d5 = A3, d6 = A4, d7 = A5;
LiquidCrystal lcd(RS, enable, d4, d5, d6, d7);

// Ultrasonic Sensor
const int ECHO = 5;		// Green Wire
const int TRIG = 6;		// Yellow Wire

// Function Prototypes
void trigger();

void setup() {
	pinMode(ECHO, INPUT);
	pinMode(TRIG, OUTPUT);
	lcd.begin(16,2);
	lcd.print("Hello World!");
	digitalWrite(TRIG, LOW);
	Serial.begin(9600);
}

void loop() {
	double distance;
	
	trigger();	// Send a 10 uS pulse
	distance = pulseIn(ECHO, HIGH, 25000)/58.0;		// Convert ECHO pulse width to distance in cm
	
	// Print to the LCD
	char lcd_buffer[16] = {0};
	dtostrf(distance, 4, 2, lcd_buffer);
	sprintf(lcd_buffer, "%s cm  ", lcd_buffer);
	lcd.setCursor(0,1);
	lcd.print(lcd_buffer);
	
	// Avoid spamming
	_delay_ms(200);
}

void trigger(){
	digitalWrite(TRIG, HIGH);
	_delay_us(10);
	digitalWrite(TRIG, LOW);
}

const int tiltSwitch = 12;
const int redLED = 3;

void setup() {
	pinMode(tiltSwitch, INPUT);
	pinMode(redLED, OUTPUT);
	digitalWrite(tiltSwitch, HIGH);	// Internal pull-up
}

void loop() {
	digitalWrite(redLED, digitalRead(tiltSwitch));
}
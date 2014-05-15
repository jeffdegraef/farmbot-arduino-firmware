// Do not remove the include below
#include "farmbot_arduino_controller.h"
#include "pins.h"

static char commandEndChar = 0x0A;
static GCodeProcessor* gCodeProcessor = new GCodeProcessor();

//The setup function is called once at startup of the sketch
void setup() {
	Serial.begin(115200);
	pinMode(X_STEP_PIN, OUTPUT);
	pinMode(X_DIR_PIN, OUTPUT);
	pinMode(X_ENABLE_PIN, OUTPUT);
	pinMode(X_MIN_PIN, OUTPUT);
	pinMode(X_MAX_PIN, OUTPUT);
}

// The loop function is called in an endless loop
void loop() {
	if (Serial.available()) {
		String commandString = Serial.readStringUntil(commandEndChar);
		if (commandString && commandString.length() > 0) {
			Command* command = new Command(commandString);
			command->print();

			gCodeProcessor->execute(command);
		}
	}
	delay(100);
}

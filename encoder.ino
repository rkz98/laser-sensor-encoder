#define COMPLETE_ROTATION 10

uint rotationStep = 0;
uint completeRotations = 0;

const uint pinButton = 12;
const uint pinLaserSensor = 8;

void setup() {
	Serial.begin(9600);
	pinMode(pinButton, INPUT);
	pinMode(pinLaserSensor, INPUT);
}

void checkIfCompleteRotation() {
	if (rotationStep == COMPLETE_ROTATION) {
		completeRotations += 1;
	}
}

void startRunning() {
	uint lastLaserSensorState = 0;
	uint laserSensorState = digitalRead(pinLaserSensor);

	if (laserSensorState == LOW) {
		if (laserSensorState == HIGH) {
			rotationStep += 1;
			lastLaserSensorState = LOW;
			checkIfCompleteRotation();
		}
	} else if (laserSensorState == LOW) {
		rotationStep += 1;
		lastLaserSensorState = HIGH;
		checkIfCompleteRotation();
	}
}

void stopRunning() {
	rotationStep = 0;
	completeRotations = 0;
}

void loop() {
	uint buttonState = digitalRead(pinButton);

	Serial.println(completeRotations);

	if (buttonState == HIGH) {
		startRunning();
	} else {
		stopRunning();
	}
}
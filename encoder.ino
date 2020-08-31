#define COMPLETE_ROTATION 10

unsigned int rotationStep = 0;
unsigned int completeRotations = 0;
unsigned int lastLaserSensorState = 0;

const unsigned int pinLaserSensor = 8;

void setup()
{
	Serial.begin(9600);
	pinMode(pinLaserSensor, INPUT);
}

void checkIfCompleteRotation()
{
	if (rotationStep == COMPLETE_ROTATION)
	{
		rotationStep = 0;
		completeRotations += 1;
	}
}

void startRunning()
{
	unsigned int lastLaserSensorState = 0;
	unsigned int laserSensorState = digitalRead(pinLaserSensor);

	if (laserSensorState == LOW)
	{
		if (laserSensorState == HIGH)
		{
			rotationStep += 1;
			lastLaserSensorState = LOW;
			checkIfCompleteRotation();
		}
	}
	else if (lastLaserSensorState == LOW)
	{
		rotationStep += 1;
		lastLaserSensorState = HIGH;
		checkIfCompleteRotation();
	}
}

void loop()
{
	Serial.println(completeRotations);
	startRunning();
	Serial.println(completeRotations);
}
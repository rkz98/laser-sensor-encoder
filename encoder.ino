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
	unsigned int laserSensorState = digitalRead(pinLaserSensor);

	//Serial.println(laserSensorState);
	Serial.println(lastLaserSensorState);
	// Serial.println(rotationStep);

	if (laserSensorState == LOW)
	{
		if (laserSensorState == HIGH)
		{
			Serial.println("Aqui 1");
			rotationStep += 1;
			lastLaserSensorState = 0;
			checkIfCompleteRotation();
		}
	}
	else if (lastLaserSensorState == 0)
	{
		Serial.println("Aqui 2");
		rotationStep += 1;
		lastLaserSensorState = 1;
		checkIfCompleteRotation();
	}
}

void loop()
{
	startRunning();
	// Serial.println(completeRotations);
}
/*
Lisul Elvitigala
Coding and Web Design Officer Application
4/5-4/16
*/

#include <Adafruit_MotorShield.h>

// Create the motor shield object with the default I2C address
Adafruit_MotorShield AFMS = Adafruit_MotorShield();

// Connect a stepper motor with 200 steps per revolution (1.8 degree)
// to motor port #1 (M1 and M2)
Adafruit_StepperMotor *myMotor = AFMS.getStepper(48, 1);
Adafruit_StepperMotor *myMotor = AFMS.getStepper(48, 2);
const int limitSwitchPin = 2;
const int greenPin = 10;
const int redPin = 9;
int bluePin = A1;

int numberCollector;
byte serialNumber;
const int opticCount = 4;
const int parameterCount = 3;
const int parameterSize = 2;

int drinkMatrix[opticCount][parameterCount] = {};

int prevButtonState = 0;
int currentButtonState = 0;

bool contactSwitchFound = false;
bool drinkRequested = false;

void setup()
{
    Serial.begin(9600); 
    while (!Serial)
        ;
    Serial.println("Stepper test!");

    if (!AFMS.begin())
    { 
        Serial.println("Could not find Motor Shield. Check wiring.");
        while (1)
            ;
    }
    Serial.println("Motor Shield found.");

    myMotor->setSpeed(10); 
}

void loop()
{
}
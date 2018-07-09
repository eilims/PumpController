//
// Created by db217620 on 6/17/2018.
//

#include "Pump.h"

Pump::Pump(uint8_t enablePin, uint8_t topControlPin, uint8_t bottomControlPin) {
    this->enablePin = enablePin;
    this->topControlPin = topControlPin;
    this->bottomControlPin = bottomControlPin;
    pinMode(this->topControlPin, OUTPUT);
    pinMode(this->bottomControlPin, OUTPUT);
}

Pump::~Pump() {

}

void Pump::runPump(int timeInMilliSeconds, uint8_t waterStrength, uint8_t fluctuationAmount, uint8_t waterStrengthLowerLimit, int intervalTime) {
    //First three variables are used to control the water pressure out of the pump
	this->timer = millis();
    uint32_t lastReading = this->timer;
    uint8_t currentWaterStrength = waterStrengthLowerLimit;
	bool isIncreasing = true;
		
    //timer is started until the requested watering time is reached
    //TODO add lower limit to watering time. IE no watering for 10 seconds watering minimum
    // TODO add on a second or two for water movement through pipe
    

    //Apply voltage to H-bridge so the enable pin can pulse the motor with voltage
    digitalWrite(this->topControlPin, HIGH);
	digitalWrite(this->bottomControlPin, LOW);

    //Check if watering time has been met
    while ((millis() - this->timer) < timeInMilliSeconds) {

        //Check if we need to change the water strength according to the fluctuation amount
        if ((millis() - lastReading) > intervalTime) {
            //Increase by fluctuation amount when increasing
            if (isIncreasing) {
                currentWaterStrength += fluctuationAmount;
            } else {
                currentWaterStrength -= fluctuationAmount;
            }

            //Switch directions once in a while
            if(currentWaterStrength > waterStrength || currentWaterStrength <= waterStrengthLowerLimit){
                isIncreasing = !isIncreasing;
            }
			lastReading = millis();
        }
		analogWrite(this->enablePin, currentWaterStrength);
    }
	Serial.print("TCCR0A: ");
	Serial.println(TCCR0A);
	Serial.print("TCCR0B: ");
	Serial.println(TCCR0B);
	Serial.print("TIMSK0: ");
	Serial.println(TIMSK0);
	Serial.print("OCR0A: ");
	Serial.println(OCR0A);
	Serial.print("OCR0B: ");
	Serial.println(OCR0B);
	turnOffPump();
}

void Pump::turnOffPump() {
    analogWrite(this->enablePin, 0);
    digitalWrite(this->topControlPin, LOW);
}

uint8_t Pump::getEnablePin() {
    return this->enablePin;
}

uint8_t Pump::getTopControlPin() {
    return this->topControlPin;
}

uint8_t Pump::getBottomControlPin() {
    return this->bottomControlPin;
}

void Pump::setEnablePin(uint8_t enablePin) {
    this->enablePin = enablePin;
}

void Pump::setTopControlPin(uint8_t topControlPin) {
    this->topControlPin = topControlPin;
}

void Pump::setBottomControlPin(uint8_t bottomControlPin) {
    this->bottomControlPin = bottomControlPin;
}
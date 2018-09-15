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


void Pump::startPump(uint8_t pumpStrength) {
    digitalWrite(this->topControlPin, HIGH);
    digitalWrite(this->bottomControlPin, LOW);
    //Activate Phase correct PWM
    uint8_t temp = TCCR0A;
    temp = temp & 0x0C;
    TCCR0A = temp | 0x81;

    temp = TCCR0B;
    temp = temp & 0x30;
    TCCR0B = temp | 0x04;

    //Enable Interrupt
    temp = TIMSK0 & 0xF8;
    TIMSK0 = temp | 0x01;

    OCR0A = pumpStrength;
}


//Strength refers to an analog value between 0 - 255
void Pump::runPump(int timeInMilliSeconds, uint8_t maxStrength, uint8_t minimumStrength, uint8_t strengthChange, int strengthChangeInterval) {
    this->timer = millis();
    //First three variables are used to control the water pressure out of the pump
    //Records time of last insterval change
    uint32_t lastStrengthChange = this->timer;
    //Records the current strength of the pump
    uint8_t currentStrength = minimumStrength;
    //The strength change is positive when isInreasing is true. Otherwise it is decreasing
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
        if ((millis() - lastStrengthChange) > strengthChangeInterval) {
            //Increase by fluctuation amount when increasing
            if (isIncreasing) {
                currentStrength += strengthChange;
            } else {
                currentStrength -= strengthChange;
            }

            //Switch directions once in a while
            if(currentStrength > maxStrength || currentStrength <= minimumStrength){
                isIncreasing = !isIncreasing;
            }
			lastStrengthChange = millis();
        }
		analogWrite(this->enablePin, currentStrength);
    }
    stopPump();
}

void Pump::stopPump() {
    analogWrite(this->enablePin, 0);
    digitalWrite(this->topControlPin, LOW);
}


//Getters
uint8_t Pump::getEnablePin() {
    return this->enablePin;
}

uint8_t Pump::getTopControlPin() {
    return this->topControlPin;
}

uint8_t Pump::getBottomControlPin() {
    return this->bottomControlPin;
}


//Setters
void Pump::setEnablePin(uint8_t enablePin) {
    this->enablePin = enablePin;
}

void Pump::setTopControlPin(uint8_t topControlPin) {
    this->topControlPin = topControlPin;
}

void Pump::setBottomControlPin(uint8_t bottomControlPin) {
    this->bottomControlPin = bottomControlPin;
}
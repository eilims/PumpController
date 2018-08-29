//
// Created by db217620 on 6/14/2018.
//

#include "Sensor.h"

Sensor::Sensor() {
    this->dataPin = 0;
    this->data = 0;
    this->macAddress = NULL;
    this->sensorType = NULL;
}

Sensor::Sensor(uint8_t powerPin, uint8_t dataPin, char* sensorType) {
    this->powerPin = powerPin;
    this->dataPin = dataPin;
    this->data = 0;
    this->macAddress = NULL;
    this->sensorType = sensorType;
    pinMode(this->powerPin, OUTPUT);
}

Sensor::Sensor(char *macAddress, char* sensorType) {
    this->dataPin = 0;
    this->data = 0;
    this->macAddress = macAddress;
    this->sensorType = sensorType;
}

Sensor::~Sensor() {

}

unsigned int Sensor::updateDataViaPin(int samples) {
    digitalWrite(powerPin, HIGH);
    delay(10);
	this->data = 0;
	for(int i = 0; i < samples; i++){
		int temp = analogRead(this->dataPin);
		this->data += temp;
		delay(1);
	}
	this->data = this->data / samples;
	digitalWrite(powerPin, LOW);
    return this->data;
}

int Sensor::updateDataViaMacAddress() {
    //Empty for now
}

uint8_t Sensor::getPowerPin() {
    return this->powerPin;
}

uint8_t Sensor::getDataPin() {
    return this->dataPin;
}

int Sensor::getData() {
    return this->data;
}

char* Sensor::getMacAddress() {
    return this->macAddress;
}

char* Sensor::getSensorType() {
    return this->sensorType;
}

void Sensor::setDataPin(uint8_t dataPin) {
    this->dataPin = dataPin;
}

void Sensor::setPowerPin(uint8_t powerPin) {
    this->powerPin = powerPin;
}

//Returns the pointer to the original char array
char* Sensor::setMacAddress(char *macAddress) {
    char* temp = this->macAddress;
    this->macAddress = macAddress;
    return temp;
}

char* Sensor::setSensorType(char *sensorType) {
    char* temp = this->sensorType;
    this->sensorType = sensorType;
    return temp;
}

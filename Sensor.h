//
// Created by db217620 on 6/14/2018.
//

#ifndef LINKEDLIST_SENSOR_H
#define LINKEDLIST_SENSOR_H

//#include <windef.h>
//#include <cstdint>
#include <Arduino.h>

class Sensor {

private:
    uint8_t powerPin;
    uint8_t dataPin;
    unsigned int data;
    char *macAddress;
    char *sensorType;

public:
    Sensor();

    Sensor(uint8_t powerPin, uint8_t dataPin, char* sensorType);

    Sensor(char *macAddress, char* sensorType);

    ~Sensor();

    unsigned int updateDataViaPin(int samples);

    int updateDataViaMacAddress();

	
	//Getters
    uint8_t getPowerPin();

    uint8_t getDataPin();

    int getData();

    char *getMacAddress();

    char *getSensorType();

	
	//Setters
    void setDataPin(uint8_t dataPin);

    void setPowerPin(uint8_t powerPin);

    char* setMacAddress(char *macAddress);

    char* setSensorType(char *sensorType);
};


#endif //LINKEDLIST_SENSOR_H

//
// Created by db217620 on 6/17/2018.
//

#ifndef LINKEDLIST_PUMP_H
#define LINKEDLIST_PUMP_H


//#include <cstdint>
#include <Arduino.h>

class Pump {
private:
    uint8_t enablePin;
    uint8_t topControlPin;
    uint8_t bottomControlPin;
    uint32_t timer;

public:
    Pump(uint8_t enablePin, uint8_t topControlPin, uint8_t bottomControlPin);
    ~Pump();

    void turnOnPump(int timeInMilliSeconds, uint8_t waterStrength, uint8_t fluctuationAmount, uint8_t waterStrengthLowerLimit, int intervalTime);
    void turnOffPump();

    uint8_t getEnablePin();
    uint8_t  getTopControlPin();
    uint8_t  getBottomControlPin();

    void setEnablePin(uint8_t enablePin);
    void setTopControlPin(uint8_t topControlPin);
    void setBottomControlPin(uint8_t  bottomControlPin);
};


#endif //LINKEDLIST_PUMP_H

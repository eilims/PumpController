//
// Created by db217620 on 6/25/2018.
//

#ifndef LINKEDLIST_HARDWARETIMER1_H
#define LINKEDLIST_HARDWARETIMER1_H

#include <cstdint>
//#include <Arduino.h>

class HardwareTimer1 {
private:
    int timerCount;
    int timerCompare;
    const uint8_t prescaleEnable256 = 0x08;
    const uint8_t prescaleDisable = 0x00;
    const uint8_t enableClock = 0x0D;
    const uint8_t disableClock = 0x00;

public:
    HardwareTimer1();

    ~HardwareTimer1();

    void startTimer1();

    void stopTimer1();

    void resetCount();

    int getTimerCount() const;

    int getTimerCompare() const;

    void setTimerCompare(int timerCompare);
};


#endif //LINKEDLIST_HARDWARETIMER1_H

//
// Created by db217620 on 6/25/2018.
//


#include "HardwareTimer1.h"

HardwareTimer1::HardwareTimer1() {
    uint8_t temp;
    //Disable interrupts during setup
    noInterrupts();


    //Need 1100 XX10
    //Selecting compare output modes: OCA-> set on match, OCB->disabled
    //Selecting waveform (bits 1 - 0): generation mode -> 4 (CTC)
    temp = TCCR1A;
    temp = temp & 0x0C;
    Serial.println(temp);
    TCCR1A = temp | 0xC0;

    //Need 00XX 0111
    //Selecting Noise cancler -> disabled
    //Selecting waveform (bits 3 - 2): generation mode -> 4 (CTC)
    //Selecting prescaler amount / clock
    temp = TCCR1B;
    temp = temp & 0x20;
    TCCR1B = temp | this->disableClock;

    //Need 00XX 0111
    //Selecting force output compare: disabled
    temp = TCCR1C;
    temp = temp & 0x3F;
    TCCR1C = temp | 0x00;

    //Set current count to Zero
    TCNT1 = 0;

    //Set count top value as 65,535
    OCR1A = 0xFFFF;


    //Set interrupt mask to use ocr2a 0000 0010
    //Enable interrupt on TCNT1 match with OCA1 register
    temp = TIMSK1;
    temp = temp & 0xD8;
    TIMSK1 = temp | 0x02;

    //reenable interrupts
    interrupts();
}

HardwareTimer1::~HardwareTimer1() {

}

void HardwareTimer1::startTimer1() {
    //Eanble clock prescaler
    CLKPR = 0x80;
    CLKPR = this->prescaleEnable256;

    //Enable timer
    temp = TCCR1B;
    temp = temp & 0x20;
    TCCR1B = temp | this->enableClock;
}

void HardwareTimer1::stopTimer1() {
    //disable clock prescaler
    CLKPR = 0x80;
    CLKPR = this->prescaleDisable;

    //disable timer
    temp = TCCR1B;
    temp = temp & 0x20;
    TCCR1B = temp | this->disableClock;
}

void HardwareTimer1::resetCount() {
    TCNT1 = 0;
}

int HardwareTimer1::getTimerCompare() const {
    return timerCompare;
}

void HardwareTimer1::setTimerCompare(int timerCompare) {
    HardwareTimer1::timerCompare = timerCompare;
}

int HardwareTimer1::getTimerCount() const {
    return timerCount;
}

ISR(TIMER1_COMPA_vect){
    if(this->timerCount >= this->timerCompare){
        //Call something here
    } else {
        this->timerCount++;
    }
}
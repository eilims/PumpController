//
// Created by db217620 on 6/25/2018.
//


#include "HardwareTimer1.h"

HardwareTimer1* HardwareTimer1::instance = NULL;

//Private methods

HardwareTimer1::HardwareTimer1() {
    uint8_t temp;
	
    //Disable interrupts during setup
    noInterrupts();

    //Need 1100 XX10
    //Selecting compare output modes: OCA-> set on match, OCB->disabled
    //Selecting waveform (bits 1 - 0): generation mode -> 4 (CTC)
    temp = TCCR1A;
    temp = temp & 0x0C;
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




//Public methods

//Singleton method
HardwareTimer1* HardwareTimer1::Instance() {
    if(HardwareTimer1::instance == NULL){
        HardwareTimer1::instance = new HardwareTimer1();
    }
    return HardwareTimer1::instance;
}

void HardwareTimer1::startTimer1(int state) {
	noInterrupts();
    //Changes the global clock speed down to allow for longer/shorter timer durations
    CLKPR = 0x80;
	//see http://ww1.microchip.com/downloads/en/DeviceDoc/Atmel-42735-8-bit-AVR-Microcontroller-ATmega328-328P_Datasheet.pdf
	//For a breakdown of the Clock prescalar select on page 60
	switch(state){
		case 0:
			CLKPR = 0x00;
			break;
		case 8: 
			CLKPR = 0x08;
			break;
		default:
			CLKPR = 0x00;
			break;
	}
	
    //Enable timer
    uint8_t temp = TCCR1B;
    temp = temp & 0x20;
    TCCR1B = temp | this->enableClock;
	interrupts();
}

void HardwareTimer1::stopTimer1() {
	noInterrupts();
    //Changes the global clock speed down to allow for longer/shorter timer durations
    CLKPR = 0x80;
	//see http://ww1.microchip.com/downloads/en/DeviceDoc/Atmel-42735-8-bit-AVR-Microcontroller-ATmega328-328P_Datasheet.pdf
	//For a breakdown of the Clock prescalar select on page 60
	//returning speed back to normal for other operations
	CLKPR = 0x00;
	
    //disable timer by changing clock source to nothing
    uint8_t temp = TCCR1B;
    temp = temp & 0x20;
    TCCR1B = temp | this->disableClock;
	interrupts();
}

void HardwareTimer1::resetCount() {
    TCNT1 = 0;
}

void HardwareTimer1::incrementGlobalCounter() {
    this->timerCount++;
}

void HardwareTimer1::resetGlobalCounter() {
    this->timerCount = 0;
}




//Getters
int HardwareTimer1::getGlobalTimerCount() {
    return timerCount;
}

int HardwareTimer1::getGlobalTimerCompare() {
    return timerCompare;
}

uint16_t HardwareTimer1::getOcaValue(){
	return ocaValue;
}

callback_function HardwareTimer1::getTimerInterruptCallback() {
    return timerInterruptCallback;
}




//Setters
void HardwareTimer1::setTimerInterruptCallback(callback_function timerInterruptCallback) {
    this->timerInterruptCallback = timerInterruptCallback;
}

void HardwareTimer1::setOcaValue(uint16_t ocaValue){
	OCR1A = ocaValue;
	this->ocaValue = ocaValue;
}

void HardwareTimer1::setGlobalTimerCompare(int timerCompare){
	this->timerCompare = timerCompare;
}


//This ISR will trigger on the OCR1A Interrupt
//If properly configured the program will gop to the function passed in through setTimerInterruptCallback
ISR(TIMER1_COMPA_vect){
    if(HardwareTimer1::Instance()->getGlobalTimerCompare() <= HardwareTimer1::Instance()->getGlobalTimerCount() ){
        HardwareTimer1::Instance()->getTimerInterruptCallback()();
		HardwareTimer1::Instance()->resetGlobalCounter();
    } else {
        HardwareTimer1::Instance()->incrementGlobalCounter();
    }
}
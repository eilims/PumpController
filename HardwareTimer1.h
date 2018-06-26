//
// Created by db217620 on 6/25/2018.
//

#ifndef LINKEDLIST_HARDWARETIMER1_H
#define LINKEDLIST_HARDWARETIMER1_H

//#include <cstdint>
#include <Arduino.h>

typedef void (*callback_function)(void);


class HardwareTimer1 {
private:
	//Constructors and deconstructors are private for singleton gurantee
    HardwareTimer1();
    ~HardwareTimer1();
	
	//allows for singleton access for user and in .cpp
    static HardwareTimer1* instance;
	
	
	//General variables
	//Number of times the timer hit OCR1A
    int timerCount;
	//User selected number of times required to trigger user callback 
    int timerCompare;
	//User set value where Interrupt Service Routine (ISR) is triggered when the timer counts up
	uint16_t ocaValue;
	//Allows for the later callback of user defined functions when the ISR is triggered and all conditions met
	callback_function timerInterruptCallback;
	
	//Some constants for timer control
    const uint8_t enableClock = 0x0D;
    const uint8_t disableClock = 0x08;
	


public:

	//Returns the pointer to the single timer1 object
    static HardwareTimer1* Instance();

	//Increments global timer recording number of times the ISR has been called
    void incrementGlobalCounter();

	//Starts the timer at the requested clock speed
	//Passing in any value but zero WILL SLOW DOWN THE ENTIRE ARDUINO
	//See cpp for link to appropriate manual page
    void startTimer1(int state);

	//Stops the timer and returns the clock to a nonprescaled state
    void stopTimer1();

	//Resets the internal timers count
    void resetCount();
	
	//Resets the global timers count which is recording number of times the ISR has been called
	void resetGlobalCounter();


	//Getters
    int getGlobalTimerCount();

    int getGlobalTimerCompare();
	
	uint16_t getOcaValue();
	
	callback_function getTimerInterruptCallback();
	
	//Setters
		
    void setGlobalTimerCompare(int timerCompare);

    void setTimerInterruptCallback(callback_function timerInterruptCallback);
	
	void setOcaValue(uint16_t ocaValue);
	
	
};

#endif //LINKEDLIST_HARDWARETIMER1_H

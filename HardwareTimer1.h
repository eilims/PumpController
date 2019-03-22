//
// Created by db217620 on 6/25/2018.
//

#ifndef LINKEDLIST_HARDWARETIMER1_H
#define LINKEDLIST_HARDWARETIMER1_H

//#include <cstdint>
#include <Arduino.h>

typedef void (*callback_function)(void);

/*
 * Description of timer calculation function and example
 * Prescaler for timer is at clk / 1024
 * Prescaler for clock can be: 0 - 256 (powers of 2)
 * System clock is 16 MHz
 * ocaValue defines number before making an ISR call
 * timerCompare defines the number of ISR calls needed before calling the given function
 * Time calculation function (with 256 clock prescale, ocaValue of 0xFFFF, and timerCompare of 0):
 * This means the given function will be called when the ISR if first called after the timer
 * counts up to 0xFFFF.
 * timer_clock_speed_MHz = (16MHz / (256 * 1024))
 * ISR_call_rate_MHz = timer_clock_speed_MHz / 65536
 * timer_until_function_call_s = 1 / (ISR_call_rate_MHz * (0 + 1)) Note: 0 is timerCompare + 1 for nonzero effect
 * This is roughly 1073 seconds
 * time_s = (256 * 1024 * 65536 * (0 + 1)) / (16MHz)
 * Calculation of 1 second ocaValue
 * ocaValue = ((16MHz * 1s)/(256 * 1024))
 * This is roughly 61 
 */
class HardwareTimer1 {
private:
	//Constructors and deconstructors are private for singleton gurantee
    HardwareTimer1();
    ~HardwareTimer1();
	
	//allows for singleton access for user and in .cpp
    static HardwareTimer1* instance;
	
	
	//General variables
	//Number of times the timer called ISR
    int timerCount;
	// Number of ISR triggers required to trigger user callback function
    int timerCompare;
	// Number of clock ticks to trigger Interrupt Service Routine (ISR)
	uint16_t ocaValue;
	// Function to be called when timerCount == timerCompare
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

	//Performs the interrupt routine function and incrementing if the count is not reached
	void interruptRoutine();


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

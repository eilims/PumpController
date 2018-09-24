#include <HardwareTimer1.h>
#include <LinkedList.h>
#include <Node.h>
#include <PID.h>
#include <Pump.h>
#include <Sensor.h>
#include <SensorList.h>

Pump* mainPump;
Pump* circulationPump;
HardwareTimer1* timer;

int circulatingPumpStrength = 255;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
  //init
  mainPump = new Pump(5, 2, 3);
  circulationPump = new Pump(6, 7, 8);
  //Setting up timer for an interrupt every minute
  timer = HardwareTimer1::Instance();
  timer->setTimerInterruptCallback(&timerInterrupt);
  timer->setOcaValue(0xE4E);

  //start logic
  circulationPump->startPump(circulatingPumpStrength);
  timer->startTimer1(8);
}

void loop() {
  // put your main code here, to run repeatedly:
}

void timerInterrupt(){
  timer->stopTimer1();
  circulationPump->stopPump();
  mainPump->runPump(10000, 200, 1, 10, 100);
  circulationPump->startPump(circulatingPumpStrength);
  timer->startTimer1(8);
}

#include <HardwareTimer1.h>
#include <LinkedList.h>
#include <Node.h>
#include <PID.h>
#include <Pump.h>
#include <Sensor.h>
#include <SensorList.h>

Pump* pump;
HardwareTimer1 *timer;


//REquires 2 LEDs one in pin siz and another in pin 11 to show test results
void setup() {
  Serial.begin(9600);
  //USed to test second led
  pinMode(11, OUTPUT);
  //Timer config
  timer = HardwareTimer1::Instance();
  //trash function pointer does nothing
    timer->setTimerInterruptCallback(&changeData);
  timer->setOcaValue(0x00FF);
  timer->setGlobalTimerCompare(0);
  timer->startTimer1(8);
  //create pump
  pump = new Pump(6, 1, 2);
  //debug data
  Serial.println(TCCR0A);
  Serial.println(TCCR0B);
  Serial.println(TIMSK0);
  //start analog writing. It will go on forever
  pump->startPump(100);
  analogWrite(11, 100);
  //debug 
  Serial.println(TCCR0B);
}

void loop() {
  // put your main code here, to run repeatedly:
}

//trash function does nothing
void changeData(){
}

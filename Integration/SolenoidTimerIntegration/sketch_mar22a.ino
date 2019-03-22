#include <HardwareTimer1.h>
#include <LinkedList.h>
#include <Node.h>
#include <PID.h>
#include <Pump.h>
#include <Sensor.h>
#include <SensorList.h>

Pump pump(6, 5, 4);
bool data = false;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(13, OUTPUT);

  HardwareTimer1::Instance()->setTimerInterruptCallback(&timerInterrupt);
  // Two minutes
  HardwareTimer1::Instance()->setOcaValue(7324);
  HardwareTimer1::Instance()->setGlobalTimerCompare(0);
  HardwareTimer1::Instance()->startTimer1(8);
}

void loop() {
  // put your main code here, to run repeatedly:

}

void timerInterrupt(){
  Serial.print("Starting Cycle");
  pump.runSolenoid(10000);
  Serial.print("Cycle Complete");
}

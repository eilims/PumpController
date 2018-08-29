#include <HardwareTimer1.h>
#include <LinkedList.h>
#include <Node.h>
#include <PID.h>
#include <Pump.h>
#include <Sensor.h>


Pump pump(5, 2, 3);
bool data = false;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(13, OUTPUT);

  HardwareTimer1::Instance()->setTimerInterruptCallback(&timerInterrupt);
  HardwareTimer1::Instance()->setOcaValue(0xFFFF);
  HardwareTimer1::Instance()->setGlobalTimerCompare(0);
  HardwareTimer1::Instance()->startTimer1(0);
}

void loop() {
  // put your main code here, to run repeatedly:
    // put your main code here, to run repeatedly:
  Serial.print("Start Time: ");
  Serial.println(millis());
  pump.runPump(100, 100, 1, 100, 10);
  Serial.print("End Time: ");
  Serial.println(millis());
  delay(600);
}

void timerInterrupt(){
  if(data){
    digitalWrite(13, LOW);
  } else {
    digitalWrite(13, HIGH);
  }
  data = !data;
}


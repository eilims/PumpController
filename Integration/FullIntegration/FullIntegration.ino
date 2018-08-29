#include <HardwareTimer1.h>
#include <LinkedList.h>
#include <Node.h>
#include <PID.h>
#include <Pump.h>
#include <Sensor.h>
#include <SensorList.h>

PID pid(0.75, 0.45, 0.08);
Pump waterPump(5, 2, 3);
Pump circulationPump(4,2,3);
SensorList sensorList;
HardwareTimer1* timer;

bool isInterruptCalled;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  //Timer setup
  timer = HardwareTimer1::Instance();
  timer->setTimerInterruptCallback(&timerInterrupt);
  timer->setOcaValue(0xFFFF);
  // 1 hour ~ 4
  // 1 day ~ 81
  // Frequency / (Clock Prescaler * timer prescaler * OcaValue)
  // This example uses state 0 in the start function
  // 16000000/(256*1024*(2^16)) * (desired time before calling function in seconds)
  timer->setGlobalTimerCompare(4);
  timer->startTimer1(0);

  //SensorList setup
  sensorList.addSensor(new Sensor(13, A0));
  sensorList.addSensor(new Sensor(13, A1));
  sensorList.addSensor(new Sensor(13, A2));
  sensorList.addSensor(new Sensor(13, A3));

  isInterruptCalled = false;
}

void timerInterrupt(){
    isInterruptCalled = true;
}


void loop() {
  // put your main code here, to run repeatedly:
  if(isInterruptCalled){
    //Timer control logic
    timer->stopTimer1();
    isInterruptCalled = false;

    //Getting data from sensors and processing it
    unsigned int averageSensorData = sensorList.getSensorDataAverage(20);
    int processVariable = pid.generateNewProcessVariable(averageSensorData);
    
    //Watering time is in minutes
    double wateringTime = 306 * (0.771 * exp(.00393*(double)processVariable)/100) + .00103;
    //round up for ease of use
    wateringTime = ceil(wateringTime);
    //Convert to milliseconds for timing
    wateringTime = wateringTime * 1000;

    //Pump Control logic
    circulationPump.stopPump();
    waterPump.runPump(wateringTime, 255, 120, 10, 1);
    circuilationPump.startPump(120);
    timer->startTimer1(0);
  }
}

#include <HardwareTimer1.h>
#include <LinkedList.h>
#include <Node.h>
#include <PID.h>
#include <Pump.h>
#include <Sensor.h>
#include <SensorList.h>

PID pid(0.75, 0.45, 0.08);
Pump pump(6, 5, 4);
SensorList sensorList;
Sensor sensor0(13, A0, "Moisture Sensor 0");
Sensor sensor1(13, A1, "Moisture Sensor 1");
Sensor sensor2(13, A2, "Moisture Sensor 2");
Sensor sensor3(13, A3, "Moisture Sensor 3");

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  pid.setSetPoint(850);

  list.addSensor(sensor0);
  list.addSensor(sensor1);
  list.addSensor(sensor2);
  list.addSensor(sensor3);

  HardwareTimer1::Instance()->setTimerInterruptCallback(&timerInterrupt);
  // Two minutes
  HardwareTimer1::Instance()->setOcaValue(7324);
  HardwareTimer1::Instance()->setGlobalTimerCompare(0);
  HardwareTimer1::Instance()->startTimer1(8);
}

void loop() {
  // put your main code here, to run repeatedly:
}

// TODO add button watering interrupt

void timerInterrupt(){
  Serial.println("Processing Sensor Input");
  unsigned int averageSensorData = sensorList.getSensorDataAverage(40);
  Serial.println("Sensor Average: ");
  Serial.print(averageSensorData);
  
  Serial.println("Processing PID Output");
  double pidOutput = pid.generateNewProcessVariable(averageSensorData);
  Serial.println("PID Output: ");
  Serial.print(pidOutput);
  
  Serial.println("Calculate Missing Volume Water Content");
  // See Soil Moisture Experiment for equation 
  double missingVwc_percent = exp((pidOutput - 62.2)/255)/100;
  Serial.println("Missing Volume Water Content (Percent): ");
  Serial.print(missingVwc_percent);

  Serial.println("Calculate Watering Time");
  // See Water Hole Diameter for equation
  double wateringTime_milli = (missingVwc_percent / 0.000972) * 60000;
  Serial.println("Watering Time (Millisecond): ");
  Serial.print(wateringTime_milli);
  
  Serial.print("Starting Cycle");
  pump.runSolenoid(wateringTime_milli);
  Serial.print("Cycle Complete");
}

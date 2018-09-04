#include <HardwareTimer1.h>
#include <LinkedList.h>
#include <Node.h>
#include <PID.h>
#include <Pump.h>
#include <Sensor.h> 
#include <SensorList.h>

SensorList list;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Sensor *sensor = new Sensor(13, A0, "Moisture Sensor 0");
  list.addSensor(sensor);
  sensor = new Sensor(13, A1, "Moisture Sensor 1");
  list.addSensor(sensor);
  sensor = new Sensor(13, A2, "Moisture Sensor 2");
  list.addSensor(sensor);
  sensor = new Sensor(13, A3, "Moisture Sensor 3");
  list.addSensor(sensor);
}

void loop() {
  // put your main code here, to run repeatedly:
  int samples = 20;
  Serial.print("Min: ");
  Serial.println(list.getSensorDataMin(samples));
  Serial.print("Average: ");
  Serial.println(list.getSensorDataAverage(samples));
  Serial.print("Max: ");
  Serial.println(list.getSensorDataMax(samples));
  delay(1000);
}
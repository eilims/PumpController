#include <HardwareTimer1.h>
#include <LinkedList.h>
#include <Node.h>
#include <PID.h>
#include <Pump.h>
#include <Sensor.h>

Sensor *sensor1;

Sensor *sensor2;

Sensor *sensor3;

Sensor *sensor4;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  sensor1 = new Sensor(13, A0);
  sensor2 = new Sensor(13, A1);
  sensor3 = new Sensor(13, A2);
  sensor4 = new Sensor(13, A3);
}

void loop() {
  // put your main code here, to run repeatedly:
  int data1 = sensor1->updateDataViaPin(50);
  int data2 = sensor2->updateDataViaPin(50);
  int data3 = sensor3->updateDataViaPin(50);
  int data4 = sensor4->updateDataViaPin(50);
  Serial.print("Result 1: ");
  Serial.println(data1);
  Serial.print("Result 2: ");
  Serial.println(data2);
  Serial.print("Result 3: ");
  Serial.println(data3);
  Serial.print("Result 4: ");
  Serial.println(data4);
  
  delay(1000);
}

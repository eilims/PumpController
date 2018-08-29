#include <HardwareTimer1.h>
#include <LinkedList.h>
#include <Node.h>
#include <PID.h>
#include <Pump.h>
#include <Sensor.h>


Pump pump1(5, 2, 3);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print("Start Time: ");
  Serial.println(millis());
  pump1.runPump(10000, 130, 0, 130, 0);
//  pump1.runPump(10000, 200, 1, 39, 10);
  Serial.print("End Time: ");
  Serial.println(millis());
  delay(600);
}

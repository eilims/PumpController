#include <HardwareTimer1.h>
#include <LinkedList.h>
#include <Node.h>
#include <PID.h>
#include <Pump.h>
#include <Sensor.h>
#include <SensorList.h>

Pump pump(6, 5, 4);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  Serial.print("Starting Cycle");
  pump.runSolenoid(10000);
  delay(2000);
  Serial.print("Cycle Complete");
}

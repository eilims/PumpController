#include <GPS.h>
#include <H2RoverXbee.h>
#include <IMU.h>
#include <MoistureSensor.h>
#include <MotorControl.h>
#include <PinDeclarations.h>
#include <Ultrasound.h>

MotorControl Red;
int count = 0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  Red.motorForward(count);
  delay(1000);
  count++;
  Serial.println(count);
  while(1){

    Red.motorOff();
  }
}

#include <GPS.h>
#include <H2RoverXbee.h>
#include <IMU.h>
#include <MoistureSensor.h>
#include <MotorControl.h>
#include <PinDeclarations.h>
#include <Ultrasound.h>

#define TIME_WAITED millis() - time

MotorControl Red;

volatile boolean bumperFlag;

static unsigned long time;

int probeStrength = 130;

void setup() {
  time = 0;
  // put your setup code here, to run once:
  Serial.begin(9600);

  // bumper setup
  bumperFlag = false;
  pinMode(FEELER, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(FEELER), stopRed, FALLING);
}

void loop() {
  while(!bumperFlag){
    Red.probeDown(probeStrength);
  }

  bumperFlag = false;
  Red.probeOff();
  Red.probeUp(probeStrength);

  time = millis(); // start stopwatch
  while (TIME_WAITED <= 400){
    //Serial.println(TIME_WAITED);
  }

  bumperFlag = false;
  Red.probeOff();
  Serial.println(bumperFlag);
  
  while(!bumperFlag){
    Red.probeUp(probeStrength);
  }

  bumperFlag = false;
  Red.probeOff();
  Red.probeDown(probeStrength);

  time = millis(); // start stopwatch
  while (TIME_WAITED <= 400){
    //Serial.println(TIME_WAITED);
  }
  
  bumperFlag = false;
  

  
}

void stopRed() {
  bumperFlag = true;
}

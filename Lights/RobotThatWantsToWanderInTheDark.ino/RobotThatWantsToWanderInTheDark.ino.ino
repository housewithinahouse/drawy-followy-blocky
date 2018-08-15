/*
 * This example code has been written by Edwin Fallwell 
 * & Matt Neer for the Monroe County Public Library in Bloomington, IN.
 * 
 * MIT license, check LICENSE for more information */


// we include our TwoWheeledRobot libary, which has all of our motor control functions 
#include <TwoWheelRobot.h>

// create a TwoWheelRobot object, which we will address
// when we want to issue commands to our photophobe
TwoWheelRobot photophobe = TwoWheelRobot();

int leftSensorPin = A0;
int rightSensorPin = A1; 

int bumpSensorPin = 20;

int leftSensorLightLevel = 0;
int rightSensorLightLevel = 0;
int high, low, ave = 0;

bool tooBright = false;
int brightnessThreshold = 300;

bool bumped = false;




void setup() {
  // start up the two wheel robot library
  photophobe.initalize();
  photophobe.setSpeed(100);
  Serial.begin(9600);
}

void loop() {  
  checkLightSensors();
  computeAverages();
  determineIfItIsTooBright();
  
  if(!tooBright){
    wanderRandomly();
  }
  else{
    runAwayFromLight();
  }
  
  
}

void checkLightSensors(){
  leftSensorLightLevel = analogRead(leftSensorPin);   
  rightSensorLightLevel = analogRead(rightSensorPin);
  Serial.print("left: "); 
  Serial.println(leftSensorLightLevel);
  Serial.println("right: ");
  Serial.println(rightSensorLightLevel);
}

void computeAverages(){
  ave = (leftSensorLightLevel + rightSensorLightLevel) / 2;
  low = ave - 5;
  high = ave + 5;
}

void determineIfItIsTooBright(){
  if(leftSensorLightLevel > brightnessThreshold || rightSensorLightLevel > brightnessThreshold){
    tooBright = true;
  }
  else{
    tooBright = false;
  }
}

void wanderRandomly(){
  photophobe.forward();
  checkBumpSensors();
  
  if(bumped){
    photophobe.left(200);
    bumped = false;    
  }
}

void runAwayFromLight(){
  if(leftSensorLightLevel < high && leftSensorLightLevel > low){
    photophobe.backward();
  }
  else if(leftSensorLightLevel < rightSensorLightLevel){
    photophobe.backwardRight();
  }
  else if(leftSensorLightLevel > rightSensorLightLevel){
    photophobe.backwardLeft();
  }
}

void checkBumpSensors(){
  bumped = digitalRead(bumpSensorPin);  
}


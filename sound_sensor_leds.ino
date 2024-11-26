#include <NanitLib.h>

byte redLed = P4_3;
byte greenLed = P4_4;
byte soundSensor = P9_3;

byte redLedValues[5] = {0, 127, 255, 0, 0};
byte greenLedValue[5] = {0, 0, 0, 127, 255};


byte iterration = 0;

volatile bool isInterruptState = false;

void setup() {
  Nanit_Base_Start();
  pinMode(redLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
  attachInterrupt(digitalPinToInterrupt(P9_3), lightLedISR, RISING);
}

void loop() {
  if(isInterruptState){
    setNextIterration();
    analogWrite(redLed, redLedValues[iterration]);
    analogWrite(greenLed, greenLedValue[iterration]);

    isInterruptState = false;
  }
  delay(100);
}

void lightLedISR(){
  isInterruptState = true;
}

void setNextIterration(){
  if(iterration == 4){
    iterration = 0;
  } else{
    iterration++;
  }
}
#include <Stepper.h>
int laser = 2;
const int stepsPerRevolution = 2048;
Stepper myStepper(stepsPerRevolution, 8, 10, 9, 11);
int br;
void setup() {
  pinMode(laser, OUTPUT);
  myStepper.setSpeed(5);  // Slow speed for testing
  Serial.begin(9600);
  Serial.println("Send 'R' or 'r' to rotate 22.5° clockwise.");
}

void loop() {
      digitalWrite(laser, HIGH);
      for(int i = 0; i < 10; i++){
      br++;
      delay(5000);
      if(br < 8){
         
              Serial.println("Rotating 22.5°...");
      myStepper.step(128);  // 512 steps = 90° (2048 steps/360°)
      Serial.println("Done!");
        }
        if(br == 8){
           Serial.println("Rotating -157.5°...");
      myStepper.step(-896);  // 512 steps = 90° (2048 steps/360°)
      Serial.println("Done!");
      br = 0;
          }
      }
     
    
  }

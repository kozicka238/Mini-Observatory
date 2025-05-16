#include <Stepper.h>
const int stepsPerRevolution = 4096;
Stepper myStepper(stepsPerRevolution, 8, 10, 9, 11);
int br;
void setup() {
  myStepper.setSpeed(5);  // Slow speed for testing
  Serial.begin(9600);
  Serial.println("Send 'R' to rotate 45° clockwise.");
}

void loop() {
  if (Serial.available() > 0) {
    char command = Serial.read();
    if (command == 'R') {
      br++;
      switch(br)
      {
        case 1: Serial.print("mercury "); break;
        case 2: Serial.print("Venus "); break;
        case 3: Serial.print("Mars "); break;
        case 4: Serial.print("Jupiter "); break;
        case 5: Serial.print("Satrun "); break;
        case 6: Serial.print("Uranus "); break;
        case 7: Serial.print("Neptun "); break;
        case 8: Serial.print("Pluto "); break;
        case 9: br = 0; return;
      }
      Serial.println("Rotating 90°...");
      myStepper.step(256);  // 512 steps = 90° (2048 steps/360°)
      Serial.println("Done!");
    }
  }
}

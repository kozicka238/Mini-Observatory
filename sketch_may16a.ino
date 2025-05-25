#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#include <Stepper.h>


LiquidCrystal_I2C lcd(0x27,16,2);  // set the LCD address to 0x27 for a 16 chars and 2 line display

const int stepsPerRevolution = 2048;

Stepper myStepper(stepsPerRevolution, 8, 10, 9, 11);

int br;

int laser = 2;

void setup() 
{

  lcd.init();
  lcd.backlight();
  myStepper.setSpeed(10);  
  lcd.setCursor(0,0);
  lcd.print("Solar System");
  Serial.begin(9600);
}

void loop() 
{
 
    while(true)
    {
       br++;   
      switch(br)
      {
        case 1: Serial.println("Rotating 22.5°..."), myStepper.step(128), Serial.println("Done!"), Mercury(), delay(5000);
        case 2: Serial.println("Rotating 22.5°..."), myStepper.step(128), Serial.println("Done!"), Venus(), delay(5000);
        case 3: Serial.println("Rotating 22.5°..."), myStepper.step(128), Serial.println("Done!"), Mars(), delay(5000);
        case 4: Serial.println("Rotating 22.5°..."), myStepper.step(128), Serial.println("Done!"), Jupiter(), delay(5000);
        case 5: Serial.println("Rotating 22.5°..."), myStepper.step(128), Serial.println("Done!"), Saturn(), delay(5000);
        case 6: Serial.println("Rotating 22.5°..."), myStepper.step(128), Serial.println("Done!"), Uranus(), delay(5000);
        case 7: Serial.println("Rotating 22.5°..."), myStepper.step(128), Serial.println("Done!"), Neptune(), delay(5000);
        case 8: Serial.println("rotating -157.5°..."), myStepper.step(-896),Serial.println("Done!"), br = 0; return;
      }
    }
     
}


void Mercury (){
  clearPlanetInfo();
  lcd.setCursor(0,0);
  lcd.print("Mercury");
  lcd.setCursor(0,1);
  lcd.print("4 878 KM");
}

void Venus (){
  clearPlanetInfo();
  lcd.setCursor(0,0);
  lcd.print("Venus");
  lcd.setCursor(0,1);
  lcd.print("12 104 KM");
}

void Mars (){
  clearPlanetInfo();
  lcd.setCursor(0,0);
  lcd.print("Mars");
  lcd.setCursor(0,1);
  lcd.print("6 779 KM");
}

void Jupiter (){
  clearPlanetInfo();
  lcd.setCursor(0,0);
  lcd.print("Jupiter");
  lcd.setCursor(0,1);
  lcd.print("139 820 KM");
}

void Saturn (){
  clearPlanetInfo();
  lcd.setCursor(0,0);
  lcd.print("Saturn");
  lcd.setCursor(0,1);
  lcd.print("116 500 KM");
}

void Uranus (){
  clearPlanetInfo();
  lcd.setCursor(0,0);
  lcd.print("Uranus");
  lcd.setCursor(0,1);
  lcd.print("51 118 KM");
}

void Neptune (){
  clearPlanetInfo();
  lcd.setCursor(0,0);
  lcd.print("Neptune");
  lcd.setCursor(0,1);
  lcd.print("49 528 KM");
}

void Pluto (){
  clearPlanetInfo();
  lcd.setCursor(0,0);
  lcd.print("Pluto");
  lcd.setCursor(0,1);
  lcd.print("2 377 KM");
}

void clearPlanetInfo(){
  lcd.clear();
  delay(500);
}

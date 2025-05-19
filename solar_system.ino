#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);  // set the LCD address to 0x27 for a 16 chars and 2 line display

byte mercury = A0;
byte venus = A1;
byte mars = A2;
byte jupiter = A3;
byte saturn =  A4; 
byte uranus = A5;
byte neptune = A6;
byte pluto = A7;

void setup() {
  // put your setup code here, to run once:
  lcd.init();                      // initialize the lcd 
  // Print a message to the LCD.
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("Solar System");
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  int mercuryRead = analogRead(mercury);
  int venusRead = analogRead(venus);
  int marsRead = analogRead(mars);
  int jupiterRead = analogRead(jupiter);
  int saturnRead = analogRead(saturn);
  int uranusRead = analogRead(uranus);
  int neptuneRead = analogRead(neptune);
  int plutoRead = analogRead(pluto);

  Serial.println(mercuryRead);

  if(mercuryRead > 0 && mercuryRead < 100){
    Mercury();
    delay(5000);
  }
  if(venusRead > 0 && venusRead < 100){
    Venus();
    delay(5000);
  }
  if(marsRead > 0 && marsRead < 100){
    Mars();
    delay(5000);
  }
  if(jupiterRead > 0 && jupiterRead < 100){
    Jupiter();
    delay(5000);
  }
  if(saturnRead > 0 && saturnRead < 100){
    Saturn();
    delay(5000);
  }
  if(uranusRead > 0 && uranusRead < 100){
    Uranus();
    delay(5000);
  }
  if(neptuneRead > 0 && neptuneRead < 100){
    Neptune();
    delay(5000);
  }
  if(plutoRead > 0 && plutoRead < 100){
    Pluto();
    delay(5000);
  }
  
  else {
    clearPlanetInfo();
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
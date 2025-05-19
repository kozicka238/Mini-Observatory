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

void clearPlanetInfo(){
  lcd.clear();
  delay(500);
}

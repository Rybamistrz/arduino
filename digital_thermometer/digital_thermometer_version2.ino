#include <LiquidCrystal.h>
#include <OneWire.h>
#include <DallasTemperature.h>

#define led_red 7
#define led_green 8
#define led_yellow 9

LiquidCrystal lcd(12, 11, 6, 5, 4, 3);
OneWire onewire(2);
DallasTemperature sensors(&onewire);

void setup() {
  lcd.begin(16, 2);
  lcd.print("Temperature:");
  sensors.begin();
  pinMode(led_red, OUTPUT);
  pinMode(led_green, OUTPUT);
  pinMode(led_yellow, OUTPUT);
  }

void loop(){
  sensors.requestTemperatures();
  lcd.setCursor(0, 1);
  lcd.print(sensors.getTempCByIndex(0));
  lcd.print((char)223) && lcd.print(F("C"));
  ;

  // LED indication controll
  if (sensors.getTempCByIndex(0) >= 28.0){
    digitalWrite(led_red, HIGH);
    digitalWrite(led_green, LOW);
    digitalWrite(led_yellow, LOW);
  }
  else if (sensors.getTempCByIndex(0) >= 24.5 && sensors.getTempCByIndex(0) < 28.0 ){
    digitalWrite(led_yellow, HIGH);
    digitalWrite(led_red, LOW);
    digitalWrite(led_green, LOW);
  }
  else if (sensors.getTempCByIndex(0) <= 24.5){
    digitalWrite(led_green, HIGH);
    digitalWrite(led_red, LOW);
    digitalWrite(led_yellow, LOW);
  }

}

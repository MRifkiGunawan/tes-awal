#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 32, 4);
#include "DHT.h"
#define DHTPIN 12     // DHT PIN 2
#define DHTTYPE DHT22   // DHT 22  (AM2302), AM2321
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  Serial.println("DHT 22 test!");
  dht.begin();
  lcd.begin();
}

void loop() {
  float h = dht.readHumidity();
  // Read temperature as Celsius (the default)
  float t = dht.readTemperature();
  
  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t) ) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }
  Serial.print("Temperature: ");
  Serial.print(t);
  Serial.print(" *C\t");
  Serial.print("Humidity: ");
  Serial.print(h);
  Serial.println(" %");
delay(1000);
lcd.setCursor(0,0);
  lcd.print("TEST LCD i2C");
  lcd.setCursor(0,1);
  lcd.print("KelasRobot.com");
}

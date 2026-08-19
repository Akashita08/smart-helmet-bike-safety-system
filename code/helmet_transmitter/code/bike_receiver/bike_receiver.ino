#include <Wire.h>
#include <LiquidCrystal_PCF8574.h>
#include <RH_ASK.h>
#include <SPI.h>

LiquidCrystal_PCF8574 lcd(0x27);
RH_ASK driver(2000, 11, 12);

int relay = 13;
int led = 9;

int lastState = -1;

void setup() {
  Wire.begin();
  driver.init();

  pinMode(relay, OUTPUT);
  pinMode(led, OUTPUT);

  Serial.begin(9600);

  lcd.begin(16, 2);
  lcd.setBacklight(255);

  lcd.setCursor(0, 0);
  lcd.print("System Ready");
  delay(2000);
  lcd.clear();
}

void loop() {
  uint8_t buf[10];
  uint8_t buflen = sizeof(buf);

  if (driver.recv(buf, &buflen)) {

    int currentState;

    if (buf[0] == '1') {
      currentState = 1;

      digitalWrite(relay, HIGH);
      digitalWrite(led, LOW);

      lcd.setCursor(0, 0);
      lcd.print("No Helmet   ");
      lcd.setCursor(0, 1);
      lcd.print("Ignition OFF   ");

    } else {
      currentState = 0;

      digitalWrite(relay, LOW);
      digitalWrite(led, HIGH);

      lcd.setCursor(0, 0);
      lcd.print("Helmet Worn     ");
      lcd.setCursor(0, 1);
      lcd.print("Ignition ON  ");
    }

    // print only when state changes
    if (currentState != lastState) {
      if (currentState == 1) {
        Serial.println("Helmet not worn");
      } else {
        Serial.println("Helmet worn");
      }
      lastState = currentState;
    }
  }
}

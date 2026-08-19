#include <RH_ASK.h>
#include <SPI.h>

RH_ASK driver;  
int ldr = A0;
int led = 13;
void setup() {
  Serial.begin(9600);
  driver.init();
  pinMode(led, OUTPUT);
  digitalWrite(13, HIGH);
}

void loop() {
  int value = analogRead(ldr);
  const char *msg;
  if (value < 800) {   
    msg = "1";
    digitalWrite(led, HIGH);  
  } else {
    msg = "0";
    digitalWrite(led, LOW);
  }

  driver.send((uint8_t *)msg, strlen(msg));
  driver.waitPacketSent();
  delay(200);
}

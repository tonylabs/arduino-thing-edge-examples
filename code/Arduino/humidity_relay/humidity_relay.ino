#include "SHT3X.h"

SHT3X objSHT30(0x44);

//@RELAY PINS
#define RELAY1_PIN 33
#define RELAY2_PIN 32

void setup()
{
  Serial.begin(115200);
  pinMode(RELAY1_PIN, OUTPUT);
  pinMode(RELAY2_PIN, OUTPUT);
}

void loop()
{
  if (objSHT30.get() == 0) {
    
    Serial.print("====== Relative Humidity : ");
    Serial.println(objSHT30.humidity);

    if (objSHT30.humidity >= 40) {
      digitalWrite(RELAY1_PIN, HIGH);
    } else {
      digitalWrite(RELAY1_PIN, LOW);
    }
  }
  delay(1000);
}

#include <Arduino.h>

void setup() {
    Serial.begin(115200);
    Serial.println("ESP32 Music Player initialized");
}

void loop() {
    Serial.println("ESP32 is working!");
    delay(1000);
}
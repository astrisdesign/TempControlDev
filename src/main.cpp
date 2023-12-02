#include <Arduino.h>

#define SSR_PIN 5  // Define the SSR control pin

void setup() {
  pinMode(SSR_PIN, OUTPUT);  // Initialize the SSR pin as an output
}

void loop() {
  digitalWrite(SSR_PIN, HIGH); // Turn the SSR on
  delay(1000);                // Wait for 1 second (1000 milliseconds)

  digitalWrite(SSR_PIN, LOW);  // Turn the SSR off
  delay(1000);                // Wait for 1 second
}
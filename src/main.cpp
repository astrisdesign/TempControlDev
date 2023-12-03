#include <Arduino.h>
#include <SPI.h>
#include <max6675.h>

// Hardware SPI pins
int thermoCS1 = A0;  // Chip Select pin for the first MAX6675
int thermoDO = MISO;
int thermoCLK = SCK;
// int thermoCS2 = A1;  // Chip Select pin for the second MAX6675 (if needed)

// Initialize the MAX6675 thermocouple amplifiers on the hardware SPI bus
MAX6675 thermocouple1(thermoCLK, thermoCS1, thermoDO);
// Adafruit_MAX6675 thermocouple2(SPI, thermoCS2);
// Add more thermocouple objects if you have more thermocouples

#define SSR_PIN 5  // Define the SSR control pin. Ensure this doesn't conflict with other pins

void setup() {
  pinMode(SSR_PIN, OUTPUT);  // Initialize the SSR pin as an output
  Serial.begin(9600);       // Start serial communication at 9600 baud rate

  Serial.println("MAX6675 test");
  // Wait for MAX chip to stabilize
  delay(500);
}

void loop() {
  // Toggle the SSR
  digitalWrite(SSR_PIN, HIGH); // Turn the SSR on
  delay(1000);                // Wait for 1 second
  digitalWrite(SSR_PIN, LOW);  // Turn the SSR off
  delay(1000);                // Wait for 1 second

  // Read temperature from the MAX6675s
  Serial.print("Thermocouple 1 - C = "); 
  Serial.println(thermocouple1.readCelsius());
  Serial.print("Thermocouple 1 - F = ");
  Serial.println(thermocouple1.readFahrenheit());

  // Serial.print("Thermocouple 2 - C = "); 
  // Serial.println(thermocouple2.readCelsius());
  // Serial.print("Thermocouple 2 - F = ");
  // Serial.println(thermocouple2.readFahrenheit());

  // ... Repeat for additional thermocouples

  // For the MAX6675 to update, you must delay AT LEAST 250ms between reads
  delay(500);
}

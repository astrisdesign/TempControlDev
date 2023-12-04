#include <Arduino.h>
#include <SPI.h>
#include <max6675.h>

// Hardware SPI pins
int thermoDO = MISO;
int thermoCLK = SCK;
int thermoCS1 = A0;  // Chip Select pin for the first MAX6675
int thermoCS2 = A1;
int thermoCS3 = A2;
int thermoCS4 = A3;

// Initialize the MAX6675 thermocouple amplifiers on the hardware SPI bus
MAX6675 thermocouple1(thermoCLK, thermoCS1, thermoDO);
MAX6675 thermocouple2(thermoCLK, thermoCS2, thermoDO);
MAX6675 thermocouple3(thermoCLK, thermoCS3, thermoDO);
MAX6675 thermocouple4(thermoCLK, thermoCS4, thermoDO);

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
  delay(10);                // Wait for .01 second
  digitalWrite(SSR_PIN, LOW);  // Turn the SSR off
  delay(10);                // Wait for .01 second

  // Read temperature from the MAX6675s
  Serial.print("Thermocouple 1 - F = ");
  Serial.println(thermocouple1.readFahrenheit());

  Serial.print("Thermocouple 2 - F = ");
  Serial.println(thermocouple2.readFahrenheit());

  Serial.print("Thermocouple 3 - F = ");
  Serial.println(thermocouple3.readFahrenheit());

  Serial.print("Thermocouple 4 - F = ");
  Serial.println(thermocouple4.readFahrenheit());

  Serial.println("");
  Serial.println("");

  // For the MAX6675 to update, you must delay AT LEAST 250ms between reads
  delay(250);
}

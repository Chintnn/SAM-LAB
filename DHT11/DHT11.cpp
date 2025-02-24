/*
void setup()
{
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop()
{
  digitalWrite(LED_BUILTIN, HIGH);
  delay(1000); // Wait for 1000 millisecond(s)
  digitalWrite(LED_BUILTIN, LOW);
  delay(1000); // Wait for 1000 millisecond(s)
}
*/

#include <DHT.h>

#define DHTTYPE DHT11 // DHT 11
#define dht_pin 2

DHT dht(dht_pin, DHTTYPE);

void setup() {
  dht.begin();
  Serial.begin(9600);
}

void loop() {
  float humidity = dht.readHumidity();
  float temp = dht.readTemperature();
  
  Serial.print("Current humidity in the room: ");
  Serial.print(humidity);
  Serial.println(" %");

  Serial.print("Current temperature in the room: ");
  Serial.print(temp);
  Serial.println(" °C");

  delay(1000);
}

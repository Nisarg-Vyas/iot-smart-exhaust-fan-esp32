#define BLYNK_TEMPLATE_ID "YOUR_TEMPLATE_ID"
#define BLYNK_TEMPLATE_NAME "YOUR_TEMPLATE_NAME"

#define BLYNK_PRINT Serial

#include <WiFi.h>
#include <BlynkSimpleEsp32.h>
#include "DHT.h"

const char auth[] = "YOUR_AUTH_CODE";
const char ssid[] = "YOUR_WIFI_NAME";
const char pass[] = "WIFI_PASSWORD";

#define DHTPIN 22
#define DHTTYPE DHT11

const int gasSensorPin = 34;        // MQ-135 gas sensor pin (analog pin)
const int motorPin1 = 23;
const int motorPin2 = 19;
const int enablePin = 18;

const int smokeThreshold = 200;     // Threshold for smoke (MQ-135) in ppm
const int co2Threshold = 400;       // Threshold for CO2 in ppm  ← was coThreshold/50
const int airQualityThreshold = 300;// Threshold for NH3/Benzene/Alcohol in ppm  ← was gasThreshold/500

DHT dht(DHTPIN, DHTTYPE);

bool manualMode = false;

void setup()
{
  Serial.begin(115200);
  dht.begin();
  Blynk.begin(auth, ssid, pass);

  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
  pinMode(enablePin, OUTPUT);
  pinMode(gasSensorPin, INPUT);

  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, LOW);
  analogWrite(enablePin, 0);

  delay(2000);
}

BLYNK_WRITE(V4)
{
  int relayControl = param.asInt();
  manualMode = (relayControl == 1);

  if (manualMode)
  {
    digitalWrite(motorPin1, HIGH);
    digitalWrite(motorPin2, LOW);
    analogWrite(enablePin, 255);
  }
  else
  {
    digitalWrite(motorPin1, LOW);
    digitalWrite(motorPin2, LOW);
    analogWrite(enablePin, 0);
  }
}

void loop()
{
  Blynk.run();

  int sensorValue = analogRead(gasSensorPin);
  int gasLevel = map(sensorValue, 0, 4095, 0, 1000);

  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();

  if (isnan(humidity) || isnan(temperature))
  {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }

  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.println("%");

  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println("°C ");

  Serial.print("Air Quality Level (ppm): ");
  Serial.println(gasLevel);

  Serial.println();

  Blynk.virtualWrite(V0, gasLevel);
  Blynk.virtualWrite(V1, temperature);
  Blynk.virtualWrite(V2, humidity);

  if (!manualMode)
  {
    if (humidity > 60)
    {
      digitalWrite(motorPin1, HIGH);
      digitalWrite(motorPin2, LOW);
      analogWrite(enablePin, 255);
      Blynk.virtualWrite(V3, HIGH);
    }
    else if (gasLevel > smokeThreshold)
    {
      digitalWrite(motorPin1, HIGH);
      digitalWrite(motorPin2, LOW);
      analogWrite(enablePin, 255);
      Blynk.virtualWrite(V3, HIGH);
    }
    else if (gasLevel > airQualityThreshold)
    {
      digitalWrite(motorPin1, HIGH);
      digitalWrite(motorPin2, LOW);
      analogWrite(enablePin, 255);
      Blynk.virtualWrite(V3, HIGH);
    }
    else if (gasLevel > co2Threshold)
    {
      digitalWrite(motorPin1, HIGH);
      digitalWrite(motorPin2, LOW);
      analogWrite(enablePin, 255);
      Blynk.virtualWrite(V3, HIGH);
    }
    else
    {
      digitalWrite(motorPin1, LOW);
      digitalWrite(motorPin2, LOW);
      analogWrite(enablePin, 0);
      Blynk.virtualWrite(V3, LOW);
    }
  }

  delay(1000);
}
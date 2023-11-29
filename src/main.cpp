#include <Wire.h>
#include <Adafruit_SSD1306.h>
#include <DHT.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1
#define SSD1306_I2C_ADDRESS 0x78
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

#define DHTPIN 7      // Pin where the DHT11 is connected
#define DHTTYPE DHT11 // Type of DHT sensor

DHT dht(DHTPIN, DHTTYPE);

void serialPrintTemperatureAndHumidity(float temperature, float humidity)
{
  Serial.print(F("VALUE: "));

  // Print humidity
  Serial.print(F("Humidity: "));
  Serial.print(humidity);
  Serial.print(F("%"));

  Serial.print('\t');

  // Print temperature
  Serial.print(F("Temperature: "));
  Serial.print(temperature);
  Serial.println(F("°C"));
}

void setup()
{
  Serial.begin(9600);
  
  Serial.println(F("Build version 0.1"));

  if (!display.begin(SSD1306_I2C_ADDRESS, OLED_RESET))
  {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;)
      ;
  }

  // Clear the display buffer
  display.display(); 
  display.clearDisplay();
}

void loop()
{

  delay(2000); // Wait for 2 seconds between readings

  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();

  if (isnan(humidity) || isnan(temperature))
  {
    Serial.println(F("ERROR: Failed to read from DHT sensor!"));
    return;
  }

  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.print(F("Humidity: "));
  display.print(humidity);
  display.print(F("%"));

  display.setCursor(0, 20);
  display.print(F("Temperature: "));
  display.print(temperature);
  display.print(F("°C"));

  display.display();
  serialPrintTemperatureAndHumidity(temperature, humidity);
}

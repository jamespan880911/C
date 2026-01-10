#include <OneWire.h>
#include <DallasTemperature.h>


#define ONE_WIRE_BUS 2
#define RELAY_COOLER 7
#define RELAY_FAN 8


const float TEMP_HIGH = 20.0;
const float TEMP_LOW = 16.0;
const unsigned long FAN_DELAY = 120000;


OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

bool coolerOn = false;
bool fanDelayStarted = false;
unsigned long fanOffTime = 0;

void setup() {
  Serial.begin(9600);
  sensors.begin();

  pinMode(RELAY_COOLER, OUTPUT);
  pinMode(RELAY_FAN, OUTPUT);

  digitalWrite(RELAY_COOLER, LOW);
  digitalWrite(RELAY_FAN, LOW);

  Serial.println("Smart Aquarium Temperature Control System Started.");
}

void loop() {
  sensors.requestTemperatures();
  float temp = sensors.getTempCByIndex(0);

  Serial.print("Current Water Temp: ");
  Serial.print(temp);
  Serial.println(" °C");

  // 溫度高於閾值：啟動TEC與風扇
  if (temp > TEMP_HIGH) {
    digitalWrite(RELAY_COOLER, HIGH);
    digitalWrite(RELAY_FAN, HIGH);
    coolerOn = true;
    fanDelayStarted = false; // 重置風扇延遲
  }

  // 溫度低於閾值且目前製冷晶片正在運作：關閉TEC，開始風扇delay
  else if (temp < TEMP_LOW && coolerOn) {
    digitalWrite(RELAY_COOLER, LOW);
    fanOffTime = millis() + FAN_DELAY;
    fanDelayStarted = true;
    coolerOn = false;
  }

  // 延遲風扇關閉邏輯
  if (fanDelayStarted && millis() >= fanOffTime) {
    digitalWrite(RELAY_FAN, LOW);
    fanDelayStarted = false;
  }

  delay(2000); // 每2秒更新一次
}
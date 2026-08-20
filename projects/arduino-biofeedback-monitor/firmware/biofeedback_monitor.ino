#include <LiquidCrystal.h>

const int GSR_PIN = A0;
const int TMP36_PIN = A1;
const int BUTTON_PIN = 7;
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
const unsigned long CALIBRATION_MS = 20000;
const unsigned long RESPONSE_MS = 6000;
float baselineGsr = 0.0;

float readTemperatureF() {
  int raw = analogRead(TMP36_PIN);
  float voltage = raw * (5.0 / 1023.0);
  float celsius = (voltage - 0.5) * 100.0;
  return celsius * 9.0 / 5.0 + 32.0;
}

float calibrateGsr() {
  unsigned long start = millis();
  unsigned long samples = 0;
  unsigned long sum = 0;
  lcd.clear();
  lcd.print("Calibrating...");
  while (millis() - start < CALIBRATION_MS) {
    sum += analogRead(GSR_PIN);
    samples++;
    delay(20);
  }
  return samples ? (float)sum / samples : 0.0;
}

void waitForButton() {
  lcd.clear();
  lcd.print("Press button");
  while (digitalRead(BUTTON_PIN) == HIGH) delay(10);
  delay(40);
  while (digitalRead(BUTTON_PIN) == LOW) delay(10);
}

void measureWindow() {
  lcd.clear();
  lcd.print("Measuring...");
  unsigned long start = millis();
  int maxDelta = 0;
  while (millis() - start < RESPONSE_MS) {
    int gsr = analogRead(GSR_PIN);
    int delta = abs(gsr - (int)baselineGsr);
    if (delta > maxDelta) maxDelta = delta;
    Serial.print("GSR:"); Serial.print(gsr);
    Serial.print(",Baseline:"); Serial.print(baselineGsr, 1);
    Serial.print(",TempF:"); Serial.println(readTemperatureF(), 1);
    delay(25);
  }
  lcd.clear();
  lcd.print("dGSR:"); lcd.print(maxDelta);
  lcd.setCursor(0, 1);
  lcd.print("T:"); lcd.print(readTemperatureF(), 1); lcd.print("F");
  delay(4000);
}

void setup() {
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.print("Biofeedback");
  delay(1000);
  baselineGsr = calibrateGsr();
}

void loop() {
  waitForButton();
  measureWindow();
}

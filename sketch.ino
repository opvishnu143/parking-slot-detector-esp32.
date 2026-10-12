#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

const int SENSOR1_PIN = 23;   // Button 1 = Slot A1
const int SENSOR2_PIN = 16;   // Button 2 = Slot A2
const int LED1 = 25;
const int LED2 = 26;
const int BUZZER = 21;

void setup() {
  Wire.begin(19, 22);   // SDA = 19, SCL = 22
  Serial.begin(115200);
  pinMode(SENSOR1_PIN, INPUT_PULLUP);
  pinMode(SENSOR2_PIN, INPUT_PULLUP);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(BUZZER, OUTPUT);
  lcd.init();
  lcd.backlight();
}

void loop() {
  bool occ1 = (digitalRead(SENSOR1_PIN) == LOW);
  bool occ2 = (digitalRead(SENSOR2_PIN) == LOW);

  digitalWrite(LED1, occ1 ? HIGH : LOW);
  digitalWrite(LED2, occ2 ? HIGH : LOW);
  digitalWrite(BUZZER, (occ1 && occ2) ? HIGH : LOW);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("A1:");
  lcd.print(occ1 ? "OCC " : "FREE");
  lcd.print(" A2:");
  lcd.print(occ2 ? "OCC" : "FREE");
  if (occ1 && occ2) {
    lcd.setCursor(0, 1);
    lcd.print("PARKING FULL!");
  }

  Serial.print("S1: "); Serial.print(occ1 ? "OCC " : "FREE ");
  Serial.print("S2: "); Serial.println(occ2 ? "OCC" : "FREE");

  delay(500);
}
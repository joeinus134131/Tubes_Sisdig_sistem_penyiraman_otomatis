/*
 * Kelompok Bori Tech
 * Create by : Made agus andi gunawan
 */
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

int sensorPin = A0;
int nilai;
const int relay = 7;

void setup() 
{
  pinMode(sensorPin, INPUT);
  pinMode(relay, OUTPUT);
  lcd.begin();
  lcd.setCursor(4, 0);
  lcd.print("kelompok");
  lcd.setCursor(4, 1);
  lcd.print("BORI TECH");
  delay(1000);
  lcd.clear();
}

void loop() 
{
  int nilai = analogRead(sensorPin);
  lcd.setCursor(0 ,0);
  lcd.print("Kelembaban = ");
  lcd.print(nilai);
  
  if(nilai < 700)
  {
    lcd.setCursor(0, 1);
    lcd.print("Tanah Basah");
    digitalWrite(relay, LOW);
    delay(1000);
    lcd.clear();
    lcd.setCursor(0 ,0);
    lcd.print("Kelembaban = ");
    lcd.print(nilai);
    lcd.setCursor(0, 1);
    lcd.print("Jangan Disiram..!");
  }
  else if(nilai < 700 && nilai > 350)
  {
    lcd.setCursor(0 ,0);
    lcd.print("normal");
    digitalWrite(relay, LOW);
    delay(1000);
    lcd.clear();
    lcd.setCursor(0 ,0);
    lcd.print("Kelembaban = ");
    lcd.print(nilai);
    lcd.setCursor(0, 1);
    lcd.print("Santuyy");
  }
  else
  {
    lcd.setCursor(0, 1);
    lcd.print("Tanah kering");
    digitalWrite(relay, HIGH);
    delay(1000);
    lcd.clear();
    lcd.setCursor(0 ,0);
    lcd.print("Kelembaban = ");
    lcd.print(nilai);
    lcd.setCursor(0, 1);
    lcd.print("Siram Oyy...!");
  }
  delay(500);
}

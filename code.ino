#include <LiquidCrystal.h>
#include <dht.h>
#include <Wire.h>
#include <RTClib.h>

// Pinos do LCD
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);

// Sensor DHT22
#define DHTPIN 9
#define DHTTYPE DHT22
dht my_dht;

// RTC DS1307
RTC_DS1307 rtc;

// Pinos dos LEDs e Buzzer
int redPin = 13;
int yellowPin = 12;
int greenPin = 11;
int buzzPin = 10;
bool emAlerta = false;
float temperatura = 0;

byte cima4[8] = { B11100, B11110, B00110, B00000, B00000, B00000, B00000, B11110 };
byte cima1[8] = { B00111, B01111, B01100, B11000, B11000, B11000, B11000, B11000 };
byte cima2[8] = { B11100, B11110, B00110, B00011, B00011, B00011, B00011, B00011 };
byte cima3[8] = { B00111, B01111, B01100, B01100, B01100, B01100, B01100, B01101 };
byte baixo1[8] = { B11000, B11000, B11000, B11000, B11000, B01100, B01111, B00111 };
byte baixo2[8] = { B00011, B00011, B00011, B00011, B00011, B00110, B11110, B11100 };
byte baixo3[8] = { B01101, B01101, B01100, B01100, B01100, B01100, B01111, B00111 };
byte baixo4[8] = { B11110, B10110, B00110, B00110, B00110, B00110, B11110, B11100 };

void aparecerLogo() {
  lcd.createChar(1, cima1);
  lcd.setCursor(6, 0);
  lcd.write(byte(1));
  lcd.createChar(2, cima2);
  lcd.setCursor(7, 0);
  lcd.write(byte(2));
  lcd.createChar(3, cima3);
  lcd.setCursor(8, 0);
  lcd.write(byte(3));
  lcd.createChar(4, cima4);
  lcd.setCursor(9, 0);
  lcd.write(byte(4));
  lcd.createChar(5, baixo1);
  lcd.setCursor(6, 1);
  lcd.write(byte(5));
  lcd.createChar(6, baixo2);
  lcd.setCursor(7, 1);
  lcd.write(byte(6));
  lcd.createChar(7, baixo3);
  lcd.setCursor(8, 1);
  lcd.write(byte(7));
  lcd.createChar(0, baixo4);
  lcd.setCursor(9, 1);
  lcd.write(byte(0)); 
  delay(4000);
  lcd.clear();
  lcd.setCursor(3,0);
  lcd.print("Oceans");
  lcd.setCursor(4,1);
  lcd.print("Guard");
  delay(2000);
  lcd.clear();
}

void setup() {
  lcd.begin(16, 2);
  aparecerLogo();
  pinMode(redPin, OUTPUT);
  pinMode(yellowPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(buzzPin, OUTPUT);
  Serial.begin(9600);

  // Inicia o RTC
  if (!rtc.begin()) {
    Serial.println("RTC não encontrado!");
    while (1);
  }

  if (!rtc.isrunning()) {
    Serial.println("RTC não está funcionando, ajustando a hora...");
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  }
}

void loop() {
  float mediaTemp = 0;

  for(int i = 0; i < 10; i++) {
    my_dht.read22(DHTPIN);
    temperatura = my_dht.temperature;
    mediaTemp += temperatura;
    delay(500);
  }

  temperatura = mediaTemp / 10;

  DateTime now = rtc.now();

  Serial.print("Data/Hora: ");
  Serial.print(now.year(), DEC);
  Serial.print('/');
  Serial.print(now.month(), DEC);
  Serial.print('/');
  Serial.print(now.day(), DEC);
  Serial.print(" ");
  Serial.print(now.hour(), DEC);
  Serial.print(':');
  Serial.print(now.minute(), DEC);
  Serial.print(':');
  Serial.print(now.second(), DEC);
  Serial.print(" | Temperatura: ");
 Serial.print(temperatura);
Serial.println("°C");

// Exibe a hora e a temperatura no LCD
lcd.setCursor(0, 0);
lcd.print("Hora: ");
lcd.print(now.hour());
lcd.print(':');
if (now.minute() < 10) lcd.print('0');
lcd.print(now.minute());
lcd.print(':');
if (now.second() < 10) lcd.print('0');
lcd.print(now.second());

delay(3000);
lcd.clear();

lcd.setCursor(0, 1);
lcd.print("Temp: ");
lcd.print(temperatura);
lcd.print((char)223); // Símbolo de grau
lcd.print("C");

if (temperatura > 30) {
  digitalWrite(buzzPin, HIGH);
  digitalWrite(redPin, HIGH);
  digitalWrite(yellowPin, LOW);
  digitalWrite(greenPin, LOW);
  emAlerta = true;
  tone(buzzPin, 700, 1000);

  lcd.clear();
  lcd.print("Temp Alta!");
  lcd.setCursor(0,1);
  lcd.print(temperatura);
  lcd.print("C");
} else if (temperatura >= 20 && temperatura <= 30) {
  digitalWrite(buzzPin, LOW);
  digitalWrite(redPin, LOW);
  digitalWrite(yellowPin, LOW);
  digitalWrite(greenPin, HIGH);

  lcd.clear();
  lcd.print("Temp OK");
  lcd.setCursor(0,1);
  lcd.print(temperatura);
  lcd.print("C");
} else {
  digitalWrite(buzzPin, HIGH);
  digitalWrite(redPin, LOW);
  digitalWrite(yellowPin, HIGH);
  digitalWrite(greenPin, LOW);
  emAlerta = true;
  tone(buzzPin, 1000, 700);

  lcd.clear();
  lcd.print("Temp Baixa! ");
  lcd.setCursor(0,1);
  lcd.print(temperatura);
  lcd.print("C");
}

delay(1000);
}

#include <WiFi.h>
#include "ThingSpeak.h"
#include <DHT.h>
#include <LiquidCrystal_I2C.h>

// ---------------- WIFI + THINGSPEAK ----------------
#define WIFI_SSID "SRC 24G"
#define WIFI_PASS "src@internet"
#define CHANNEL_ID 3246077
#define WRITE_API_KEY "LO48BQV5VX5YBMUB"

WiFiClient client;

// ---------------- LCD ----------------
LiquidCrystal_I2C lcd(0x27, 16, 2);

// ---------------- DHT ----------------
#define DHTTYPE DHT11
DHT dht1(4, DHTTYPE);
DHT dht2(5, DHTTYPE);

// ---------------- SET 1 ----------------
#define GAS1_S1 34
#define GAS2_S1 35
#define LDR_S1  25
#define FAN1    17
#define BUZ1    19

// ---------------- SET 2 ----------------
#define GAS1_S2 32
#define GAS2_S2 33
#define LDR_S2  26
#define FAN2    16
#define BUZ2    18
#define vs    27
// Thresholds
#define GAS1_LIMIT 100
#define GAS2_LIMIT 120
#define GAS3_LIMIT 100
#define GAS4_LIMIT 120
#define TEMP1_LIMIT 30
#define TEMP2_LIMIT 28
int prt=30;
int prh=55;
int prt2=30;
int prh2=55;
#define h1_LIMIT 65
#define h2_LIMIT 75
unsigned long lastTS = 0;

void setup() {
  Serial.begin(115200);

  pinMode(FAN1, OUTPUT);
  pinMode(FAN2, OUTPUT);
  pinMode(BUZ1, OUTPUT);
  pinMode(BUZ2, OUTPUT);
  digitalWrite(BUZ1,1);
  
digitalWrite(BUZ2,1);

 digitalWrite(FAN1,0);
  
digitalWrite(FAN2,0);
  lcd.init();
  lcd.backlight();

  dht1.begin();
  dht2.begin();

  WiFi.begin(WIFI_SSID, WIFI_PASS);
  lcd.setCursor(0, 0);
  lcd.print("Connecting WiFi");

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    lcd.print(".");
  }


  pinMode(LDR_S2,INPUT);
  pinMode(LDR_S1,INPUT);
  lcd.clear();
  lcd.print("WiFi Connected");

  ThingSpeak.begin(client);
  delay(2000);
}

void loop() {

  // -------- READ SET 1 --------
  int gas1_s1 = (analogRead(GAS1_S1)*1.2)/5;
  int gas2_s1 = analogRead(GAS2_S1)/5;
  int ldr_s1  = digitalRead(LDR_S1);
  int vval  = analogRead(vs)/100;
  int temp1 = dht1.readTemperature();
  int hmd1 = dht1.readHumidity();
  if(temp1>200)
  {
  temp1=prt;
  hmd1=prh;
  }
  else
  {
  prt=temp1;
  prh=hmd1;
  }
  // -------- READ SET 2 --------
  int gas1_s2 = analogRead(GAS1_S2)/5;
  int gas2_s2 = (analogRead(GAS2_S2)*1.9)/5;
  int ldr_s2  = digitalRead(LDR_S2);
  int temp2 = dht2.readTemperature();
  int hmd2 = dht2.readHumidity();


 if(temp2>200)
  {
  temp2=prt2;
  hmd2=prh2;
  }
  else
  {
  prt2=temp2;
  prh2=hmd2;
  }
  // -------- CONTROL FAN & BUZZER --------
  digitalWrite(FAN1, (temp1 > TEMP1_LIMIT || gas1_s1 > GAS1_LIMIT || gas2_s1 > GAS2_LIMIT || hmd1 > h1_LIMIT ) ? HIGH : LOW);
  digitalWrite(BUZ1, (temp1 > TEMP1_LIMIT || gas1_s1 > GAS1_LIMIT || gas2_s1 > GAS2_LIMIT || hmd1 > h1_LIMIT ) ? LOW : HIGH);

  digitalWrite(FAN2, (temp2 > TEMP2_LIMIT || gas1_s2 > GAS3_LIMIT || gas2_s2 > GAS4_LIMIT || hmd2 > h2_LIMIT ) ? HIGH : LOW);
  digitalWrite(BUZ2, (temp2 > TEMP2_LIMIT || gas1_s2 > GAS3_LIMIT || gas2_s2 > GAS4_LIMIT || hmd2 > h2_LIMIT ) ? LOW : HIGH);

  // -------- LCD SET 1 (3 sec) --------
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("1-ON C:");
  lcd.print(gas1_s1);
  lcd.print(" M:");
  lcd.print(gas2_s1);

  lcd.setCursor(0, 1);
  lcd.print("T:");
  lcd.print(temp1);
     lcd.print(" H:");
  lcd.print(hmd1);
  lcd.print(" L:");
  lcd.print(ldr_s1);

  lcd.print(" ");
  lcd.print(vval);

  delay(3000);
 
  
  if(temp1>TEMP1_LIMIT)
  {
     lcd.clear();
    lcd.print("1 - TEMP ALERT");
    delay(1000);
  }

  
  if(hmd1>h1_LIMIT)
  {
     lcd.clear();
    lcd.print("1 - HUMD ALERT");
    delay(1000);
  }

   if(gas1_s1 > GAS1_LIMIT)
  {
     lcd.clear();
    lcd.print("1 - CO ALERT");
    delay(1000);
  }
   if(gas2_s1 > GAS2_LIMIT)
  {
     lcd.clear();
    lcd.print("1 - CH4 ALERT");
    delay(1000);
  }


  // -------- LCD SET 2 (3 sec) --------
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("2-PT C:");
  lcd.print(gas1_s2);
  lcd.print(" M:");
  lcd.print(gas2_s2);

  lcd.setCursor(0, 1);
  lcd.print("T:");
  lcd.print(temp2);
   lcd.print(" H:");
  lcd.print(hmd2);
  
  lcd.print(" L:");
  lcd.print(ldr_s2);
  lcd.print(" ");
  lcd.print(vval);

  delay(3000);


  if(temp2>TEMP2_LIMIT)
  {
     lcd.clear();
    lcd.print("2 - TEMP ALERT");
    delay(1000);
  }

  
  if(hmd2>h2_LIMIT)
  {
     lcd.clear();
    lcd.print("2 - HUMD ALERT");
    delay(1000);
  }

   if(gas1_s2 > GAS3_LIMIT)
  {
     lcd.clear();
    lcd.print("2 - CO ALERT");
    delay(1000);
  }
   if(gas2_s2 > GAS4_LIMIT)
  {
     lcd.clear();
    lcd.print("2 - CH4 ALERT");
    delay(1000);
  }


  // -------- THINGSPEAK UPDATE (15s min) --------
  if (millis() - lastTS > 16000) {

    ThingSpeak.setField(1, temp1);
    ThingSpeak.setField(2, hmd1);
    ThingSpeak.setField(3, gas1_s1);
    ThingSpeak.setField(4, gas2_s1);
    ThingSpeak.setField(5, temp2);
    ThingSpeak.setField(6, hmd2);
    ThingSpeak.setField(7, gas1_s2);
    ThingSpeak.setField(8, gas2_s2);

    ThingSpeak.writeFields(CHANNEL_ID, WRITE_API_KEY);
    lastTS = millis();
  }
}
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
//LCD
LiquidCrystal_I2C lcd(0x27,16,2);
//define pin LED
#define sensor A0
#define led_red 13
#define led_yellow 12

//deklarasi variabel
float RS_air;
int RL = 200000; //200kOhm
float R0 = 314.56;
float b = -0.2978;
float m = -0.64;
float RS;
float ratio;
float ppminlog;
float ppm;
float mgL;
float BAC;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("Aphol");
  lcd.setCursor(0,1);
  lcd.print("Sabrina13218014");
  delay(2000);
  pinMode(sensor,INPUT);
  pinMode(led_red,OUTPUT);
  pinMode(led_yellow,OUTPUT);
  lcd.clear();
}

void loop() {
  // put your main code here, to run repeatedly:
  float sensor_volt;
  int sensorValue = analogRead(sensor);
  sensor_volt = (float)sensorValue/1024*5.0;
  //kode untuk mencari nilai R0
  //RS_air = ((5.0*RL)/sensor_volt) - RL;
  //R0 = RS_air / 60;
  //Serial.print("R0 = ");
  //Serial.println(R0);
  //delay(1000);
/*
 * mencari gradien alkohol dari datasheet
 * y = mx+b
 * y = nilai Rs/R0
 * x = mg/L
 * m = slope
 * b = y di titik perpotongan
 * log(y) = m*log(x) + b
 * m =[log(y)-log(y0)]/[log(x)-log(x0)]
 * m = log(y/y0) / log(x/x0)
 * m = log(0.12/2.3) / log(10/0.1)
 * m = -0.64
 * b = log(y)-m*log(x)
 * b = log(0.16) - (-0.64)*log(6)
 * b = -0.2978
 */
  RS = (5.0-sensor_volt)/sensor_volt; // RS dalam udara
  ratio = RS/R0; //rasio RS/R0
  ppminlog = ((log(ratio)/log(10))-b)/m; 
  ppm = pow(10,ppminlog);
  mgL = ppm*0.00188;
  BAC = (mgL*210)/1000;
  Serial.print("tegangan sensor = ");
  Serial.print(sensor_volt);
  Serial.println(" V");
  Serial.print("ppm = ");
  Serial.println(ppm); //kadar alkohol dalam ppm di serial monitor
  Serial.print("mg/L = ");
  Serial.print(mgL); //kadar alkohol dalam mg/L di serial monitor
  Serial.println("mg/L");
  Serial.print("BAC = ");
  Serial.println(BAC); //kadar alkohol dalam mg% di serial monitor
  lcd.setCursor(0,0);
  lcd.print("BrAC: ");
  lcd.print(mgL); //kadar alkohol dalam mg/L di LCD
  lcd.print("mg/L ");
  lcd.setCursor(0,1);
  lcd.print(sensor_volt); //tegangan output sensor
  lcd.print(" V");

  if((mgL >= 0.8) && (mgL < 1.8)){ 
    digitalWrite(led_yellow, HIGH); //led kuning nyala
    digitalWrite(led_red, LOW); //led merah mati
  }
  if(mgL >= 1.8){ 
    digitalWrite(led_yellow, LOW); //led kuning mati
    digitalWrite(led_red, HIGH); //led merah nyala
  }
  else{
    digitalWrite(led_yellow, LOW);
    digitalWrite(led_red, LOW);
  }
  
  delay(1000);
}

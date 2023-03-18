//dht_nextion

#include "DHT.h"
#define DHTPIN 2
#define DHTTYPE DHT11
int heat = 14;
int outside = 15;
int Vo;
int Va;
float R1 = 10000;
float logR2, R2, H, T;
float c1 = 1.009249522e-03, c2 = 2.378405444e-04, c3 = 2.019202697e-07;
float temp = 0.0f;
//initialise it with a float literal constant,0,0f, rather than a int (0)
float humi = 0.0f;

DHT dht(DHTPIN, DHTTYPE);
void setup() {
  Serial.begin(9600);
  dht.begin();
  pinMode(heat, INPUT);
  pinMode(outside, INPUT);
}

void loop() {
  humi = dht.readHumidity();
  temp = dht.readTemperature(true);

  delay(1000);
  String command = "humi.txt=\"" + String(humi, 1) + "\"";
  //Escape sequence \ used to represent double quote " special characters

  Serial.print(command);
  Serial.write(0xff);
  Serial.write(0xff);
  Serial.write(0xff);
  

  String command2 = "temp.txt=\"" + String(temp, 1) + "\"";
  //as temperature is float variable we use 1 decimal place in String
  Serial.print(command2);
  Serial.write(0xff);
  Serial.write(0xff);
  Serial.write(0xff);

  Vo = analogRead(heat);
  R2 = R1 * (1023.0 / (float)Vo - 1.0);
  logR2 = log(R2);
  H = (1.0 / (c1 + c2 * logR2 + c3 * logR2 * logR2 * logR2));
  H = H - 273.15;
  H = (H * 9.0) / 5.0 + 34.10;//34.10 is the cal number to change

  String command3 = "heat.txt=\"" + String(H, 1) + "\"";
  Serial.print(command3);
  Serial.write(0xff);
  Serial.write(0xff);
  Serial.write(0xff);

  Va = analogRead(outside);
  R2 = R1 * (1023.0 / (float)Va - 1.0);
  logR2 = log(R2);
  T = (1.0 / (c1 + c2 * logR2 + c3 * logR2 * logR2 * logR2));
  T = T - 273.15;
  T = (T * 9.0) / 5.0 + 35.10;//35.10 is the cal number to change

  String command4 = "outside.txt=\"" + String(T, 1) + "\"";
  Serial.print(command4);
  Serial.write(0xff);
  Serial.write(0xff);
  Serial.write(0xff);
}

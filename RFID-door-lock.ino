#include <MFRC522.h>
#include <SPI.h>
//#include <Servo.h>

#define SS_PIN 10
#define RST_PIN 9

#ifdef COMMON_ANODE
#define LED_ON LOW
#define LED_OFF HIGH
#else
#define LED_ON HIGH
#define LED_OFF LOW
#endif
#define Relay 4
#define redLed 2
#define greenLed 3
#define blueLed 5

 
MFRC522 rfid(SS_PIN, RST_PIN); // Instance of the class

MFRC522::MIFARE_Key key;

int card1[] = {39,139,22,163}; //This is the stored UID
int card2[] = {67,161,011,169}; //This is the stored UID
int codeRead = 0;
//int Buzzer = 6;
int activate =0;
//Servo myservo;
String uidString;


void setup() {
 
 Serial.begin(9600);
 SPI.begin(); // Init SPI bus
 rfid.PCD_Init(); // Init MFRC522 
 //myservo.attach(5); //attach the servo to pin 5
 pinMode(Relay, OUTPUT);
// pinMode(Buzzer,OUTPUT);
 pinMode(redLed, OUTPUT);
 pinMode(greenLed, OUTPUT);
 pinMode(blueLed, OUTPUT); 
 //myservo.write(0); // 0 degree angle for servo
 digitalWrite(redLed, LED_OFF);  // Make sure led is off
 digitalWrite(greenLed, LED_OFF);  // Make sure led is off
 digitalWrite(blueLed, LED_OFF); // Make sure led is off



}

void loop() {
 if( rfid.PICC_IsNewCardPresent())
 {
 readRFID();
 }
 delay(100);

}

void readRFID()
{
 
 rfid.PICC_ReadCardSerial();
 Serial.print(F("\nPICC type: "));
 MFRC522::PICC_Type piccType = rfid.PICC_GetType(rfid.uid.sak);
 Serial.println(rfid.PICC_GetTypeName(piccType));

// Check is the PICC of Classic MIFARE type
 if (piccType != MFRC522::PICC_TYPE_MIFARE_MINI && 
 piccType != MFRC522::PICC_TYPE_MIFARE_1K &&
 piccType != MFRC522::PICC_TYPE_MIFARE_4K) {
 Serial.println(F("Your tag is not of type MIFARE Classic."));
 return;
 }


 Serial.println("Scanned PICC's UID:");
 printDec(rfid.uid.uidByte, rfid.uid.size);

uidString = String(rfid.uid.uidByte[0])+" "+String(rfid.uid.uidByte[1])+" "+String(rfid.uid.uidByte[2])+ " "+String(rfid.uid.uidByte[3]);



 int i = 0;
 boolean match = true;
 while(i<rfid.uid.size)
 {
 if(!(rfid.uid.uidByte[i] == card1[i])||!(rfid.uid.uidByte[i] == card2[i]))
  {
 match = false;
 }
 i++;
 }

if(match)
 { if (activate==0){
 //myservo.write(90); // 90 degree angle for servo (Door will open)
 digitalWrite(Relay, HIGH);
 digitalWrite(redLed, LOW);
 digitalWrite(greenLed, HIGH);
 digitalWrite(blueLed, LOW);
 Serial.println("\nDoor is open");
 //delay(100);
 activate = activate+1;
 }
 else
 { 
  //digitalWrite(Relay, LOW); 
   digitalWrite(redLed, HIGH);
   digitalWrite(greenLed, LOW);
   digitalWrite(blueLed, LOW);
   //delay(5000);
 
 //myservo.write(0); // 0 degree angle for servo (Door will close)
 activate = 0;
 Serial.println("\nDoor is close");
 digitalWrite(Relay, LOW);
 delay(5000);
 digitalWrite(redLed, LOW);
 digitalWrite(greenLed, LOW);
 digitalWrite(blueLed, LOW);
 }
 }
 
 else
 {
 //tone(6,400,1000);
 Serial.println("\nUnknown Card");
 digitalWrite(redLed, LOW);  // Make sure led is off
 digitalWrite(greenLed, LOW);  // Make sure led is off
 digitalWrite(blueLed, HIGH); // Make sure led is off
 delay(2000);
 digitalWrite(blueLed, LOW);
 
 }


 // Halt PICC
 rfid.PICC_HaltA();

// Stop encryption on PCD
 rfid.PCD_StopCrypto1();
}

void printDec(byte *buffer, byte bufferSize) {
 for (byte i = 0; i < bufferSize; i++) {
 Serial.print(buffer[i] < 0x10 ? " 0" : " ");
 Serial.print(buffer[i], DEC);
 }
}

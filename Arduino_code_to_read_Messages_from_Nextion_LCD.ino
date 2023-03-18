// Arduino code to read Messages from Nextion LCD

#include <SoftwareSerial.h>  // Software Serial Port (included in Arduino IDE "no download")
#include <Nextion.h>  // Nextion Library by Bentley Born https://github.com/bborncr/nextion

SoftwareSerial nextion(10, 11);// Nextion TX to pin 10 and RX to pin 11 of Arduino

Nextion NextionLCD(nextion, 9600); // Setup of Nextion library with name NextionLCD at 9600bps

void setup() {
  Serial.begin(9600);
  NextionLCD.init();
}

void loop() {
  String message = NextionLCD.listen(); // if a message is received from the Nextion LCD
  if(message != ""){ // if the message is not empty
    Serial.println(message); // Display the message on the Serial monitor
  } 
}

5 www.handsontec.com
Upload the sketch "4 Channel Relay Demo " to the Arduino Uno or ATMega2560 board. Then you can see
the LED cycle between on and off.
The actual figure is shown below:
Arduino Sketch: 4 Channel Relay Demo
/************************************************
Name：4 channel_relay
Description: control the 4 channel relay module to ON or OFF
Website: www.handsontec.com
Email: techsupport@handsontec.com
*****************************************************/
//the relays connect to
int RelayControl1 = 4; // Digital Arduino Pin used to control the motor
int RelayControl2 = 5;
int RelayControl3 = 6;
int RelayControl4 = 7;
void setup()
{
Serial.begin(9600);
pinMode(RelayControl1, OUTPUT);
pinMode(RelayControl2, OUTPUT);
pinMode(RelayControl3, OUTPUT);
pinMode(RelayControl4, OUTPUT);
}
void loop()
{
digitalWrite(RelayControl1,HIGH);// NO1 and COM1 Connected (LED on)
delay(1000);
digitalWrite(RelayControl1,LOW);// NO1 and COM1 disconnected (LED off)
delay(1000);
digitalWrite(RelayControl2,HIGH);
delay(1000);
digitalWrite(RelayControl2,LOW);
delay(1000);
digitalWrite(RelayControl3,HIGH);
delay(1000);
digitalWrite(RelayControl3,LOW);
delay(1000);
digitalWrite(RelayControl4,HIGH);
delay(1000);
digitalWrite(RelayControl4,LOW);
delay(1000);
}

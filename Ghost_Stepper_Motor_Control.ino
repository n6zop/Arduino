/*     Simple Stepper Motor Control Exaple Code
 *      
 *  by Dejan Nedelkovski, www.HowToMechatronics.com
 *  
 */

// defines pins numbers
const int stepPin = 3; 
const int dirPin = 4;
const int stepPin2 = 8; 
const int dirPin2 = 9;
const int MS1 = 5;
const int MS2 = 6;
const int MS3 = 7;
const int MS12 = 10;
const int MS22 = 11;
const int MS32 = 12; 
 
void setup() {
  // Sets the two pins as Outputs
  pinMode(stepPin,OUTPUT); 
  pinMode(dirPin,OUTPUT);
  pinMode(MS1, OUTPUT);
  pinMode(MS2, OUTPUT);
  pinMode(MS3, OUTPUT);
  pinMode(stepPin2,OUTPUT);
  pinMode(dirPin2, OUTPUT);
  pinMode(MS12, OUTPUT);
  pinMode(MS22, OUTPUT);
  pinMode(MS32, OUTPUT);
}
void loop() {
  digitalWrite(MS1, HIGH);
  digitalWrite(MS2, LOW);
  digitalWrite(MS3, LOW);
  digitalWrite(MS12, HIGH);
  digitalWrite(MS22, LOW);
  digitalWrite(MS32, LOW);
  
  digitalWrite(dirPin , LOW); // Enables the motor to move in a particular direction
  digitalWrite(dirPin2, HIGH);// Makes 200 pulses for making one full cycle rotation
  for(int x = 0; x < 18000; x++) {
    digitalWrite(stepPin,HIGH);
    digitalWrite(stepPin2, HIGH);  
    delayMicroseconds(400); 
    digitalWrite(stepPin,LOW);
    digitalWrite(stepPin2, LOW);  
    delayMicroseconds(400); 
  }

  delay(1000); // One second delay
   
  digitalWrite(dirPin,HIGH); //Changes the rotations direction
  digitalWrite(dirPin2, LOW);// Makes 400 pulses for making two full cycle rotation
  for(int x = 0; x < 18000; x++) {
    digitalWrite(stepPin,HIGH);
    digitalWrite(stepPin2, HIGH);
    delayMicroseconds(400);
    digitalWrite(stepPin,LOW);
    digitalWrite(stepPin2, LOW);
    delayMicroseconds(400);
  }
  delay(1000);
}

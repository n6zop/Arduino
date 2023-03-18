/*
 * pin segment
 * 2 middle
 * 3 bottem right
 * 4 top right
 * 5 top 
 * 6 bottem
 * 7 left bottem
 * 8 left top
 */
 
int segment[] = {2,3,4,5,6,7,8}; // dem pins
int d = 1000;  // delay time

void setup() {
for(int i = 0; i< 8; i++){
  pinMode(segment[i],OUTPUT);
}

}

void loop() {
  zero();
  delay(d);
  one();
  delay(d);
  two();
  delay(d);
  three();
  delay(d);
  four();
  delay(d);
  five();
  delay(d);
  six();
  delay(d);
  seven();
  delay(d);
  eight();
  delay(d);
  nine();
  delay(d);

}

void zero(){
  digitalWrite(2,0);
  digitalWrite(3,1);
  digitalWrite(4,1);
  digitalWrite(5,1);
  digitalWrite(6,1);
  digitalWrite(7,1);
  digitalWrite(8,1);
}

void one(){
  digitalWrite(2,0);
  digitalWrite(3,1);
  digitalWrite(4,1);
  digitalWrite(5,0);
  digitalWrite(6,0);
  digitalWrite(7,0);
  digitalWrite(8,0);
}

void two(){
  digitalWrite(2,1);
  digitalWrite(3,0);
  digitalWrite(4,1);
  digitalWrite(5,1);
  digitalWrite(6,1);
  digitalWrite(7,1);
  digitalWrite(8,0);
}

void three(){
  digitalWrite(2,1);
  digitalWrite(3,1);
  digitalWrite(4,1);
  digitalWrite(5,1);
  digitalWrite(6,1);
  digitalWrite(7,0);
  digitalWrite(8,0);
}

void four(){
  digitalWrite(2,1);
  digitalWrite(3,1);
  digitalWrite(4,1);
  digitalWrite(5,0);
  digitalWrite(6,0);
  digitalWrite(7,0);
  digitalWrite(8,1);
}

void five(){
  digitalWrite(2,1);
  digitalWrite(3,1);
  digitalWrite(4,0);
  digitalWrite(5,1);
  digitalWrite(6,1);
  digitalWrite(7,0);
  digitalWrite(8,1);
}

void six(){
  digitalWrite(2,1);
  digitalWrite(3,1);
  digitalWrite(4,0);
  digitalWrite(5,1);
  digitalWrite(6,1);
  digitalWrite(7,1);
  digitalWrite(8,1);
}

void seven(){
  digitalWrite(2,0);
  digitalWrite(3,1);
  digitalWrite(4,1);
  digitalWrite(5,1);
  digitalWrite(6,0);
  digitalWrite(7,0);
  digitalWrite(8,0);
}

void eight(){
  digitalWrite(2,1);
  digitalWrite(3,1);
  digitalWrite(4,1);
  digitalWrite(5,1);
  digitalWrite(6,1);
  digitalWrite(7,1);
  digitalWrite(8,1);
}

void nine(){
  digitalWrite(2,1);
  digitalWrite(3,1);
  digitalWrite(4,1);
  digitalWrite(5,1);
  digitalWrite(6,1);
  digitalWrite(7,0);
  digitalWrite(8,1);
}

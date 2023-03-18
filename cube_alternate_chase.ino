/*
  Name:      cube_alternate_chase.ino
  Description:  Layers then faces of the cube chasing.
  Build:    0.1
*/
 
// Speed for wait times.
int wait = 500;
 
// Naming and declaring the pins for the LED cube.
int topLayer = 13;
int midLayer = 12;
int botLayer = 11;

int col1 = 10;
int col2 = 9;
int col3 = 8;
int col4 = 7;
int col5 = 6;
int col6 = 5;
int col7 = 4;
int col8 = 3;
int col9 = 2;

void setup() {                
  // Setting up the pins.
  pinMode(topLayer, OUTPUT); 
  pinMode(midLayer, OUTPUT);
  pinMode(botLayer, OUTPUT);
  
  pinMode(col1, OUTPUT);
  pinMode(col2, OUTPUT);
  pinMode(col3, OUTPUT);
  pinMode(col4, OUTPUT);
  pinMode(col5, OUTPUT);
  pinMode(col6, OUTPUT);
  pinMode(col7, OUTPUT);
  pinMode(col8, OUTPUT);
  pinMode(col9, OUTPUT);
}

void loop() {
  
  // Main Program for the cube.
  
  // **************************
  // LAYERS FIRST
  // **************************
  
  //Turns all LED columns on.
  digitalWrite(col1, HIGH);
  digitalWrite(col2, HIGH);
  digitalWrite(col3, HIGH);
  digitalWrite(col4, HIGH);
  digitalWrite(col5, HIGH);
  digitalWrite(col6, HIGH);
  digitalWrite(col7, HIGH);
  digitalWrite(col8, HIGH);
  digitalWrite(col9, HIGH);
  
  // Bottom layer.
  digitalWrite(botLayer, HIGH);
  delay(wait);
  digitalWrite(botLayer, LOW);
  
  // Middle layer.
  digitalWrite(midLayer, HIGH);
  delay(wait);
  digitalWrite(midLayer, LOW);

  // Top layer.
  digitalWrite(topLayer, HIGH);
  delay(wait);
  digitalWrite(topLayer, LOW);
  
  // Middle layer.
  digitalWrite(midLayer, HIGH);
  delay(wait);
  digitalWrite(midLayer, LOW);
  
  // Bottom layer.
  digitalWrite(botLayer, HIGH);
  delay(wait);
  digitalWrite(botLayer, LOW);
  
  //Turns all LED columns off.
  digitalWrite(col1, LOW);
  digitalWrite(col2, LOW);
  digitalWrite(col3, LOW);
  digitalWrite(col4, LOW);
  digitalWrite(col5, LOW);
  digitalWrite(col6, LOW);
  digitalWrite(col7, LOW);
  digitalWrite(col8, LOW);
  digitalWrite(col9, LOW);
  
  // **************************
  // FACES SECOND
  // **************************
  
  //Turns all LED layers on.
  digitalWrite(topLayer, HIGH);
  digitalWrite(midLayer, HIGH);
  digitalWrite(botLayer, HIGH);
  
  // Rear Face.
  digitalWrite(col1, HIGH);
  digitalWrite(col2, HIGH);
  digitalWrite(col3, HIGH);
  delay(wait);
  digitalWrite(col1, LOW);
  digitalWrite(col2, LOW);
  digitalWrite(col3, LOW);
  
  // Middle Face.
  digitalWrite(col4, HIGH);
  digitalWrite(col5, HIGH);
  digitalWrite(col6, HIGH);
  delay(wait);
  digitalWrite(col4, LOW);
  digitalWrite(col5, LOW);
  digitalWrite(col6, LOW);

  // Front Face.
  digitalWrite(col7, HIGH);
  digitalWrite(col8, HIGH);
  digitalWrite(col9, HIGH);
  delay(wait);
  digitalWrite(col7, LOW);
  digitalWrite(col8, LOW);
  digitalWrite(col9, LOW);
  
  // Middle Face.
  digitalWrite(col4, HIGH);
  digitalWrite(col5, HIGH);
  digitalWrite(col6, HIGH);
  delay(wait);
  digitalWrite(col4, LOW);
  digitalWrite(col5, LOW);
  digitalWrite(col6, LOW);
  
  // Rear Face.
  digitalWrite(col1, HIGH);
  digitalWrite(col2, HIGH);
  digitalWrite(col3, HIGH);
  delay(wait);
  digitalWrite(col1, LOW);
  digitalWrite(col2, LOW);
  digitalWrite(col3, LOW);
  
  //Turns all LED layers off.
  digitalWrite(topLayer, LOW);
  digitalWrite(midLayer, LOW);
  digitalWrite(botLayer, LOW);
}

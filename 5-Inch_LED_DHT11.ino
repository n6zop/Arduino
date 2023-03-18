/*
 * Rui Santos 
 * Complete Project Details http://randomnerdtutorials.com
 */

#include "Nextion.h"

#include "DHT.h"
#define DHTPIN 4     // what digital pin we're connected to

// Uncomment whatever type you're using!
#define DHTTYPE DHT11   // DHT 11
//#define DHTTYPE DHT22   // DHT 22  (AM2302), AM2321
//#define DHTTYPE DHT21   // DHT 21 (AM2301)

// Initialize DHT sensor.
DHT dht(DHTPIN, DHTTYPE);

// LED pins
const int led1 = 5;
const int led2 = 6;
const int led3 = 7;
const int led4 = 8;
const int led5 = 9;
const int led6 = 10;

// Declare your Nextion objects - Example (page id = 0, component id = 1, component name = "b0") 
NexText tState = NexText(0, 14, "tState"); 
//NexText tState1 = NexText(0, 15, "tState1"); 
//NexText tState2 = NexText(0, 16, "tState2"); 
//NexText tState3 = NexText(0, 17, "tState3"); 
//NexText tState4 = NexText(0, 18, "tState4"); 
//NexText tState5 = NexText(0, 19, "tState5"); 
NexButton bon = NexButton(0, 2, "bon");
NexButton boff = NexButton(0, 3, "boff");
NexButton b2on = NexButton(0, 4, "b2on");
NexButton b3off = NexButton(0, 5, "b3off");
NexButton b4on = NexButton(0, 6, "b4on");
NexButton b5off = NexButton(0, 7, "b5off");
NexButton b6on = NexButton(0, 8, "b6on");
NexButton b7off = NexButton(0, 9, "b7off");
NexButton b8on = NexButton(0, 10, "b8on");
NexButton b9off = NexButton(0, 11, "b9off");
NexButton b10on = NexButton(0, 12, "b10on");
NexButton b11off = NexButton(0, 13, "b11off");
NexText tTempC = NexText(1, 4, "tTempC");
NexText tTempF = NexText(1, 8, "tTempF");
NexProgressBar jHumidity = NexProgressBar(1, 10, "jHumidity");
NexText tHumidity = NexText(1, 6, "tHumidity");
NexButton bUpdate = NexButton(1, 11, "bUpdate");


// Register a button object to the touch event list.  
NexTouch *nex_listen_list[] = {
  &bon,
  &boff,
  &b2on,
  &b3off,
  &b4on,
  &b5off,
  &b6on,
  &b7off,
  &b8on,
  &b9off,
  &b10on,
  &b11off,
  &bUpdate,
  NULL
};
 
/*
 * Button bOn component pop callback function. 
 * When the ON button is released, the LED turns on and the state text changes. 
 */
void bonPopCallback(void *ptr) {
  tState.setText("State: on");
  digitalWrite(led1, HIGH);
}

/*
 * Button bOff component pop callback function. 
 * When the OFF button is released, the LED turns off and the state text changes. 
 */
void boffPopCallback(void *ptr) {
  tState.setText("State: off");
  digitalWrite(led1, LOW);
}

void b2onPopCallback(void *ptr) {
//  tState1.setText("State: on");
  digitalWrite(led2, HIGH);
}

/*
 * Button bOff component pop callback function. 
 * When the OFF button is released, the LED turns off and the state text changes. 
 */
void b3offPopCallback(void *ptr) {
//  tState1.setText("State: off");
  digitalWrite(led2, LOW);
}
void b4onPopCallback(void *ptr) {
//  tState2.setText("State: on");
  digitalWrite(led3, HIGH);
}

/*
 * Button bOff component pop callback function. 
 * When the OFF button is released, the LED turns off and the state text changes. 
 */
void b5offPopCallback(void *ptr) {
//  tState2.setText("State: off");
  digitalWrite(led3, LOW);
}
void b6onPopCallback(void *ptr) {
//  tState3.setText("State: on");
  digitalWrite(led4, HIGH);
}

/*
 * Button bOff component pop callback function. 
 * When the OFF button is released, the LED turns off and the state text changes. 
 */
void b7offPopCallback(void *ptr) {
//  tState3.setText("State: off");
  digitalWrite(led4, LOW);
}
void b8onPopCallback(void *ptr) {
//  tState4.setText("State: on");
  digitalWrite(led5, HIGH);
}

/*
 * Button bOff component pop callback function. 
 * When the OFF button is released, the LED turns off and the state text changes. 
 */
void b9offPopCallback(void *ptr) {
//  tState4.setText("State: off");
  digitalWrite(led5, LOW);
}
void b10onPopCallback(void *ptr) {
//  tState5.setText("State: on");
  digitalWrite(led6, HIGH);
}

/*
 * Button bOff component pop callback function. 
 * When the OFF button is released, the LED turns off and the state text changes. 
 */
void b11offPopCallback(void *ptr) {
//  tState5.setText("State: off");
  digitalWrite(led6, LOW);
}
/*
 * Slider h0 component pop callback function. 
 * When the slider is released, the LED brightness changes and the slider text changes. 
 */
//void h0PopCallback(void *ptr) {
//  uint32_t number = 0;
//  char temp[10] = {0};
  // change text with the current slider value
//  h0.getValue(&number);
//  utoa(number, temp, 10);
//  tSlider.setText(temp);
  // change LED brightness
//  analogWrite(led2, number); 
//}

/*
 * Button bUpdate component pop callback function. 
 * When the UPDATE button is released, the temperature and humidity readings are updated. 
 */
void bUpdatePopCallback(void *ptr) {
  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  float h = dht.readHumidity();
  // Read temperature as Celsius (the default)
  float t = dht.readTemperature();
  // Read temperature as Fahrenheit (isFahrenheit = true)
  float f = dht.readTemperature(true);

  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t) || isnan(f)) {
    return;
  }
  // Update temperature in Celsius
  static char temperatureCTemp[6];
  dtostrf(t, 6, 2, temperatureCTemp);
  tTempC.setText(temperatureCTemp);

  // Update humidity percentage text and progress bar
  char hTemp[10] = {0}; 
  utoa(int(h), hTemp, 10);
  tHumidity.setText(hTemp);
  jHumidity.setValue(int(h));

  // Update temperature in Fahrenheit
  static char temperatureFTemp[6];
  dtostrf(f, 6, 2, temperatureFTemp);
  tTempF.setText(temperatureFTemp);
}

void setup(void) {    
  dht.begin();
  Serial.begin(9600);
    
  // You might need to change NexConfig.h file in your ITEADLIB_Arduino_Nextion folder
  // Set the baudrate which is for debug and communicate with Nextion screen
  nexInit();

  // Register the pop event callback function of the components
  bon.attachPop(bonPopCallback, &bon);
  boff.attachPop(boffPopCallback, &boff);
  b2on.attachPop(b2onPopCallback, &b2on);
  b3off.attachPop(b3offPopCallback, &b3off);
  b4on.attachPop(b4onPopCallback, &b4on);
  b5off.attachPop(b5offPopCallback, &b5off);
  b6on.attachPop(b6onPopCallback, &b6on);
  b7off.attachPop(b7offPopCallback, &b7off);
  b8on.attachPop(b8onPopCallback, &b8on);
  b9off.attachPop(b9offPopCallback, &b9off);
  b10on.attachPop(b10onPopCallback, &b10on);
  b11off.attachPop(b11offPopCallback, &b11off);
  bUpdate.attachPop(bUpdatePopCallback, &bUpdate);
    
  // Set LEDs as outputs
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
  pinMode(led6, OUTPUT);
}

void loop(void) {   
  /*
   * When a pop or push event occured every time,
   * the corresponding component[right page id and component id] in touch event list will be asked.
   */
  nexLoop(nex_listen_list);
}

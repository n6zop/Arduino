int ledPins[] = {2,3,4,5};

// The first element of an array is index 0.

// We've put the value "2" in index 0, "3" in index 1, etc.

// The final index in the above array is 7, which contains

// the value "9".

// We're using the values in this array to specify the pin numbers

// that the eight LEDs are connected to. LED 0 is connected to

// pin 2, LED 1 is connected to pin 3, etc.

void setup()

{

int index;

// In this sketch, we'll use "for() loops" to step variables from

// one value to another, and perform a set of instructions for

// each step. For() loops are a very handy way to get numbers to

// count up or down.

// Every for() loop has three statements separated by

// semicolons (;):

// 1. Something to do before starting

// 2. A test to perform; as long as it's true, keep looping

// 3. Something to do after each loop (increase a variable)

// Here we'll use a for() loop to initialize all the LED pins

// to outputs. This is much easier than writing eight separate

// statements to do the same thing.

// This for() loop will make index = 0, then run the pinMode()

// statement within the brackets. It will then do the same thing

// for index = 2, index = 3, etc. all the way to index = 7.

for(index = 0; index <= 7; index++)

{

pinMode(ledPins[index],OUTPUT);

// ledPins[index] is replaced by the value in the array.

// For example, ledPins[0] is 2

}

}

void loop()

{

// This loop() calls functions that we've written further below.

// We've disabled some of these by commenting them out (putting

// "//" in front of them). To try different LED displays, remove

// the "//" in front of the ones you'd like to run, and add "//"

// in front of those you don't to comment out (and disable) those

// lines.

oneAfterAnotherNoLoop(); // Light up all the LEDs in turn

}

/*

oneAfterAnotherNoLoop()

This function will light one LED, delay for delayTime, then light

the next LED, and repeat until all the LEDs are on. It will then

turn them off in the reverse order.

This function does NOT use a for() loop. We've done it the hard way

to show you how much easier life can be when you use for() loops.

Take a look at oneAfterAnotherLoop() further down, which does

exactly the same thing with much less typing.

*/

void oneAfterAnotherNoLoop()

{

int delayTime = 100; // time (milliseconds) to pause between LEDs

// make this smaller for faster switching

// turn all the LEDs on:

//digitalWrite(ledPins[0], HIGH); //Turns on LED #0 (pin 2)
//
//delay(delayTime); //wait delayTime milliseconds
//
//digitalWrite(ledPins[1], HIGH); //Turns on LED #1 (pin 3)
//
//delay(delayTime); //wait delayTime milliseconds

digitalWrite(ledPins[2], HIGH); //Turns on LED #2 (pin 4)

delay(delayTime); //wait delayTime milliseconds

digitalWrite(ledPins[3], HIGH); //Turns on LED #3 (pin 5)

delay(delayTime); //wait delayTime milliseconds

digitalWrite(ledPins[4], HIGH); //Turns on LED #4 (pin 6)

delay(delayTime); //wait delayTime milliseconds

digitalWrite(ledPins[5], HIGH); //Turns on LED #5 (pin 7)

delay(delayTime); //wait delayTime milliseconds

//digitalWrite(ledPins[6], HIGH); //Turns on LED #6 (pin 8)
//
//delay(delayTime); //wait delayTime milliseconds
//
//digitalWrite(ledPins[7], HIGH); //Turns on LED #7 (pin 9)
//
//delay(delayTime); //wait delayTime milliseconds

// turn all the LEDs off:

//digitalWrite(ledPins[7], LOW); //Turn off LED #7 (pin 9)
//
//delay(delayTime); //wait delayTime milliseconds
//
//digitalWrite(ledPins[6], LOW); //Turn off LED #6 (pin 8)
//
//delay(delayTime); //wait delayTime milliseconds

digitalWrite(ledPins[5], LOW); //Turn off LED #5 (pin 7)

delay(delayTime); //wait delayTime milliseconds

digitalWrite(ledPins[4], LOW); //Turn off LED #4 (pin 6)

delay(delayTime); //wait delayTime milliseconds

digitalWrite(ledPins[3], LOW); //Turn off LED #3 (pin 5)

delay(delayTime); //wait delayTime milliseconds

digitalWrite(ledPins[2], LOW); //Turn off LED #2 (pin 4)

delay(delayTime); //wait delayTime milliseconds

//digitalWrite(ledPins[1], LOW); //Turn off LED #1 (pin 3)
//
//delay(delayTime); //wait delayTime milliseconds
//
//digitalWrite(ledPins[0], LOW); //Turn off LED #0 (pin 2)
//
//delay(delayTime); //wait delayTime milliseconds

}

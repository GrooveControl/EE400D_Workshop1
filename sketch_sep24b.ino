/*
  Button

 Turns on and off a light emitting diode(LED) connected to digital
 pin 13, when pressing a pushbutton attached to pin 2.


 The circuit:
 * LED attached from pin 13 to ground
 * pushbutton attached to pin 2 from +5V
 * 10K resistor attached to pin 2 from ground

 * Note: on most Arduinos there is already an LED on the board
 attached to pin 13.


 created 2005
 by DojoDave <http://www.0j0.org>
 modified 30 Aug 2011
 by Tom Igoe

 This example code is in the public domain.

 http://www.arduino.cc/en/Tutorial/Button

 Modified By: alanvalles@gmail.com sep242016
 for questions regarding this code contact, alanvalles@gmail.com
 */

// constants won't change. They're used here to
// set pin numbers:
const int buttonPin = 8;     // the number of the pushbutton pin
const int ledPin =  9;      // the number of the LED pin

// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status
int brightness = 0;
void setup() {
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);
}

void loop() {
  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);

  // check if the pushbutton is pressed.
  // if it is, the buttonState is HIGH:

  if (buttonState == HIGH) {
   
    for (brightness = 0;brightness<=255;brightness+=5) 
    {
      analogWrite(ledPin,brightness);
      buttonState = digitalRead(buttonPin);
       if(buttonState==LOW){
        brightness= 0;
        break;}
      delay(20);
      }
    }
   else {
    // turn LED off:
    digitalWrite(ledPin, LOW);
  }
}

#include <SoftwareSerial.h> // will allow us to use the serial communication library

int LED = 13; // most arduino boards have an onboard LED on pin 13

void setup() { // called once pers startup

  // start sequence -> flash LED 3 times
  pinMode(LED, OUTPUT); // set up pin as output
  for (int i = 0; i < 3; i++) {
    digitalWrite(LED, HIGH); // turn on LED (i.e. set to HIGH voltage)
    delay(500); // wait for 500 ms (i.e. half a second)
    digitalWrite(LED, LOW);
    delay(500);
  }
  
}

void loop() { // continuous loop

}

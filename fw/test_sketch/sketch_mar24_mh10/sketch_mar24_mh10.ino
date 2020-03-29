#include <SoftwareSerial.h> // will allow us to use the serial communication library

SoftwareSerial HM10(2, 3); // RX = 2, TX = 3 on the HM-10 Module itself

// variable to store the operation instructions sent from HM10 and the app
String inData = "";

// CONSTANTS
int LED = 13; // most arduino boards have an onboard LED on pin 13 (used to identify program status)
int BAUD_RATE = 9600;

// Operation variables
int FiO2 = 20; // default is 20% FiO2
int respiratpryRate = 16; // deafult respiratory rate is 16 breaths/min
int pip = 16; // default PIP (inspritation pressure in Bi-PAP mode) is 16 cmH2O
int peep = 6; // default PEEP (inspritation pressure in Bi-PAP mode) is 6 cmH2O
int constantPressure = 10; // default constant pressure in C-PAP mode is 10 cmH2O

// Helper variables
String prevSettings = "";
char operationMode = "A"; // default is assist mode

void setup() { // called once pers startup

  Serial.begin(BAUD_RATE);
  
  Serial.println("HM10 serial started at 9600"); // debugging statement
  
  HM10.begin(BAUD_RATE); // set HM10 to the BAUD rate
  
  
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
  HM10.listen(); // listen to the HM10 port

  while (HM10.available() > 0) { // if HM10 sends smth, read it
    
    inData = String(HM10.read()); // save the data in string format
    
    // change the settings only if there are new settings
    if (inData != prevSettings) {
      Serial.println("New settings!"); // for debugging
      applyNewSettings(inData);
    }
    
    Serial.println(appData);
  }

  // DUMMY TEST CODE FOR HM-10
//  if (inData ="OFF") {
//    Serial.println("LED OFF");
//    digitalWrite(LED, LOW); // switch LED OFF
//    delay(500); // wait before taking instructions or going through the loop again
//    }
//
//  if (intData == "ON") {
//    Serial.println("LED ON");
//    digitalWrite(LED, HIGH); // switch LED ON
//    delay(500); // wait before taking instructions or going through the loop again
//    }
    
  // ACTUAL CONTROL CODE
  
  // Mode of operation and its parameters
  switch (operationMode) {
    case "B": // Bi-PAP mode
      Serial.println("Bi-PAP mode");

      // get the 3 parameters needed to operate on Bi-PAP from the control string
      respiratpryRate = int(inData.charAt(3)) * 10 + int(inData.charAt(4));
      int pip = int(inData.charAt(5)) * 10 + int(inData.charAt(6));
      int peep = int(inData.charAt(7)) * 10 + int(inData.charAt(8));
      // TODO divert 
      delay(500); // the exact inspiration time needed 
      // TODO set the PEEP (exhale pressure)
      delay(500); // the 
    default: // Assit Mode
    }
}

void applyNewSettings(String inData) {
  
  // FiO2 percentage
  switch (inData.charAt(1) {
    case 1: // O2 source is connected
      FiO2 = int(inData.charAt(2)) * 10; // FiO2 % (in increments of 10)
      if (FiO2 = 10) FiO2 = 100; // dirty solution to allow 100% (by writing 1, cuz we cant have 10% anyway)
      // TODO set oxygen valve to allow desired FiO2 %
      break;
    default: // if O2 source is not connected, do nothing
      break;
  }

  // Mode of operation and its parameters
  switch (inData.charAt(0) {
    case "B": // Bi-PAP mode
      Serial.println("Bi-PAP mode");

      // get the 3 parameters needed to operate on Bi-PAP from the control string
      respiratpryRate = int(inData.charAt(3)) * 10 + int(inData.charAt(4));
      int pip = int(inData.charAt(5)) * 10 + int(inData.charAt(6));
      int peep = int(inData.charAt(7)) * 10 + int(inData.charAt(8));
    }
}

// TODO apply pressure through the Parker regulator
void applyPressure(int pressure) {
  // TODO apply certain voltage that will result in this pressure
}

// can use this function to test the HM-10 Module
void testHM10() {
    if (Serial.available()) { // Read user input if available for debugging
    delay(10);
    HM10.write(Serial.read())
  }
}
}

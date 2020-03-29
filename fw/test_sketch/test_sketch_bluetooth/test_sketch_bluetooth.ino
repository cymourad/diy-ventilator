// https://circuitdigest.com/microcontroller-projects/how-to-use-arduino-and-hm-10-ble-module-to-control-led-with-android-app
// used this tutorial

#include <SoftwareSerial.h>
SoftwareSerial HM10(2, 3); // RX = 2, TX = 3
char appData;  
String inData = "";
void setup()
{
  Serial.begin(9600);
  Serial.println("HM10 serial started at 9600");
  HM10.begin(9600); // set HM10 serial at 9600 baud rate
  pinMode(13, OUTPUT); // onboard LED
  digitalWrite(13, LOW); // switch OFF LED

}

void loop()
{
  HM10.listen();  // listen the HM10 port
  while (HM10.available() > 0) {   // if HM10 sends something then read
    Serial.println("HM-10 is available!");
    appData = HM10.read();
    inData = String(appData);  // save the data in string format
    Serial.write(appData);
  }

 
  if (Serial.available()) {           // Read user input if available.
    delay(10);
    HM10.write(Serial.read());
  }
  if ( inData == "F") {
    Serial.println("LED OFF");
    digitalWrite(13, LOW); // switch OFF LED
    delay(500);
  }
  if ( inData == "N") {
    Serial.println("LED ON");
    digitalWrite(13, HIGH); // switch OFF LED
    delay(500);
    digitalWrite(13, LOW); // switch OFF LED
    delay(500);
  }
}

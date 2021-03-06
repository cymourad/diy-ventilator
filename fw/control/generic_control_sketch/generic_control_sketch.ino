#include <SoftwareSerial.h> // will allow us to use the serial communication library

// Connect the HM-10 to pins 0, 1, 5V, and Gnd and use the 1 and 2 k resistors for the Rx connection
SoftwareSerial HM10(2, 3); // RX = 2, TX = 3 on the HM-10 Module itself

// variable to store the operation instructions sent from HM10 and the app
String inData = "";

// CONSTANTS
int LED = 13; // most arduino boards have an onboard LED on pin 13 (used to identify program status)
int BAUD_RATE = 9600;
int EXHALE_PROXIMAL_FLOW_SENSOR = 1;
int INHALE_PROXIMAL_FLOW_SENSOR = 0;

// Operation variables
int FiO2 = 20; // default is 20% FiO2
int humidityLevelReference = 55; // default relative humidity is 55 [%] 
int temperatureReference = 37; // deafult air temperature 
int respiratpryRate = 16; // deafult respiratory rate is 16 [breaths/min]
int iPortion = 1; // the I in the I:E ratio
int ePortion = 2; // the E in the I:E ratio
int pip = 16; // default PIP (inspritation pressure in Bi-PAP mode) is 16 [cmH2O]
int peep = 6; // default PEEP (inspritation pressure in Bi-PAP mode) is 6 [cmH2O]

bool isHumidifying = false;

// Helper variables
String prevSettings = "";
String operationMode = "A"; // default is assist mode
double breathPeriod = 4000; // [milli-seconds/breath]
int inhalePeriod = 1000; // inhale time per breath [ms]
int exhalePeriod = 2000; // exhale time per breath [ms]
int timeToExecuteOtherCycles = 10; // time taken by cycles in loop() [ms]
int currentHumidity = 55; // the current sensor reading of the humidity
int currentTemperature = 37; // the current sensor reading of the temperature

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
    
    inData = String(HM10.read()); // save the data to string format
    
    // change the settings only if there are new settings
    if (inData != prevSettings) {
      Serial.println("New settings!"); // for debugging
      applyNewSettings(inData);
      prevSettings = inData;
    }
    
    Serial.println(inData);
  }
    
  // ACTUAL CONTROL CODE

  // make sure humidity and temperature match the desired settings
  if (isHumidifying) {

    // TODO monitor humidity level (populate currentHumidity)
    readHumidityTemperatureSensor();

    // TODO coorect the humidity / temperature if it does not match the desired one
    if (currentHumidity != humidityLevelReference) {
      if (currentTemperature <= temperatureReference && currentHumidity < humidityLevelReference) {
        turnHeaterOn();
      }
      else if (currentTemperature >= temperatureReference && currentHumidity > humidityLevelReference) {
        turnHeaterOff();
      }
    }
  }
  
  // Mode of operation and its parameters
  if (operationMode == "B") { // Bi-PAP mode

      setPressureRegulator(pip); // TODO set the pressure regulator to the PIP
      delay(inhalePeriod); // TODO change to the exact inhale time needed 

      setPressureRegulator(peep); // TODO set the pressure regulator to the PEEP
      delay(exhalePeriod - timeToExecuteOtherCycles); // TODO change to the excat exhale time needed minus an estimate of cycles lost performing other tasks in the loop
      
      // TODO check the exhale flow meter to make sure tidal volume is good

  } else if (operationMode == "C"){ // C-PAP mode
      // There is not much to do every cycle, the pressure keeps going at same rate from one side
  } else {  // Assit Mode 
      // TODO average readings from pressure sensor to find PIP, PEEP, inhalePeriod and exhalePeriod
      // TODO listen to the pressure sensor in case patient misses a breath
      // TODO if breath missed, apply avgPIP for avgInhalePeriod
      }
}

void applyNewSettings(String inData) {
  
  // FiO2
  if (inData.charAt(1) == 1) { // O2 source is connected

      FiO2 = int(inData.charAt(2)) * 10; // FiO2 (in increments of 10)

      if (FiO2 = 10) FiO2 = 100; // dirty solution to allow 100% (by writing 1, cuz we cant have 10% anyway)

      // TODO set oxygen flow regulator to allow desired FiO2 !!manually!!
      // TODO and adjust the speed of the fan to provide appropriate total flow and FiO2


  } else if (inData.charAt(1) == 0) { // O2 is not connected
      // TODO make sure the input flow-meter reading matches the expected flow calcualted for the fan and correct it if needed
  } else { // wrong string was sent, do nothing (and flash light to indicate wrong string)
      Serial.println("Wrong settings string sent, the oxygen status must be 0 or 1!");
      failureLEDalert(5); // falsh LED 5 times to tell the user they sent faulty settings
  }

  // Humidity and temperature
  if (inData.charAt(3) == 1) { // humidifer is connected
      isHumidifying = true; // set a bool to monitor humidity
      humidityLevelReference = int(inData.charAt(4)) * 10 + int(inData.charAt(5));
      temperatureReference = int(inData.charAt(6)) * 10 + int(inData.charAt(7));
  } else if (inData.charAt(3) == 0) { // humudifier is not connected
      isHumidifying = false;
  } else { // wrong string was sent, do nothing (and flash light to indicate wrong string)
      Serial.println("Wrong settings string sent, the humidifier status must be 0 or 1!");
      failureLEDalert(5); // falsh LED 5 times to tell the user they sent faulty settings
  }

  // Mode of operation and its parameters
  if (String(inData.charAt(0)) == "B") { // Bi-PAP mode
      Serial.println("Setting ventilator to Bi-PAP mode"); // for debugging

      operationMode = "B"; // setting the operation mode

      readFourBreatingParamsFromSettingsString();

  } else if (String(inData.charAt(0)) == "C") { // C-PAP Mode
      Serial.println("Setting ventilator to C-PAP mode"); // for debugging

      operationMode = "C"; // setting the operation mode

      // get the required parameter from the control string
      int peepSent = int(inData.charAt(14)) * 10 + int(inData.charAt(15));
      if (peepSent < 4 || peepSent > 20) {
        wrongSettingStringAlert("Wrong settings string sent, the PEEP must be between 4 and 20 cmH2O!");
      } else {
        peep = peepSent;
      }

      // TODO set the PEEP valve to satisfy this constant pressure setting
      setPressureRegulator(peep);

      // TODO adjust flow in

  } else if (String(inData.charAt(0)) == "A") { // Assist mode
      Serial.println("Setting ventilator to Assist mode"); // for debugging

      operationMode = "A"; // setting the operation mode

      readFourBreatingParamsFromSettingsString();

  } else if (String(inData.charAt(0)) == "T") { // Test mode
      // TODO run test routine
      operationMode = "A"; // set to assist mode (default) when done running the tests
  } else { // wrong string was sent, do nothing (and flash light to indicate wrong string)
      wrongSettingStringAlert("Wrong settings string sent, the operation mode must be A, B, C, or T!");
  }
}

// save the 4 parameters needed to operate on Bi-PAP/Assist mode from the control string to the global variables
void readFourBreatingParamsFromSettingsString() {
  // Respiratory Rate
  int respiratpryRateSent = int(inData.charAt(8)) * 10 + int(inData.charAt(9));
  if (respiratpryRateSent < 4 || respiratpryRateSent > 60) {
    wrongSettingStringAlert("Wrong settings string sent, the respiratory rate must be between 4 and 60 breaths/min!");
  } else {
    respiratpryRate = respiratpryRateSent;
  }

  // I:E Ratio
  iPortion = int(inData.charAt(10));
  ePortion = int(inData.charAt(11));

  // PIP
  int pipSent = int(inData.charAt(12)) * 10 + int(inData.charAt(13));
  if (pipSent < 4 || pipSent > 40) {
    wrongSettingStringAlert("Wrong settings string sent, the PIP must be between 4 and 60 cmH2O!");
  } else {
    pip = pipSent;
  }

  // PEEP
  int peepSent = int(inData.charAt(14)) * 10 + int(inData.charAt(15));
  if (peepSent < 4 || peepSent > 20) {
    wrongSettingStringAlert("Wrong settings string sent, the PEEP must be between 4 and 20 cmH2O!");
  } else {
    peep = peepSent;
  }

  // calculate intervals of inhale and exhale (inhalePeriod and exhalePeriod) based on the new respiratory rate
  breathPeriod = (60 / respiratpryRate) * 1000; // [ms]
  inhalePeriod = breathPeriod * iPortion / (iPortion + ePortion); // [ms]
  exhalePeriod = breathPeriod - inhalePeriod; // [ms]
}

// can use this function to test the HM-10 Module
void testHM10() {
    if (Serial.available()) { // Read user input if available for debugging
    delay(10);
    HM10.write(Serial.read());
  }
}

// in case of a wrong settings string, output instructons to Serial (and maybe bluetooth later) and flash LED tiidicate error
void wrongSettingStringAlert(String message) {
  Serial.println(message);
  failureLEDalert(5); // falsh LED 5 times to tell the user they sent faulty settings
}

// flash LED to signal that something failed
void failureLEDalert(int seconds) {
  for (int i = seconds; i < 5; i++) {
    digitalWrite(LED, HIGH); // turn on LED (i.e. set to HIGH voltage)
    delay(500); // wait for 500 ms (i.e. half a second)
    digitalWrite(LED, LOW);
    delay(500);
  }
}

// read the humidity sensor to find realtive humidity and temp
void readHumidityTemperatureSensor() {
  // THOUGHT might need to average or compare to old values in case of noise
  currentHumidity = 100; // TODO fill this reading correctly
  currentTemperature = 90; // TODO fill this reading correctly
}

void turnHeaterOn() {
  // TODO send voltage to turn the heater ON
}

void turnHeaterOff() {
  // TODO send voltage to turn the heater OFF
}

void setPressureRegulator(int pressure) {
  // TODO send voltage to apply
}

double readFlow(int sensorNumber) {
  // TODO read value of proximal flow sensor and return it in milli-Liter per second [mL/s]
  return 5;
}

// apply appropriate voltage to fan blower to achieve desired total flow [mL/sec]
void changeFanSpeedToAchieveFlow(int desiredFlow) {
  // TODO read current flow
  double currentFlow = readFlow(INHALE_PROXIMAL_FLOW_SENSOR);
  // TODO change speed of fan till flow matches desired flow (might need to allow for some tolerance --> while(currentFlow < desiredFlow * 0.95 && currentFlow > desiredFlow * 1.05))
  while(currentFlow != desiredFlow) {
    if (currentFlow < desiredFlow) { // need to make fan go faster
      // TODO set this to an incremental speed
      setFanSpeed(10);
    } else { // need to make fan go slower
      // TODO set this to a decremental speed
      setFanSpeed(10);
    }
  }
}

void setFanSpeed(int speed) {
  // TODO apply voltage to fan to set its speed
}

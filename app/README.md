# DIY-Ventilator
This repositry hosts two sub-repositories that feature the code of two identical mobile applications: an IOS app and an Android.
The app conncets to the Arduino controlling the ventilator and features three main tabs:
1. Settings
2. Monitor
3. Tutorials

As the machines is designed to be modualr, the user must first indicate in the settings which parts are connected:
* BPAP (base/default)
* Oxygen supply (to be connected immediately to the output of the ventilator)
* Humidifier (to be connected to the output of the ventilator before the tube)

Then, the user must indicate which mode they want to operate in (the tutorials give the user guidance on which mode to choose based on the conditions of the patient):
* Bi-PAP (patient is unconscious, cannot breathe on their own)
* C-PAP (patient is conscious but having difficulty breathing)
* Spontaneous (difficult is back to normal brething but sometimes skips a breath

The user must also enter the height, weight, age and sex of the patient for the machine to calculate some parameters. Moreover, the user can choose to have more manual control and enter a set pressure for the C-PAP mode or set low and high pressures (IPAP and EPAP) for the Bi-PAP mode.
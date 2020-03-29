# DIY-Ventialtor Mechanical Parts
This directory contains the CAD files of the parts that must be 3D-printed to make the ventilator, as well as the readily-available parts we used (and potential equivalent parts) to make the design below.
![Ventilator Design](https://github.com/cymourad/diy-ventilator/blob/master/mech/ventilator_design.jpeg "Ventilator Design")

## CAD Parts

### Humidifier Chamber
* This part takes the pressure regulator output as its input and outputs to the Y-piece that connects to the tube going to the patient.
![humidifer design](https://github.com/cymourad/diy-ventilator/blob/master/prototypes/third_iteration/humidifer_design.jpeg "Humidifer Design")
* TODO special instructions to print (material, orientation, printer settings )
* TODO a picture of it printed

### Oxygen Nozzle
* This part connects to the Oxyen regulator to lower the pressure to match the pressure of the airflow.
* TODO special instructions to print (material, orientation, printer settings )
* TODO a picture of it printed

## Readily Available Parts

### Arduino UNO Baord
* This is the brain if the ventilator, it controls the outputs and makes sense of the inputs. This is our controller.
* Can be purchased from [here](https://www.amazon.ca/ARDUINO-A000066-Uno-DIP-1-5/dp/B008GRTSV6).
* equivalent parts

### Arduino HM-10 Bluetooth Module
* This module connects to our microcontroller and it lets the user send the desired settings over bluetooth from their phone.
* Can be pruchased from[here](https://www.amazon.com/DSD-TECH-Bluetooth-iBeacon-Arduino/dp/B06WGZB2N4)
* equivalent parts

### Parker OEM-EP (Miniature Electronic Pressure Controller)
* This device takes any pressure greter than 40 cmH2O (can be variable pressure) and outputs a regulated pressure (10% - 100% of its input pressure.)
* Its data sheet can be found [here](https://www.parker.com/Literature/Precision%20Fluidics/Electronic%20Pressure%20Controllers/PPF_Pressure_Control_Catalog.pdf).
* equivalent parts

### Proximal Flow Sensor (Sensirion SFM3300-AW)
* This device reads the current flow rate. Two will be used, one to blend oxygen and air, and the other to monitor the exhaled tidal volume.
* Its data sheet can be found [here](https://www.sensirion.com/fileadmin/user_upload/customers/sensirion/Dokumente/5_Mass_Flow_Meters/Datasheets/Sensirion_Mass_Flow_Meters_SFM3300_Datasheet.pdf).

### Brushless DC Motor Blower
* This part is respoinsible for generating our airflow and high pressure for the pressure regulator.
* Can be prucahsed [here](https://www.alibaba.com/product-detail/12-24V-brushless-dc-motor-blower_60657146534.html?spm=a2700.7724857.normalList.2.37b52e3eF33iw2&s=p).

### Pressure and humidity sensor
* This device outputs the current temperature and relative humidity to the Arduino.
* Can be purchased [here](https://www.amazon.com/AZDelivery-Digital-Temperature-Humidity-Raspberry/dp/B07F86WXR7/ref=sr_1_3?keywords=dht22&qid=1585283973&sr=8-3).

### Tube and Mask
* These are standard tube and mask to connect to the patient.
* An example tube can be found [here]() and an example mas can be found [here]().

### Oxygen tank and oxygen regulator
* This is the source of Oxygen to regulate FiO2 higer than 21%. The regulator 
* These parts can be purchased or rented. They are standard parts so any combination should work. An example can be found [here]().

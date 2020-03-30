# DIY-Ventialtor Mechanical Parts
This directory contains the CAD files of the parts that must be 3D-printed to make the ventilator, as well as the readily-available parts we used (and potential equivalent parts) to make the design below.
![Ventilator Block Diagram Design](https://github.com/cymourad/diy-ventilator/blob/master/mech/block_diag.jpg "Ventilator Block Diagram")

## CAD Parts

### Humidifier Chamber
* This part takes the pressure regulator output as its input and outputs to the Y-piece that connects to the tube going to the patient.
![humidifer design](https://github.com/cymourad/diy-ventilator/blob/master/mech/new_humidifer_design.jpeg "Humidifer Design")
* TODO add special instructions to print (material, orientation, printer settings )
* TODO add a picture of it printed

### Oxygen Nozzle
* This part connects to the Oxyen regulator to lower the pressure to match the pressure of the airflow.
* TODO add special instructions to print (material, orientation, printer settings )
* TODO add a picture of it printed

## Readily Available Parts

### Arduino UNO Baord
* This is the brain if the ventilator, it controls the outputs and makes sense of the inputs. This is our controller.
* Can be purchased from [here](https://www.amazon.ca/ARDUINO-A000066-Uno-DIP-1-5/dp/B008GRTSV6).

### Arduino HM-10 Bluetooth Module
* This module connects to our microcontroller and it lets the user send the desired settings over bluetooth from their phone.
* Can be pruchased from[here](https://www.amazon.com/DSD-TECH-Bluetooth-iBeacon-Arduino/dp/B06WGZB2N4)

### Brushless DC Motor Blower
* This part is respoinsible for generating our airflow and high pressure for the pressure regulator.
* Can be prucahsed [here](https://www.alibaba.com/product-detail/12-24V-brushless-dc-motor-blower_60657146534.html?spm=a2700.7724857.normalList.2.37b52e3eF33iw2&s=p).

### Oxygen tank and oxygen regulator
* This is the source of Oxygen to regulate FiO2 higer than 21%. The regulator controls the pressure going out of the compressed oxygen tank to (typically) 3-5 bar. While
* These parts can be purchased or rented. They are standard parts so any combination should work. An example of the flow meter and regulator can be found [here](https://www.emrn.ca/en/respiratory/oxygen-regulators/o-two-oxygen-regulator-0-25-lpm-all-brass.html).

### Y-Piece
* This piece converges the airflow coming from the blower with the oxygen coming from the tank into one flow going to the proximal flow sensor (maybe it should be with non-return valves for each input stream to stay safe).
* Can be purchased [here](https://www.biodex.com/nuclear-medicine/products/lung-ventilation-systems/xenon-disposables/y-connector).

### Proximal Flow Sensor (Sensirion SFM3300-AW)
* This device reads the current flow rate. Two will be used, one to blend oxygen and air, and the other to monitor the exhaled tidal volume.
* Its data sheet can be found [here](https://www.sensirion.com/fileadmin/user_upload/customers/sensirion/Dokumente/5_Mass_Flow_Meters/Datasheets/Sensirion_Mass_Flow_Meters_SFM3300_Datasheet.pdf).

### Parker OEM-EP (Miniature Electronic Pressure Controller)
* This device takes any pressure greter than 40 cmH2O (can be variable pressure) and outputs a regulated pressure (10% - 100% of its input pressure.)
* Its data sheet can be found [here](https://www.parker.com/Literature/Precision%20Fluidics/Electronic%20Pressure%20Controllers/PPF_Pressure_Control_Catalog.pdf).

### Atomizer
* This small device floats on a water surface and atomizes tiny water dropplets to the air above to increase its humidity.
* Can be purchased [here](https://www.amazon.com/Gikfun-Ultrasonic-Ceramics-Sealing-Diffuser/dp/B075CHT2HY).

### Immersion heater
* Immersion heaters are commonly used to heat up water or coffe in a glass. So, we can use one to heat up the water and thus heat up to the air to reach 50 degress Celsius.
* Can be purchased [here](https://www.bedbathandbeyond.ca/store/product/portable-immersion-heater/1011091717?skuId=11091717&mrkgcl=610&mrkgadid=3281231058&mcid=PS_googlepla_nonbrand__&product_id=11091717CA&enginename=google&adpos=&creative=258866604705&device=c&matchtype=&network=g&utm_campaignid=71700000040549836&utm_adgroupid=58700004338901609&targetid=92700036666415279&gclid=Cj0KCQjwjoH0BRD6ARIsAEWO9DszFTlK9m6QqUaqluHM9tY8NCT2iUO5fvBEnReT12LD8P85y4bN1pEaAho5EALw_wcB&gclsrc=aw.ds).

### Pressure and humidity sensor
* This device outputs the current temperature and relative humidity to the Arduino.
* Can be purchased [here](https://www.amazon.com/AZDelivery-Digital-Temperature-Humidity-Raspberry/dp/B07F86WXR7/ref=sr_1_3?keywords=dht22&qid=1585283973&sr=8-3).

### Y-piece with non-return valve
* This piece conncects the air flow coming from the machine with the tube, and lets the air exhaled back from the patient exit from a third outlet.
* Can be purchased [here](https://www.biodex.com/nuclear-medicine/products/lung-ventilation-systems/xenon-disposables/y-connector).

### Tube and Mask
* These are standard tube and mask to connect to the patient.
* An example tube can be found [here](https://cpapmachinescanada.ca/products/resmed-standard-tube-6-feet-and-9-feet?variant=49938448967) and masks are determined [based on the patient's features](https://www.oxygenconcentratorstore.com/cpap-mask-sizing-guide-and-maintenance/#).



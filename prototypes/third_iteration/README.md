# DIY-Ventilator
We met again on March 28, 2020. 

## Humidifier
After studying humidifiers for the day, we learnt the following:
* there are two types of humidifiers: atomizers and heaters. Atomizers keep the temperature of the water the same and simply atomizes some water int dropplets in the air. A heater heats up the water till it evaporizes.
* temperature of air drops significantly across the tube. So industry either uses a tube that has a heater in it, or regulates the air temperature to 50 degress Celsius so that by the time it travels the standard length tube it arrives to the patient at 37 degress Celsius.

Upon some discussions around the trade-offs between accuracy, cost, availabilty of material and ease of making, we arrived to the following design.
![humidifer design](https://github.com/cymourad/diy-ventilator/blob/master/prototypes/third_iteration/humidifer_desin.jpeg "Humidifer Design")

An atomizer (like [this one](https://www.amazon.com/Gikfun-Ultrasonic-Ceramics-Sealing-Diffuser/dp/B075CHT2HY)) is primairly responsible for controlling the humidity level. An immersion heater (like [this one](https://www.walmart.ca/en/ip/Portable-Safe-Car-12V-24V-Immersion-Water-Heater-Auto-Electric-Tea-Coffee-Water-Heater/5EUK9APPV4YD)) is primairly responsible for heating the air to 50 degrees Celsius and it also heats up the water so it will affect the humidity slightly. A humidity and temperature sensor (like the [DHT22](https://www.amazon.com/AZDelivery-Digital-Temperature-Humidity-Raspberry/dp/B07F86WXR7/ref=sr_1_3?keywords=dht22&qid=1585283973&sr=8-3)) will provide feedback to adjust both the temperature and humidity.

## Blending Oxygen and Air
Upon his research, John generated the table below to adjust the flow rate coming out of the fan blower and the flow coming out of an oxygen tank to achieve the desired FiO2.
![Oxygen Blending Ratios Table](https://github.com/cymourad/diy-ventilator/blob/master/prototypes/third_iteration/oxygen_air_flow_ratios.jpeg "Oxygen Blending Ratios Table")

To simplify the design, the user interface can tell the user to adjust the oxygen flow and pressure regulator manually (like [this one](https://www.ocelco.com/store/pc/Regulator-for-Oxygen-Flowmeter-with-1-2-15-LPM-CGA-540-Nut-and-Nipple-Inlet-Connection-p6442.htm)). These regulators and flow meters usually come with a rented oxygen tank, and they follow standards so any tank and regulator that a user chooses should work with our design. As for the flow rate of the air, it can be 

The design would look as follows.
![Blender Design](https://github.com/cymourad/diy-ventilator/blob/master/prototypes/third_iteration/blender_design.jpeg "Blender Design")


On a seperate note, if we use a delta fan blower (like [this one](https://www.digikey.ca/product-detail/en/delta-electronics/ASB0312HA-AF00/603-1723-ND/3444171) for example), we can use its [PWM signal](https://www.delta-fan.com/NewsDetail.aspx?NID=71) to control its speed and thus its flow rate. This would also mean that we would have to design our own shell to boost the fan's pressure.

## Pressure Control
Upon inspecting the [datasheet of the pressure regulator](https://www.parker.com/Literature/Precision%20Fluidics/Electronic%20Pressure%20Controllers/PPF_Pressure_Control_Catalog.pdf), we learnt that it can output 10-100% of the pressure that is given to it. In other words, we must provide it 


[this burshless DC motor blower](https://www.alibaba.com/product-detail/12-24V-brushless-dc-motor-blower_60657146534.html?spm=a2700.7724857.normalList.2.37b52e3eF33iw2&s=p)
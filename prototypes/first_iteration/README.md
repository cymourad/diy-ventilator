# DIY-Ventialtor 1st Iteration
On March 21, 2020, Hany Zaki, Youssef Zaki, Youhanna Iskander, Nicolas Mourad and I dicussed a few ideas for a first design.

## Basic ventilator types
Hany explained to us that the early ventilators he worked with had three main modes which relate to the patient's condition:
1. **Bi-PAP**: patient is unconcscious and in very difficult condition, patiet cannot breathe on their own, Bi-PAP must artifically inhale (at Inspiratory Pressure, I-PAP) and exhale (at Expiratory Pressure, EPAP) at a set respiratory rate for the patient who exerts no resistance on the machine. This pressured air is often mixed with a hihger concentration of oxyen.
2. **C-PAP**: when the patient gets a little better and they become conscious and in control of their respiratory system again, the ventilator supplies constant pressured air (often mixed with oxygen).
3. **Patient-triggered**: the patient can fully brethe on thier own anf they are about to get weaned off the ventialtor but they sometimes miss a breath and/or they need a supply of oxygen, ventilator supplies pressured air at a low pressure (close to 4 cmH2O) and senses when the patient skips a breath, in which case it supplues a single IPAP cycle at the patient's average respiratory rate with their average tidal volume.

## Design principles
Common themes that we decided to kee through our design cycles were:
* break it to modules: break ventilator down to smaller standalone pieces (in case people do not need some functionalty or cannot find certain components AND for ease of testing)
* do not re-invent the wheel: use as many readily-available parts and technology as possible to increase reliability and to have online support community that can help with development and testing
* keep it simple: do not include functionality, features, or components that are not needed for most users (to minimize modes of failures and for ease of assembly and use)

## First design
We quickly came up with this first design, that was dismissed after for being a tad too complex.
![first design with pistons, cam-shaft, mixer chamber, and two pressure chambers](https://github.com/cymourad/diy-ventilator/blob/master/prototypes/first_iteration/first_design_pistons.jpeg "First Design with pistons and cam-shafts and mixer")
Starting from the right, a mixing chamber takes compressed air from a compressor and an oxyen tank or an oxyen concentrator. The FiO2 is controlled with a valve that connects the oxygen source to this mixing chamber.
Then, the air goes into a pressure chamber. A DC motor rotates a shaft and a cam that pushes a piston to compress the air in the pressure chamber and pushes it out to a valve that controls the pressure (and volume) of the air going out to the patient. Then, the valvev connects to a Y-piece that connects on one side to the tube and mask going out to the patient, and on the other side to a tube that contains a pressure sensor and connects to a pressure chamber that sucks the air back to simulate an exhale. The second pressure chamber is operated by the same DC motor and shat but a different sized cam.

## Second design
We examined the design and found some repition (compressing the air twice first with the compressor then with the piston, using two pressure chambers for inhale and exhale). Also, since the cam had a set size, it was difficult to provide two different pressures from one pressure chamber (IPAP and EPAP). So, we decided to come up with another idea and compare the two.
We decided to use a blower fan and a valve to compress the air instead of the pressure chambers. This simplified our desing quite a bit as seen in the sketch below.
![second design with blower fan and valve](https://github.com/cymourad/diy-ventilator/blob/master/prototypes/first_iteration/second_design_fan.jpeg "Second design with blower fan and valve")
Starting from the right, a DC motor runs a blowing fan into a chamber that connects to a valve. There are a few modules that are optional to add here: a Y-piece that can let oxygen in with a valve nad/or a humidifer. Whether these modules are connected or not, a Y-piece is then connected. The Y-piece ends with a tube and a mask. The other side of the Y-piece measures the pressure of the air exhaled out of the patient and passes it through a filter before goin back to the room. It is also an option to include a disinfection unit before letting the air out.
At this point we knew that we had three things to control, and this is how this design controls them:
* **Respiratpry rate**: timer set on valve to open and close
* **Tidal volume**: speed of DC motor
* **Pressure**: how much the valve closes

### Disinfection
Nicolas was looking into ways to disinfect the exhaled air. His conclusion was that the cheapest and easiest way is to pass the exhaled air over concentrated bleech before letting it back in the room. John added that filters should be incorporated at the end of that disinfection chamber before letting the air out to keep the PH level of the room.

### Power
We decided to use a DC motor because:
* it is readily-avaible, 
* it is easy to control its speed, 
* it is easy to run it on a battery, and
* it is relatively easiser to run on AC power with readily-avaible adapters for different systems.
Upon some internet research, it seems like we might be able to use a phone charger to power the arduino and potentially a power bank as the battery as well. It will def supply the needed voltage, the question is the current. Also, seems like some chargers might not have isolation or negotiate voltage with Arduino, so must give users instructions on how to make sure the charger they use works for the Arduino.

### Volume Control
Traditionally, the datasheet of a fan blower contains a table relating angular speed to volumetric flow rate. Once we know one of these relations, we can use the equation found [here](https://www.axair-fans.co.uk/news/applications/understanding-basic-fan-laws/) to find the new speed required for the desired volumetric flow rate (this desired volumetric flow rate can be calculated from the desied tidal volume, the size of the nozzle and the respiratory rate).
As for the volume of the exhaled air, it can be calculated using pressure sensors as shown [here](https://www.sensortips.com/featured/calculate-flow-pressure-measurement/).

### Pressure Control
The valve controls the pressure going to the patient by changing the diameter of the valve. [This calculator](http://irrigation.wsu.edu/Content/Calculators/Sprinkler/Nozzle-Requirements.php) helps build intuition towards the relationship between the diameter of the nozzle (valve in our case) and the new flow rate of the water (given the initial pressure of the fluid coming in from the fan blower).

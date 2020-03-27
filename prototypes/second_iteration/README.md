# DIY-Ventilator 2nd Iteration

Late at night on March 24, 2020, Hani, John and I had a conversation about the design. We came up with a few improvements:
* globe or butterfly valves seem like good options to control the pressure of the air and the FiO2 (they are rotary so they allow fast control, and they allow flow regulations (not just one/off))
* remembering to go back to the basics when it comes to controls, we need to now the tidal volume and the respiratory rate. Based on those 2 pieces of information we will know the volume of air that the blower must deliver. We also need to derive how long an inhale takes and how long an exhale takes (exhale takes longer) to know how often to change the pressure in Bi-PAP mode
* for Bi-PAP mode, instead of having one channel for the air and keep switching the position of the valve to change the pressure for PIP and PEEP, have a air blown by the fam split throug a y-piece that has two valves connected to its two outlets and a switch that controls which outlet the air goes to. This way, the regulating valves will only need to change their positions when settings chnage, and the switch will do the heavy lifting. This Y-piece then connect to another Y-piece to connect to the patient's tube. This would look like something similar to the picture below.
![third design with blower fan and 2 valves](https://github.com/cymourad/diy-ventilator/blob/master/prototypes/second_iteration/third_design_diverter.jpeg "Third design with blower fan and 2 valves")

Action list for our meeting on March 25, 2020:
* finalize design
* order parts and decide which parts will be designed in-house
* figure out the parameters needed to run in Bi-PAP and C-PAP modes (what we should ask the user to provide) and how to translate them into:
1. speed of fan blower, 
2. position of pressure valves, and 
3. delays when diverting flow between PIP and PEEP.

I think the diagram below might help us with this third task.
![main Bi-PAP ventilation controls](https://github.com/cymourad/diy-ventilator/blob/master/prototypes/second_iteration/main_controls.png "Main Bi-PAP Ventilation Controls")

We meet on March 25, 2020. We started by reviewing the new list of requirements one last time before changing our design and desciding what parts to buy and what parts to make. The new requirements explicitly ask for:
* the integration of a humidifier (to control humidity and air temperature), 
* the interation of an Oxygen blender (to control the FiO2),
* pressure controlled ventialtion (as opposed to volume controlled),
* A/C (Assited/Controlled breaths) modes of ventilation (a.k.a. patient-triggered vs machine-triggered ventilation), 
* monitoring of Vt (tidal volume), and
* alerts when max inhale and exhale pressures are exceeded, as well as a fail-safe method to limit the max pressure.


Those new requirements meant that the following inputs must be supplied by the user (and therefore the interface must allow the user to set them):
* PIP (Peak Inspiratory Pressure [cmH2O], 5 < PIP < 40)
* PEEP (Positive End of Exhalation Pressure [cmH2O], 4 < PEEP < 20)
* RR (Respiratory rate [breaths/minute] 4 < RR < 60)
* I:E Ratio (Ratio of Inhale to Exhale time)
* FiO2 (Perecentage of Oxygen in air [%], 20 < FiO2 < 100)
* Humidity (of air [units])
* Temperature (of air [degrees Celsius])

The machine must control:
* two pressures (PIP and PEEP),
* the intervals of switching between them,
* blending the air and Oxygen,
* humidity and temperature, and
* listening to the patient asing for a breath in patient-triggered mode.

Thus, the design we can come up with the night before seemed to satisfy the requirements. It seemed like blending should have happened before controlling the pressure and upon looking at literature it turned out that this new suggestion was true.

At this point, it was time to browse the internet to find:
* low pressure regulators (a.k.a. low pressure valves) --> for 0 to 50 cmH20 (which is 0 to 0.5 psi)
* flow meters
* oxygen blender
* fan blower
* simple humidifier

This 3 hour component search was eye-opening to say the least.
* Oxygen belnders turned out to cost somewhere between $1,000 and $2,000. Upon some literature reading, we came to the conclusion that the sweet spot of most cost effective and easy to build blender can be achieved if we just buy a flow regulator to hook up to the oxygen source, and buy a flow meter. Then, we connect those Oxygen source and the air coming out of the fan blower to a mixing chamber that we design and 3D print. When the user requests a certain FiO2, we ask them to turn the manual knob of the Oxygen flow regulator, and use the flow meter to regulate the speed of the fan blower to produce a flow of air that summed with the flow of Oxygen would result in the desired combination.
* Even though high pressure regulator are so widely available, it is considerbaly more dificult to find a low pressure regulator (for the range we are seeking to control). The next best option is a needle valve to regulate the flow (and use a pressure sensor and a feedback loop to adjust the valve to achieve desire pressure); but needle valves turned out to be not that much better in terms of avilability. Giving in to the $150 price range, we found that Parker sells a low pressure regulator that hits our desired pressure range with high accuracy and can switch between pressures fairly quickly. Thus, we decided that if $150 could give us fast switching between pressures (thus eliminatin the need for a diverter and two different channels) and precise pressure regulation (eliminating the need for two needle valves, two pressure sensors and two feedback control loops), a Parker pressure regulator (like [this one](https://www.parker.com/Literature/Precision%20Fluidics/Electronic%20Pressure%20Controllers/PPF_Pressure_Control_Catalog.pdf)) would be worth the price (especially given the time and resource constraints).
* We need a flow sensor to regulate the oxygen/air blending, and we need another one to monitor the actualy tidal valume from the exhale. Water flow meters/sensors are so widely avaibale. But, a lot of them are mechanical and thus useless to out controller, and the ones that are electronic are not suitable for air flow measurements. Instead, the type of flow sensor we are looking for is called a prximal flow sensor. An avergae prximal sensor (like [this one](https://www.sensirion.com/en/flow-sensors/proximal-flow-sensors/)) would cose around $300. 
* These parts are not usually found on Amazon or E-Bay. They even sometimes ask you to request a quote.

In light of these decisions, the final design has been modified to look as follows:
![final design](https://github.com/cymourad/diy-ventilator/blob/master/prototypes/second_iteration/final_design.jpeg "Final Design")


Final action plan:
* change interface (app) to prompt for the fina list of inputs,
* look at the data sheets of the parts we found and figure out who they will be integrated with the contoller,
* design the parts that will connect the bought parts together, and
* write the control algorithm.

### Humidifer
Arduino provides a few humidity and temperature sensors like the [DHT22](https://www.tutorialspoint.com/arduino/arduino_humidity_sensor.htm) which measures relative humidity and temperature. It as cheap as [$5](https://www.amazon.com/AZDelivery-Digital-Temperature-Humidity-Raspberry/dp/B07F86WXR7/ref=sr_1_3?keywords=dht22&qid=1585283973&sr=8-3) and it prvides reasonable accuracy for the application.
We could use one of those [mist makers](https://www.aliexpress.com/item/32986565997.html?src=google&src=google&albch=shopping&acnt=494-037-6276&isdl=y&slnk=&plac=&mtctp=&albbt=Google_7_shopping&aff_platform=google&aff_short_key=UneMJZVf&&albagn=888888&albcp=9309943343&albag=90987094781&trgt=296730740870&crea=en32986565997&netw=u&device=c&albpg=296730740870&albpd=en32986565997&gclid=Cj0KCQjwpfHzBRCiARIsAHHzyZq2tk2O9b_C5bZ24iYWOpBFKPeDzB2jphI0SbhkUgaNJtEAdyG6xQEaAu9TEALw_wcB&gclsrc=aw.ds) to vaporize water and increase humidity but if we do so we won't be able to control the temperature.
To heat the water, we can use a [commercial immersion heater](https://www.aliexpress.com/item/4000311044016.html?src=google&src=google&albch=shopping&acnt=494-037-6276&isdl=y&slnk=&plac=&mtctp=&albbt=Google_7_shopping&aff_platform=google&aff_short_key=UneMJZVf&&albagn=888888&albcp=7386552844&albag=80241711349&trgt=743612850714&crea=en4000311044016&netw=u&device=c&albpg=743612850714&albpd=en4000311044016&gclid=Cj0KCQjwpfHzBRCiARIsAHHzyZrjRCKICYG-yAlzy4qPAde6-GPtUT5aT-6TAv_bCtONP7gE_2nNKzkaAtIeEALw_wcB&gclsrc=aw.ds) and do some surgey one the wires to turn it ON/OFF with the Arduino.
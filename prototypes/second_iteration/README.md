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
3. delays between switching the flow traffic from
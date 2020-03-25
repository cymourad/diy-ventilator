# DIY-Ventilator Tests
These are some basic test cases to run the ventilator through once you assemble it and before you let a patient use it.
You can also run them whenever you want.
** All the tests assume that all the parts of the ventilator are assembled correctly.

## User Acceptance Tests

### User Acceptance Test 1
##### Settings
| Setting   | Configuration   |
|-----------|-----------------|
| Setting 1 | Configuration 1 |
| Setting 2 | Configuration 2 |
| Setting 3 | Configuration 3 |
##### Expected Ventilator Behavior
Describe what the behavior would look/sound like (ex:high noise, low noise, if you put your hand at the tube you would feel presure, etc).
Might also wanna explain when these settings would be applied (the condition of the patient that requires these settings), and maybe how these settings would help the patient.
##### How to Meausre the Success of the Test
Describe the sesnors/mechanisms needed to ensure the ventilator behaves as expected.

### User Acceptance Test 2
##### Settings
| Setting   | Configuration   |
|-----------|-----------------|
| Setting 1 | Configuration 1 |
| Setting 2 | Configuration 2 |
| Setting 3 | Configuration 3 |
##### Expected Ventilator Behavior
Describe what the behavior would look/sound like (ex:high noise, low noise, if you put your hand at the tube you would feel presure, etc).
Might also wanna explain when these settings would be applied (the condition of the patient that requires these settings), and maybe how these settings would help the patient.
##### How to Meausre the Success of the Test
Describe the sesnors/mechanisms needed to ensure the ventilator behaves as expected.

### User Acceptance Test 3
##### Settings
| Setting   | Configuration   |
|-----------|-----------------|
| Setting 1 | Configuration 1 |
| Setting 2 | Configuration 2 |
| Setting 3 | Configuration 3 |
##### Expected Ventilator Behavior
Describe what the behavior would look/sound like (ex:high noise, low noise, if you put your hand at the tube you would feel presure, etc).
Might also wanna explain when these settings would be applied (the condition of the patient that requires these settings), and maybe how these settings would help the patient.
##### How to Meausre the Success of the Test
Describe the sesnors/mechanisms needed to ensure the ventilator behaves as expected.

## Engineering Tests
The following tests were used when developing the machine and we encourage anyone who decides to fork this design to run them when they make modifications. We would also encourage all developers and health professionals to add other tests as they see fit, or reach out to us to add them.

### Engineering Test 1 - Min PIP and min PIP
##### Settings
| Setting   | Configuration   |
|-----------|-----------------|
| Mode | Bi-PAP |
| PIP | 10 cmH2O |
| PEEP | 4 cmH2O |
##### Expected Ventilator Behavior
The ventilator can supply the minimum inspiratory pressure and the minimum expiratory pressure.
##### How to Meausre the Success of the Test
Connect mask to pressure sensor to measure inspiratory pressure and use the sensor at the Y-piece to meausre the epiratory pressure.

### Engineering Test 2 - Max PIP and max PEEP
##### Settings
| Setting   | Configuration   |
|-----------|-----------------|
| Mode | Bi-PAP |
| PIP | 40 cmH2O |
| PEEP | 20 cmH2O |
##### Expected Ventilator Behavior
The ventilator can supply the maximum inspiratory pressure and the maximum expiratory pressure.
##### How to Meausre the Success of the Test
Connect mask to pressure sensor to measure inspiratory pressure and use the sensor at the Y-piece to meausre the epiratory pressure.

### Engineering Test 3 - Max PIP and min PEEP
##### Settings
| Setting   | Configuration   |
|-----------|-----------------|
| Mode | Bi-PAP |
| PIP | 40 cmH2O |
| PEEP | 4 cmH2O |
##### Expected Ventilator Behavior
The ventilator can supply the maximum inspiratory pressure and the minimum expiratory pressure.
##### How to Meausre the Success of the Test
Connect mask to pressure sensor to measure inspiratory pressure and use the sensor at the Y-piece to meausre the epiratory pressure.

### Engineering Test 4 - Min PIP and max PEEP
##### Settings
| Setting   | Configuration   |
|-----------|-----------------|
| Mode | Bi-PAP |
| PIP | 10 cmH2O |
| PEEP | 20 cmH2O |
##### Expected Ventilator Behavior
The ventilator cannot supply an inspiratory pressure that is higher than the expiratory pressure.
##### How to Meausre the Success of the Test
Ventilator errors out.

### Engineering Test 5 - Avergae Bi-PAP Pressures
##### Settings
| Setting   | Configuration   |
|-----------|-----------------|
| Mode | Bi-PAP |
| PIP | 20 cmH2O |
| PEEP | 8 cmH2O |
##### Expected Ventilator Behavior
The ventilator can supply an average inspiratory pressure and an average expiratory pressure.
##### How to Meausre the Success of the Test
Connect mask to pressure sensor to measure inspiratory pressure and use the sensor at the Y-piece to meausre the epiratory pressure.

### Engineering Test 6 - Max C-PAP Pressure
##### Settings
| Setting   | Configuration   |
|-----------|-----------------|
| Mode | C-PAP |
| Pressure | 40 cmH2O |
##### Expected Ventilator Behavior
The ventilator can supply the maximum pressure in C-PAP mode.
##### How to Meausre the Success of the Test
Connect mask to pressure sensor to measure inspiratory pressure.

### Engineering Test 7 - Min C-PAP Pressure
##### Settings
| Setting   | Configuration   |
|-----------|-----------------|
| Mode | C-PAP |
| Pressure | 6 cmH2O |
##### Expected Ventilator Behavior
The ventilator can supply the minimum pressure in C-PAP mode.
##### How to Meausre the Success of the Test
Connect mask to pressure sensor to measure inspiratory pressure.

### Engineering Test 8 - Above-max C-PAP Pressure Error
##### Settings
| Setting   | Configuration   |
|-----------|-----------------|
| Mode | C-PAP |
| Pressure | 50 cmH2O |
##### Expected Ventilator Behavior
The ventilator signals an error when requested to supply pressure that's higher than the approved average.
##### How to Meausre the Success of the Test
Connect mask to pressure sensor to measure inspiratory pressure, notthing should happen.

### Engineering Test 9 - Patient-effort Triggered
##### Settings
| Setting   | Configuration   |
|-----------|-----------------|
| Mode | Spontaneous |
##### Expected Ventilator Behavior
The ventilator recognizes a skipped breath and compensates for it with an inspiration that has the average respiratory rate, tidal volume, and inspiratory pressure of the patient over the past hour.
##### How to Meausre the Success of the Test
Connect mask to pressure sensor to measure inspiratory pressure.
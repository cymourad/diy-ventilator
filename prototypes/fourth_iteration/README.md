# DIY-Ventilator 4th Iteration
I video conferenced Nazmy today for around 7 hours. This man wrecked almost everything. It's late. There is so much to document. I'll capture the most important things as much as I can.

## Parker pressure regulator
We forgot to check its flow range. Some max out at 20 L/min, which is pretty low, so might need to find different models and a different part all togheter. Also, because it scales it input pressure 10% - 100%, we must provide it with 40-50 cmH2O to get our desired range. So, we gotta do some serious pressure reduction to go from 50 psi (~3515.35 cmH2O) to 50 cmH2O (~70x). We might need to do this reduction on two stages. But good news is: this is a fixed reduction so we can use mechanical valves with no control and they should be cheaper

## Tidal volume
A call with an anathtiliologist (def spelled that wrong) informed us that for COVID-19, the patient would need a Vt of 6 mL/kg (yieldning and avg Vt of 0.426 L). Aslo, avg person is around 71 kgs. So, to caculate our flow rate (Q) range:
> Q [L/min] = Vt / (inhale period)

## Oxygen blending
Nazmy made it clear that it is better to blend at a high pressure. It also became clear after some research that most belnders ($300 - $800) are designed for the 40-50 psi range, which is conviently the pressure coming out of an Oxygen tank.
Omitting much discussion, we decided that using a ready made blender and an air compressor might be the sweet spot between precision and safety vs cost. The final concern we had was running this compressor on a battery for 3 hours in case power goes out. Nazmy is looking into this tonight.
Meanwhile, Hani was looking into using the venturi principle instead on a standard compressor and belnder. We will design the venturi and some seious control logic with some regulaor solenoids. This design would be so much cheaper (but maybe harder for an average person to assemble). Main problem with this design is it must supply a minimum FiO2 of 40%.

## Humidifier
Also giving the summary of long dicussions here. Using a simple atomizer will not give us enough control over humidity. We generally want 55% humidity. I looked into HMEs because they seem easy and cheap. Nazmy is designing smth and we'll talk tomorrow.
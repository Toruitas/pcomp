# Week 6 labs
Msc Creative Computing
Physical Computing #6 w/ Phoenix Perry
By Stuart Leitch
November 4, 2019

[Lecture PowerPoint](https://github.com/phoenixperry/cci-ual-pcomp/blob/master/week06/week06.pdf)

## Lab #1: Simple synths
This lab was meant to explore capacitors and resistors and their interplay. To do so, we were provided with a lab bag which included a speaker, a trio of different polarized and unpolarized capacitors, a photoresistor, a resistor, a 9V battery, an oscillator, and finally a dial/potentiometer. 

The fancy version of what we were building lives here: https://www.youtube.com/watch?v=t7JYOIYqMEY

The more beginner-friendly version for our circuit is derived from this video: https://www.youtube.com/watch?v=EmoF-sdWOCc 

### The gear
![The gear](https://github.com/Toruitas/pcomp/blob/master/wk6/0_gear.JPG)

The project had a video tutorial but included no schematic or diagram. As a result, we probably incremented the viewcount of the second video by about 20 just so we could verify we had our circuit engineered correctly.

### The original circuit
![The original circuit](https://github.com/Toruitas/pcomp/blob/master/wk6/1_original_setup.JPG)

### Plugged in
![Plugged in](https://github.com/Toruitas/pcomp/blob/master/wk6/2_plugged_in.JPG)

Cue an hour+ of frustration. We didn't have the right oscillator. Can't make a synthisizer without an oscillator.

### The wrong chip
![The wrong chip](https://github.com/Toruitas/pcomp/blob/master/wk6/3_bad_chip.JPG)

Eventually, our dear leader realized that we all had the wrong one, and we all replaced it within our circuits.

Immediately, our circuit worked. At least we had it wired correctly. 

### The right chip
[![Physical Computing - Wk6 - Lab 1a](https://github.com/Toruitas/pcomp/blob/master/wk6/4_good_touch.JPG)](https://youtu.be/coa9hnEuwyY "Physical Computing - Wk6 - Lab 1a")

With this, we could increase/decrease the resistance by using the photoresistor. This would in turn increase/decrease the frequency within the pitch range given by the capacitor.

### Further experimantation

Vino and I decided to try to add to the circuit, but keep using the same oscillator. After all, it still had plenty of "ports" available for use, so no need to get a second one. We used one of the polarized caps and added the pot. 

[![Physical Computing - Wk6 - Lab 1b](https://github.com/Toruitas/pcomp/blob/master/wk6/5a_with_dial_works.JPG)](https://youtu.be/Kl1jHvoML2A "Physical Computing - Wk6 - Lab 1b")

It might be from hearing damage over the prior few hours (or years of shows) but I can't determine whether it's significantly higher or lower pitched at the baseline. It sounds like it's just louder or quieter, which shouldn't be determined by our input on this end, but by the controls on the speaker itself. 

### Key lesson #1: Inspect your hardware and don't use the wrong things.
### Key lesson #2: Make sure polarized caps are facing the right way, otherwise, they'll become popcaps. 
### Key lesson #3: Capacitors are very useful at smoothing dips in voltage. 
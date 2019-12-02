# Week 7 labs
Msc Creative Computing
Physical Computing #6 w/ Phoenix Perry
By Stuart Leitch
November 11, 2019

[Lecture PowerPoint](https://github.com/phoenixperry/cci-ual-pcomp/blob/master/week07/week07.pdf)

## Lab #1: Shift Registers

Shift registers are magical. They allow you to read or write bits to the shift register and thus let us use 1 pin to control 8 things. Magic!

When shifting bits in from the right, the bits on the left will fall off. Inverse for shifting from the left. As a result, the standard operating procedure is to write an entire byte (8-bits) at a time. 

We also covered some forms of binary operators, & (and) | (or) ^ (xor)

![Bit chart](https://github.com/Toruitas/pcomp/blob/master/wk7/0_bit_chart.JPG)

On the shift registers we were provided, Vcc is power and Gnd is ground. 
Q0-Q7 are the eight output pins. Q7 gets rolled out. 
DS is the pin that receives bits.
SH_CP is the clock pin. HIGH when we're putting bits in.
ST_CP is the latch pin. LOW when bits go in. HIGH when done putting bits in as serial data from the Ard. This says the bits are in place, let's send to the output pins. Output pins don't do anything until this is HIGH.
OE is Output Enabled pin. When it is connected to ground (and maybe any LOW), output is disabled. When set to HIGH it shows that the register is set to send output as serial data over the pin to the Ard.

This excerpt from [Adafruit](https://learn.adafruit.com/adafruit-arduino-lesson-4-eight-leds/the-74hc595-shift-register) is particularly useful:

![Shift Register](https://github.com/Toruitas/pcomp/blob/master/wk7/0a_shift_register.png)

The shift register holds what can be thought of as eight memory locations, each of which can be a 1 or a 0.

To set each of these values on or off, we feed in the data using the 'Data' and 'Clock' pins of the chip.

The clock pin needs to receive eight pulses. At the time of each pulse, if the data pin is high, then a 1 gets pushed into the shift register. Otherwise, it is a 0. When all eight pulses have been received, then enabling the 'Latch' pin copies those eight values to the latch register. This is necessary, otherwise the wrong LEDs would flicker as the data was being loaded into the shift register.

The chip also has an OE (output enable) pin, this is used to enable or disable the outputs all at once. You could attach this to a PWM capable Arduino pin and use 'analogWrite' to control the brightness of the LEDs. This pin is active low, so we tie it to GND.

As is this video: [Sparkfun Shift Registers](https://youtu.be/6BLj9Ak2Djs)

### The lab's task was to go through these tutorials: 
https://learn.adafruit.com/adafruit-arduino-lesson-4-eight-leds/overview
http://www.cs.uregina.ca/Links/class-info/207/Lab8/

### The Shift register
![Bit chart](https://github.com/Toruitas/pcomp/blob/master/wk7/1_shifter.JPG)

The hardest part of the lab was actually fitting all the LEDs and resistors on the board at the same time. Did get it figured out with a bit of cleverly rotated resistors. Both links have the same wiring so I consider it one lab.

I really likes how we could simply connect the Output Enable pin to an Analog pin and use analogWrite to control brightness. Nifty nifty.

[![Physical Computing - Wk7 - Lab 1](https://github.com/Toruitas/pcomp/blob/master/wk7/2a_shifter_leds.JPG)](https://youtu.be/0mb_N0TKfp4  "Physical Computing - Wk7 - Lab 1")


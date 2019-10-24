# Week 4 labs
Msc Creative Computing
Physical Computing #4 w/ Phoenix Perry
By Stuart Leitch
October 21, 2019


## Lab 1 - Project proposal
Fill out final project proposal form.
Final project description here: https://github.com/phoenixperry/cci-ual-pcomp/blob/master/final_project.md


## Lab 2 - Hook up a servo
Goal: Follow this tutorial in hooking up a servo: https://www.instructables.com/id/Arduino-Servo-Motors/

Servos work when hooked up to a digital pin. Using a simple circuit with power, one digital pin, and ground, we can control the position of the servo through use of `servo.write(number)`. Easy. In this particular servo, the digital control pin is NOT in the middle.

Don't forget to `#include <Servo.h> ` and install the library if necessary.

Servos in theory have up to 180 degrees of movement range, but in reality the cheap ones won't quite reach that and will max out a few degrees short. To confirm this maximum we altered the supplied example code and set it to a value > 180: `Servo1.write(270);` and saw that it indeed doesn't go beyond 180. 

Behind the scenes, the servo receives an input from the Arduino consisting of a square wave. The wavelength / pulse width of the square wave is interpreted as a position for the servo to go to. 

Click to view video.
[![Physical Computing - Wk4 - Lab 2](https://github.com/Toruitas/pcomp/blob/master/wk4/lab2a.JPG)](https://youtu.be/rQGDW6hsgyk  "Physical Computing - Wk4 - Lab 2")

Close-up on the servo hookup:
![Servo hookup](https://github.com/Toruitas/pcomp/wk4/blob/master/lab2b.JPG)


## Lab 3 - Hook up a motor
Goal: Understand how a motor works by working through Project 9 of the Arduino Projects book. Make a spinner. 

Motors are kind of miraculous. Using a magnetic field to spin some other metal? Magic!

The presence of the magnetic field requires we take special care to not let it damage our circuit. By using a polarised diode, we can prevent the current from going the wrong way after the motor turns off but is still spinning, as the voltage the still-spinning motor generates is in the opposite direction of the normal voltage. When voltage is supplied to a motor, the motor spins. When the motor spins on its own, think power generation, the motor itself generates voltage. 

Key note: Put the diode in reverse of the regular "flow" of the current. It's meant to block the reverse current, but not the normal current. Or put another way: The diode must be in parallel w/ the motor. We want the reverse current (back voltage) to flow through the diode. 

Key note #2: Additional power (battery) has to have ground connected to same ground as the rest of the circuit. 

Key note #3: Electron current flow is from - to +. Conventional is + to -, but this is inaccurate. Unfortunately the schematics use the inaccurate flow representation. But some component parts are named according to the accurate model. Transistor drain and source, for example. Source is connected to ground, which is in fact where electrons come from.

No wonder it's confusing.

As long as we are using lowish voltage our computers will have diodes inside able to handle the current that comes in, but if we are using a Raspberry Pi, it doesn't have any sort of protection. Definitely a must-use.

The lab diagram and schematic:
![Lab 3 diagram](https://github.com/Toruitas/pcomp/wk4/blob/master/lab3a.JPG)

This was not straightforward. We use a transistor hooked up to the button to control the high voltage source of the 9v battery. When the button is pressed, the gate of the transistor gets voltage, connecting the motor on the drain pin and the ground on the source pin. It gives the motor its path to ground. This turns it on.

The diode is connected as such:
Cathode (-): power of motor
Anode   (+): ground of motor

When the motor turns off, the flow reverses but the diode stops it from going through the circuit.

The completed product:
![Lab 3 pic](https://github.com/Toruitas/pcomp/wk4/blob/master/lab3b.JPG)

After finishing all of the labs, we went back and upgraded this motor circuit, to vary the amount of voltage the motor gets with two buttons. One button adds voltage, making the motor move faster. One button reduces, slowing it down. It's an accelerator and decelerator, essentially.

Source: https://www.jianshu.com/p/076e6b4c6590

The upgraded lab diagram:
![Lab 3a diagram](https://github.com/Toruitas/pcomp/wk4/blob/master/lab3c.JPG)

Click to view video.
[![Physical Computing - Wk4 - Lab 3](https://github.com/Toruitas/pcomp/blob/master/wk4/lab3d.JPG)](https://youtu.be/xVed3GcLTaA "Physical Computing - Wk4 - Lab 3")


## Lab 4 - Hook up an MPR121
Goal: Use a capacitave touch sensor with the Arduino
Reference: [Adafruit tutorial](https://learn.adafruit.com/adafruit-mpr121-12-key-capacitive-touch-sensor-breakout-tutorial/overview)

This at first seemed easy. After all, that's why the little chip was developed. To make it easier. 

Then proved difficult because the SCL and SCD pins are different on the Leonardo vs the Uno, so the reference photos are wrong.

Once we read the docs, we learned that digital 3 can be used as SCL, and digital 2 as SDA. Later, after we got the circuit working, we learned that there're specific SCL and SDA pins as well.

The device sensitivity is quite good.

The results:
![Lab 4 diagram](https://github.com/Toruitas/pcomp/wk4/blob/master/lab4c.JPG)

The completed device: 
Click to view video.
[![Physical Computing - Wk4 - Lab 4](https://github.com/Toruitas/pcomp/blob/master/wk4/lab4b.JPG)](https://youtu.be/4s9D7VuA5Qg "Physical Computing - Wk4 - Lab 4")


## Lab 5 - The Capsense library
Goal: Explore how humans conduct electricity, evidently. But really to make a touch sensor.

Reference: [Arduino playground Capacitive Sensing Library](https://playground.arduino.cc/Main/CapacitiveSensor/)

Initial Hurdles:
1) Installing the right library
2) No diagram or schematic to refer to when building the circuit
3) Not enough resistors to fully complete the example. 

Since the pack we were given only had one pair of resistors, we only did one sensor.

Installing the library was easier by going through the Arduino IDE library manager. Thankfully the newer version was included there.

It took us some time to figure out how the thing worked. Originally we had been using the adhesive back to put the metal tape on a card. However that seems to have impacted the sensitivity of the readings, since we got weird results until we just cut out a new bit of tape and used that. 

Taped card:
![Taped card](https://github.com/Toruitas/pcomp/wk4/blob/master/lab5a.JPG)

Click to view video of base version of the lab:
[![Physical Computing - Wk4 - Lab 5a](https://i9.ytimg.com/vi/rA1zn3ueJZA/mq1.jpg?sqp=CI-Yx-0F&rs=AOn4CLA4wvdAaT88k3bm-mNpn7oRDcFEAg)](https://youtu.be/rA1zn3ueJZA  "Physical Computing - Wk4 - Lab 5a")

Then we wanted to make it a bit more interesting. We added an output pin to an LED and turned it on or off based on the readings from the capacitive sensor.

[![Physical Computing - Wk4 - Lab 5b](https://github.com/Toruitas/pcomp/blob/master/wk4/lab5b.JPG)](https://youtu.be/3oSSPZAJ4Ik "Physical Computing - Wk4 - Lab 5b")
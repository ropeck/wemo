# wemo

Control wemo switches with a photon internet button

## IOT Deskside Switch

Just for fun, I've set up some wemo switches and lights around the house
recently.  They come with a free app that lets you set a schedule and
controll them with your phone.  

Using IFTTT, you can make the lights change state from an outside event
or send a trigger to make something happen when a switch is pressed.

## Nighttime

The new lights are set to turn on a half hour before sunset, so it's hard
to even notice they are there.  It works great but for bed time, running the
app from the phone is just a little frustrating at the end of a long day.
(Such difficult problems!)

To help switch off the living room and bedroom lights simply, and to play
with IOT and the wemo lights, I wrote this project.  It uses an internet
button flashed with this code to make a big pushbutton that sends wemo
codes to turn off the lights.

You can do the same thing using IFTTT and a published message from the
button, but it takes a few seconds for the signal to be detected and relayed
to the lights.  This code uses SOAP and TCP on the local network controling
the wemo devices directly.  The lights change state instantly when the
button is pressed.

## Bright Lights
  The button is nice on the nightstand, but it has bright LEDs that are
distracting when trying to sleep in a dark room. 

Fortunately the code to dim the led is simple enough.
How to dim D7 but not sense it as a button is TBD.

  
## Shake to Turn On

IF you accidentally turn off the lights, it's nice to be able to turn them
on again.  I thought about making a long press or double click detection,
or maybe use the directional buttons in some way.  Then I realized the
internet button has an acceleratometer too.  Using that device, you can
measure if the button is tilted accurately.  You can also tell if it's been
shaken.

The code looks at the measurements in each loop and if the difference is
too high, it sends the turn on codes to the wemo lights.


# Materials
  * internet button
  * wemo switches

# Installation
The button photon is updated with the particle cli or web ide using the code in the src directory.

```

% particle flash buttonname

```


# Future
TODO: 

  * Scan for devices
  * Alarm or blinky lights
  * Fix D7 light
  * setup mode
    * select which devices by pressing the buttons and choosing
    * maybe have a web server for setup mode to choose devices
  * refactor the code for a wemo and button library
  * long press, double click
  * turn on LR only -- long click? 
  
## Sunrise Alarm
  Slowly turn on the leds in the morning to wake up.  Then turn off when pressed.
  
## Clock Display
  Show the time of day on the leds on the button.
  


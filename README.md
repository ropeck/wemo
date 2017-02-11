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

# Materials
  * internet button
  * wemo switches

# Installation
The button photon is updated with the particle cli or web ide using the code in the src directory.

```

% particle flash buttonname

```


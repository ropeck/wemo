Internet button ifttt power control

https://community.particle.io/t/beginner-tutorial-ifttt-publish-an-event-spark-internet-button/10270

http://makezine.com/2015/06/26/ifttt-adds-new-channel-makers/

http://www.howtogeek.com/249801/how-to-control-your-belkin-wemo-switch-from-the-home-screen/

https://community.lifx.com/t/lightsd-a-daemon-with-a-json-rpc-api-to-control-your-bulbs/446/56

https://community.particle.io/t/disable-pulsing-cyan/14032/8

Works well with the LED dimmed, but the D7 led is still lit.  If its set off, the button sensor sees it and sends messages continuously


Direct control of wemo lights
https://community.particle.io/t/directly-control-wemo-switches-arduino-2-photon-code/21055

Used this python code to list the devices on the network -- then used those addresses with the button
https://pypi.python.org/pypi/ouimeaux

https://medium.com/@SnowShoeStamp/wemo-hacking-with-the-snowshoe-stamp-4bcd1ceaeb27#.3uzzc3w66

https://github.com/ExistentialEnso/WeMo-PHP-Toolkit

http://apcmag.com/control-a-wemoh-with-arduino.htm/

http://www.instructables.com/id/Control-WeMo-Switch-with-ArduinoEthernet-shield/

http://wiznetmuseum.com/portfolio-items/control-a-wemo-switch-with-arduino/

https://docs.particle.io/reference/firmware/photon/#tcpclient

http://mattenoble.com/2013/08/07/wemo-hacking/


## Alarm Clock Notes
http://www.makeuseof.com/tag/arduino-night-light-and-sunrise-alarm-project/

```c++

void sunrisealarm(){
   //each second during the 30 minite period should increase the colour value by:
  float increment = (float) 255/(30*60);

  //red 255 , green 255 gives us full brightness yellow  
  if(currentMinutes >= minutesUntilSunrise){
     //sunrise begins! 
     float currentVal = (float)((currentMillis/1000) - (minutesUntilSunrise*60)) * increment;
     Serial.print("Current value for sunrise:");
     Serial.println(currentVal);
     //during ramp up, write the current value of minutes X brightness increment
     if(currentVal < 255){
       analogWrite(RED,currentVal);
       analogWrite(GREEN,currentVal);
     }
     else if(currentMinutes - minutesUntilSunrise < 40){
       // once we're at full brightness, keep the lights on for 10 minutes longer
       analogWrite(RED,255);
       analogWrite(GREEN,255);
     }
     else{
        //after that, we're nuking them back to off state
        analogWrite(RED,0);
        analogWrite(GREEN,0);
      }
  }
}

```



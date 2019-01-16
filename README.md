# 74HC165-ESP8266
Example of using the 74HC165 Shift Register within the ESP8266 Arduino Environment.

## Hardware
Example performed using a NodeMCU v 1.0 ESP-12 variant. It should work with other ESP8266 hardware with changes to the gpios.

## Arduino IDE
Development environment used arduino-1.8.6-windows with the esp8266-Arduino-2.5.0-beta2 board extention installed.

## Code (Sketches)
There are two different code sketches. One that uses the ShiftIn() function (bitbang) and the other that uses the esp8266's hspi (hardware) interface. The hspi is far faster and should be the perfered method. But, where spi isn't available or used for another purpose (sdcard) the bitbang method is still very good (160MHz) and useable. Additionally, there is an example to demonstrate hardware driven interrupt. I personally feel with the speed available polling the register with every loop or using a software interrupt or even a millis() variable and then comparing the last read with the current read to determin if a button was pressed works best ... eliminating the need for the extra gpio. However, I includ it as a demostration of using SPI & hardware interrupts ...

## Schematic & Pinout
<div align="center">
<img width="20%" height="20%" src="https://raw.github.com/sfranzyshen/74HC165-ESP8266/master/Pinout.png"><img width="50%" height="50%" src="https://raw.github.com/sfranzyshen/74HC165-ESP8266/master/Schematics.png">
</div>
## Schematic Hardware Interrupt
<div align="center">
<img width="50%" height="50%" src="https://raw.github.com/sfranzyshen/74HC165-ESP8266/master/Schematics-interrupt.png">
</div>
## References
- [Multiple inputs - Parallel to Series](https://jpralves.net/post/2015/09/08/multiple-inputs-parallel-to-series.html)
- [Shift register hacks](http://www.openmusiclabs.com/learning/digital/input-matrix-scanning/hacks/)
- [SN74HC165N Arduino Playground](http://playground.arduino.cc/Code/ShiftRegSN74HC165N)
- [Using a 74HC165 input shift register](http://www.gammon.com.au/forum/?id=11979)
- [74HC165 8 BIT PARALLEL IN/SERIAL OUT SHIFT REGISTER](https://iamzxlee.wordpress.com/2014/05/13/74hc165-8-bit-parallel-inserial-out-shift-register/)

/*

/*
 * ESP32 Servo Example Using Arduino ESP32 Servo Library
 * John K. Bennett
 * March, 2017
 * 
 * This sketch uses the Arduino ESP32 Servo Library to sweep 4 servos in sequence.
 * 
 * Different servos require different pulse widths to vary servo angle, but the range is 
 * an approximately 500-2500 microsecond pulse every 20ms (50Hz). In general, hobbyist servos
 * sweep 180 degrees, so the lowest number in the published range for a particular servo
 * represents an angle of 0 degrees, the middle of the range represents 90 degrees, and the top
 * of the range represents 180 degrees. So for example, if the range is 1000us to 2000us,
 * 1000us would equal an angle of 0, 1500us would equal 90 degrees, and 2000us would equal 1800
 * degrees.
 * 
 * Circuit:
 * Servo motors have three wires: power, ground, and signal. The power wire is typically red,
 * the ground wire is typically black or brown, and the signal wire is typically yellow,
 * orange or white. Since the ESP32 can supply limited current at only 3.3V, and servos draw
 * considerable power, we will connect servo power to the VBat pin of the ESP32 (located
 * near the USB connector). THIS IS ONLY APPROPRIATE FOR SMALL SERVOS. 
 * 
 * We could also connect servo power to a separate external
 * power source (as long as we connect all of the grounds (ESP32, servo, and external power).
 * In this example, we just connect ESP32 ground to servo ground. The servo signal pins
 * connect to any available GPIO pins on the ESP32 (in this example, we use pins
 * 22, 19, 23, & 18).
 * 
 * In this example, we assume four Tower Pro SG90 small servos.
 * The published min and max for this servo are 500 and 2400, respectively.
 * These values actually drive the servos a little past 0 and 180, so
 * if you are particular, adjust the min and max values to match your needs.
 * Experimentally, 550 and 2350 are pretty close to 0 and 180.
 

#include <ESP32Servo.h>

// create four servo objects 
Servo servo1;
// Published values for SG90 servos; adjust if needed
int minUs = 500;
int maxUs = 2400;

// These are all GPIO pins on the ESP32
// Recommended pins include 2,4,12-19,21-23,25-27,32-33
// for the ESP32-S2 the GPIO pins are 1-21,26,33-42
int servo1Pin = 15;

int pos = 0;      // position in degrees
ESP32PWM pwm;
void setup() {
	Serial.begin(115200);
	servo1.setPeriodHertz(50);

}

void loop() {
	servo1.attach(servo1Pin, minUs, maxUs);
  
  servo1.write(0);
  delay(2000);

  servo1.write(92);
  delay(2000);

  servo1.write(184);
  delay(2000);
}
*/
/*

  HelloWorld.ino

  Universal 8bit Graphics Library (https://github.com/olikraus/u8g2/)

  Copyright (c) 2016, olikraus@gmail.com
  All rights reserved.

  Redistribution and use in source and binary forms, with or without modification, 
  are permitted provided that the following conditions are met:

  * Redistributions of source code must retain the above copyright notice, this list 
    of conditions and the following disclaimer.
    
  * Redistributions in binary form must reproduce the above copyright notice, this 
    list of conditions and the following disclaimer in the documentation and/or other 
    materials provided with the distribution.

  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND 
  CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, 
  INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF 
  MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE 
  DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR 
  CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, 
  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT 
  NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; 
  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER 
  CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, 
  STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) 
  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF 
  ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  
  
  27 Oct 2018:
  
  U8G2_SSD1306_128X64_NONAME_1_4W_HW_SPI u8g2
  make -f Makefile.184.uno
  
   text	   
   8732	    					default, all active
   8500	    -232	    -2.65%		no U8G2_WITH_CLIP_WINDOW_SUPPORT
   8316	    -416	    -4.76%		no U8G2_WITH_FONT_ROTATION
   8606	    -126	    -1.44%	 	no U8G2_WITH_UNICODE
   8692	    -40	    -0.45%		no U8G2_WITH_INTERSECTION
   8328	    -404	    -4.62%	  	no U8G2_WITH_INTERSECTION  no U8G2_WITH_CLIP_WINDOW_SUPPORT
   8718	    -14	    -4.86%		no U8G2_WITH_HVLINE_SPEED_OPTIMIZATION
   8026	    -706	    -8.08%		no U8G2_WITH_FONT_ROTATION   no U8G2_WITH_INTERSECTION  no U8G2_WITH_CLIP_WINDOW_SUPPORT
   
   Some flags depend on each other: `U8G2_WITH_INTERSECTION` is required for `U8G2_WITH_CLIP_WINDOW_SUPPORT`, so `U8G2_WITH_INTERSECTION` is partly active as long
   as `U8G2_WITH_CLIP_WINDOW_SUPPORT` is requested.
   
*/

#include <Arduino.h>
#include <U8g2lib.h>

U8G2_SSD1306_128X64_NONAME_1_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE, /* clock=*/ 21, /* data=*/ 22);   // ESP32 Thing, HW I2C with pin remapping
int val = 0;
void setup(void) {
  u8g2.begin();
  
}

void loop(void) {
  u8g2.firstPage();
  do {
    u8g2.setFont(u8g2_font_ncenB10_tr);
    //u8g2.drawStr(0,24,"Hello World!");
    u8g2.setCursor(0, 15);
    u8g2.print(val);
  } while ( u8g2.nextPage() );
  delay(200);
  val++;

}

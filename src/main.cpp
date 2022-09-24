#include <ESP32Servo.h>
#include <Arduino.h>
#include <U8g2lib.h>

U8G2_SSD1306_128X64_NONAME_1_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE, /* clock=*/ 21, /* data=*/ 22);   // ESP32 Thing, HW I2C with pin remapping

Servo servo1;
int servo1Pin = 15;
int minUs = 500;
int maxUs = 2400;
int vel = 89;
ESP32PWM pwm;

void setup() {
  u8g2.begin();
	servo1.setPeriodHertz(50);
  servo1.attach(servo1Pin, minUs, maxUs);
}

void loop() {
	servo1.write(vel);
  u8g2.firstPage();
  do {
    u8g2.setFont(u8g2_font_ncenB10_tr);
    //u8g2.drawStr(0,24,"Hello World!");
    u8g2.setCursor(0, 15);
    u8g2.print("velocidad: ");
    u8g2.setCursor(80, 15);
    u8g2.print(vel);
  } while ( u8g2.nextPage() );
  vel = vel+1; 
  if (vel>=96){
    vel=89;
  }
  delay(3000);
}
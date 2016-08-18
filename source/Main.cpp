/*
WINTER WORDERLAND
Dancing Lady Software

Distributed under the MIT Licence - https://opensource.org/licenses/MIT
Copyright (c) 2016 Evan Morgan

*/

#include "MicroBit.h"
#include "ubit-neopixel/uBit_neopixel.h"

// neopixel settings
uint8_t pin_num = 2;
uint8_t leds_per_strip = 24;
uint8_t errors;
uint8_t red = 0;
uint8_t green = 0;
uint8_t blue = 0;
uint8_t pulseBr [24] = {88,97,10,72,10,62,2,29,79,2,62,43,37,48,90,9,45,1,36,73,64,17,73,38};
int8_t pulseStep [24] = {-2,5,-3,-4,3,-2,3,-5,-3,0,-2,3,5,3,-5,-1,-3,2,0,-2,3,-1,-5,1};
//
int raw = 0; // raw acceleromter value
float br = 0; // brightness multiplier
float mini [9] = {995000.0,995000.0,995000.0,1070000.0,1070000.0,1070000.0,1125000.0,1125000.0,1125000.0}; // mimiumum acceleration to trigger light
float maxi [9] = {1050000.0,1100000.0,1200000.0,1100000.0,1200000.0,1300000.0,1150000.0,1300000.0,1450000.0}; // maximum acceleration
int sens = 0; // user selected sensitivity
int ramp = 100; // ramp increment
int value = (int) mini[0]; // value to
int timer = 0;
int thresh = 50;
const char version [] = "v1.0";

neopixel_strip_t m_strip;
MicroBitI2C i2c = MicroBitI2C(I2C_SDA0, I2C_SCL0);
MicroBitAccelerometer accelerometer = MicroBitAccelerometer(i2c);
MicroBitDisplay display;
MicroBitButton buttonA(MICROBIT_PIN_BUTTON_A, MICROBIT_ID_BUTTON_A);
Serial pc(USBTX,USBRX);  //serial usb config

void startupSeq()
{
    display.scrollAsync(version);
    int reds [3] = {255,0,0};
    int greens [3] = {0,255,0};
    int blues [3] = {0,0,255};
    for (int k = 0; k<3; k++) {
        for (int j =0; j<leds_per_strip; j++) {
            errors = neopixel_set_color(&m_strip, j, reds[k], greens[k], blues[k]);
        }
        neopixel_show(&m_strip);
        wait(1);
    }
    display.clear();
}

int getRaw()
{
    int x = accelerometer.getX();
    int y = accelerometer.getY();
    int z = accelerometer.getZ();
    int sumSq = (int)x*(int)x + (int)y*(int)y + (int)z*(int)z;
    return sumSq;
}

void checkButtonA()
{
    if(buttonA.isPressed()) {
        sens +=1;
        if (sens > 8)
            sens = 0;
        display.print(sens,400);
        wait(1);
        display.clear();
    }
}



int main()
{
    accelerometer.configure();
    accelerometer.setPeriod(100);
    neopixel_init(&m_strip, pin_num, leds_per_strip);
    neopixel_clear(&m_strip);
    startupSeq();


    while(1) {
        checkButtonA();
        raw = getRaw();

        if (raw <= mini[sens] & timer >0)
            timer -= 5;
        else if (timer < 10*thresh)
            timer ++;

        if (value< raw & value <maxi[sens] & timer >thresh) { //if (value< raw & value <maxi[sens] & timer >thresh)
            value+=ramp;
        } else if (value > raw) //else if ((timer < thresh | value > raw) & value > 0)
            value -= ramp;

        br = ((float) value - mini[sens])/(maxi[sens]-mini[sens]);
        //pc.printf("Accel = %d        Value = %d         BR = %d\r\n",raw, value, (int) (br*1000.0));
        //wait(0.5);
        if (br > 1)
            br = 1;
        else if (br < 0)
            br = 0;



        for (int j =0; j<leds_per_strip; j++) {
            pulseBr[j] = pulseBr[j]+pulseStep[j];
            if (pulseBr[j] <= 0 & pulseStep[j] < 0) {
                pulseStep[j] *= -1; // switch direction of fade
                pulseBr[j] = 0;
            } else if (pulseBr[j] >= 100 & pulseStep[j] > 0) {
                pulseStep[j] *= -1; // switch direction of fade
                pulseBr[j] = 100;
            }
            red = (int)(255.0*br);
            green = (int)(100.0*br*((float) pulseBr[j]/100.0));
            blue = (int)(30.0*br*((float) pulseBr[j]/100.0));
            errors = neopixel_set_color(&m_strip, j, red, green, blue);
        }
        neopixel_show(&m_strip);

    }
    release_fiber();
}


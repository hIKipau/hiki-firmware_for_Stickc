
#include <Arduino.h>
#include "M5StickCPlus2.h"
#include <M5Unified.h>
#include "../resources/boot_1.h"
#include "../resources/boot_2.h"
#include "menu.h"

uint32_t starttimer = millis();
uint32_t timeforsleep = starttimer;
uint32_t timeForBattery = starttimer;

Hiki::Menu menu;

void setup() {
    M5.begin();
    M5.Lcd.setRotation(3);
    M5.Lcd.drawBitmap(0, 0, BOOT_1_WIDTH, BOOT_1_HEIGHT, boot_2, WHITE); 
    delay(3000);
    M5.Lcd.fillScreen(BLACK);
    menu.drawMenu();  
}

void loop() {
    M5.update();
    timeforsleep = millis();

    menu.updateBattery();

    if (M5.BtnA.wasClicked()) {
        M5.Lcd.setBrightness(100);

        timeforsleep = starttimer;
    } 
    else if (M5.BtnPWR.wasClicked()) {
        M5.Lcd.setBrightness(100);

        timeforsleep = starttimer;
        menu.changeStateDown();
        menu.drawMenu();  
    } 
    else if (M5.BtnB.wasClicked()) {
        M5.Lcd.setBrightness(100);

        timeforsleep = starttimer;
        menu.changeStateUp();
        menu.drawMenu();  
    }

    if ((timeforsleep - starttimer) >= 45000) {
        M5.Lcd.setBrightness(30);
    }
    if ((timeforsleep - starttimer) >= 90000) {
        M5.Lcd.setBrightness(0);
    }
}

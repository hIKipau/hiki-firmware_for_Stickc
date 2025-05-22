#pragma once
#include <Arduino.h>
#include "M5StickCPlus2.h"
#include <M5Unified.h>
#include "battery.h"

namespace Hiki {
class Menu {
private: 
    const char wifi[6] = "WI-FI";
    const char bluetooth[10] = "BLUETOOTH";
    const char settings[9] = "SETTINGS";
    int stateoOfMenu = 0;
    Hiki::Battery battery;

public:
    void changeStateDown() {
        // очищаем область меню (например, середина экрана)
        M5.Lcd.fillRect(0, 40, 240, 80, BLACK);
        stateoOfMenu = (stateoOfMenu + 1) % 3;
    }

    void changeStateUp() {
        M5.Lcd.fillRect(0, 40, 240, 80, BLACK);
        stateoOfMenu = (stateoOfMenu == 0) ? 2 : stateoOfMenu - 1;
    }

    void drawMenu() { 
        M5.Lcd.setTextSize(3);
        M5.Lcd.setCursor(10, 60);

        switch (stateoOfMenu) {
            case 0:
                M5.Lcd.setTextColor(WHITE);
                M5.Lcd.printf(wifi);
                break;
            case 1:
                M5.Lcd.setTextColor(WHITE);
                M5.Lcd.printf(bluetooth);    
                break;
            case 2:
                M5.Lcd.setTextColor(WHITE);
                M5.Lcd.printf(settings);    
                break;
        }
    }

    void updateBattery() {
        battery.drawBattery(M5);  
    }
};
}

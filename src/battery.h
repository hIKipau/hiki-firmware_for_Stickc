#pragma once
#include <Arduino.h>
#include "M5StickCPlus2.h"
#include <M5Unified.h>

namespace Hiki {

class Battery {
    public:
        bool changed = false;
        int prewBatteryLevel = -1;
        unsigned long lastUpdateTime = 0;

        bool drawBattery(m5::M5Unified &M5) {
            int batteryLevel = M5.Power.getBatteryLevel();
            unsigned long currentTime = millis();

            if (currentTime - lastUpdateTime >= 1000) {
                lastUpdateTime = currentTime;

                if (batteryLevel != prewBatteryLevel) {
                    M5.Lcd.fillRect(212, 2, 40, 10, BLACK);  // только область процентов
                    prewBatteryLevel = batteryLevel;

                    if (batteryLevel > 70) {
                        M5.Lcd.setTextColor(GREEN);
                    } else if (batteryLevel > 20) {
                        M5.Lcd.setTextColor(YELLOW);
                    } else {
                        M5.Lcd.setTextColor(RED);
                    }

                    M5.Lcd.setCursor(212, 2);
                    M5.Lcd.setTextSize(1);
                    M5.Lcd.printf("%d%%", batteryLevel);
                    changed = true;
                } else {
                    changed = false;
                }
            }

            return changed;
        }
};

}

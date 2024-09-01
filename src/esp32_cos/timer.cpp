#include <Arduino.h>
#include "../esp32_cos_lib/lib.h"
#include "esp32_cos_header/timer.h"
#include "esp32_cos_header/server/RTC.h"
const long getDataDelay = 1 * 60 * 60; //each get data from sensor
unsigned long lastTime = 0;
void initTimer(){
    EEPROM.begin(512);
    initRTC();
    lastTime = EEPROM.read(EEPROM_LAST_TIME_ADDRESS);
    if (lastTime == 0xFFFFFFFF) { // If EEPROM is empty, set lastTime to 0
        lastTime = 0;
    }
    updateRTC();
}
bool checkTimer(){
    unsigned long curMil = millis();
    if(curMil - lastTime >= getDataDelay){
        lastTime = curMil;
        return true;
    }else{
        return false;
    }
}
bool checkUpdateOTA(){
    return checRTCforOTA();
}
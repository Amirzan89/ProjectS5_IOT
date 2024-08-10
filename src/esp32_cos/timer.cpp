#include <Arduino.h>
#include "../esp32_cos_lib/lib.h"
#include "esp32_cos_header/timer.h"
#include "esp32_cos_header/server/RTC.h"
const long getDataDelay = 1 * 60 * 60; //each get data from sensor
const long getDataTimeout = 5 * 60;
bool dataState = false;
unsigned long timerUpdate = 0;
unsigned long lastTime = 0;
unsigned long lastDate = 0;
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
    // unsigned long curMil = millis();
    if()
    if (curMil - lastDate >= getDataDelay) {
        lastDate = curMil;
        // dataState = true;
        return true;
    }else{
        return false;
    }
    return false;
    // if (dataState == false && curMil - previousMillis >= getDataDelay) {
//    if (dataState == true && curMil - previousMillis >= intervalOn) {
//        previousMillis = curMil;
//        dataState = false;
//        return false;
//    }
}
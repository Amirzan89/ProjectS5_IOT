#include <Arduino.h>
#include "../esp32_cos_lib/lib.h"
#include "common/utils_all.h"
#include "esp32_cos_header/utils.h"
#include "esp32_cos_header/server/main.h"
#include "esp32_cos_header/server/OTA.h"
#include "esp32_cos_header/server/server.h"
#include "esp32_cos_header/communication.h"
#include "esp32_cos_header/timer.h"
#include "esp32_cos_header/sleep.h"
bool isConnected = false;
bool isRunning = false;
void setup(){
    Serial.begin(115200);
    initUtilsAll();
    while(!isConnected){
        isConnected = initMainServer();
        delay(500);
    }
    initCom();
    initTimer();
}
void loop(){
    if(checkUpdateOTA()){
        manageOTA();
    }
    if(checkTimer()){
        wakeup();
        if(!isSleep){
            sendData(reqDataCom());
            makeSleep();
        }
    }
}
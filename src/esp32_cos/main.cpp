#include <Arduino.h>
#include "../esp32_cos_lib/lib.h"
#include "common/utils_all.h"
#include "esp32_cos_header/utils.h"
#include "esp32_cos_header/server/main.h"
#include "esp32_cos_header/communication.h"
#include "esp32_cos_header/timer.h"
// #include "lib.h"
bool isConnected = false;
bool isRunning = false;
void setup() {
    Serial.begin(115200);
    initUtilsAll();
    while(!isConnected){
        isConnected = initMainServer();
        delay(500);
    }
    initCom();
}
void loop() { 
    // lcd.println("welcommee");
    // lcd.println("Check Connection");
    isRunning = startRunning();
    if(isRunning){
        //get sensor from arduino
        
    }
}

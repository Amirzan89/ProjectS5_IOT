#include <Arduino.h>
#include "uno_cos_header/communication.h"
bool isReadyCom = false;
void initCom(){
    while(Serial.available() > 0 && !isReadyCom){
        if(Serial.readStringUntil('\n') == "init arduino"){
            Serial.println("ready");
            isReadyCom = true;
        }
    }
}
void updateOTA(){
    //
}
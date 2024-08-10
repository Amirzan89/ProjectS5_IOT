#include <Arduino.h>
#include "../esp32_cos_lib/lib.h"
#include "esp32_cos_header/communication.h"
bool isReadyCom = false;
void initCom(){
    Serial.println("init arduino");
    unsigned long timeout = millis() + 5000; 
    while(!isReadyCom){
        if(millis() <= timeout){
            while(Serial.available() > 0){
                if(Serial.readStringUntil('\n') == "ready"){
                    isReadyCom = true;
                }
            }
        }else{
            // reach timeout
        }
    }
}
void sendOTA(String dataOTA){
    // Serial.println("update");
    // Serial.print(dataOTA);
}
DynamicJsonDocument reqDataCom(){
    Serial.println('getData');
    if(Serial.available() > 0){
        DynamicJsonDocument jsonRes(720);
        deserializeJson(jsonRes, Serial.readStringUntil('\n'));
        return jsonRes;
    }
}
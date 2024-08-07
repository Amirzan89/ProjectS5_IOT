#include <Arduino.h>
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
//void getData(){
//    Serial.print('getData');
//    if(Serial.available){
//        return Serial.readStringUntil('\n');
//    }
//}
//void reqData(){
//    Serial.print();
//}
//void resData(){
//    Serial.print("");
//}

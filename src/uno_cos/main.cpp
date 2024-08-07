#include <Arduino.h>
#include "../uno_cos_lib/lib.h"
#include "common/utils_all.h"
#include "uno_cos_header/utils.h"
#include "uno_cos_header/config.h"
#include "uno_cos_header/communication.h"
void setup() {
    Serial.begin(115200);
    initUtilsAll();
    initUtilsUno();
    initCom();
}
void loop(){
    if(Serial.available()){
        if(Serial.readString() == "getData"){
            //
        }
    }
}
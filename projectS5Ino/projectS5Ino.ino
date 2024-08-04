#include "config.h"
#include "lib.h"
#include "utils.ino"
#include "communation.ino"
void setup() {
    Serial.begin(115200);
    initAllUtils();
    initCom();
}
void loop(){
    if(Serial.available()){
        if(Serial.readString() == "getData"){
            //
        }
    }
}
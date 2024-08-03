#include "config.h"
#include "lib.h"
#include "utils.ino"
void setup() {
    // put your setup code here, to run once:
    Serial.begin(115200);
    initAllUtils();
}
void loop(){
    if(Serial.available()){
        if(Serial.readString() == "getData"){
            //
        }
    }
}
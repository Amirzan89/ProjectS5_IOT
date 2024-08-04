bool isReadyCom = false;
void initCom(){
    while(Serial.available > 0 && !isReadyCom){
        if(Serial.readStringUntil("\n") == "init arduino"){
            Serial.println("ready");
            isReadyCom = true;
        }
    }
}
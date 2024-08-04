#include "wifi.h"
#include "Arduino.h"
bool isConnect = false;
int maxTryConnect = 3;
int tryConnect = 0;
bool initMainServer(){
    initWifi();
    while(!isConnect && tryConnect < 3){
        isConnect = checkWifi();
        tryConnect++;
        delay(1000);
    }
    if(!isConnect){
        return false;
    }
    return true;
}
void runServer(){
    
}
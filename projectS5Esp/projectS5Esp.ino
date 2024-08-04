#include "config.h"
#include "lib.h"
bool isConnected = false;
bool isRunning = false;
void setup() {
    Serial.begin(115200);
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

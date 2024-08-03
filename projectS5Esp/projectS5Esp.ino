#include "config.h"
#include "server/main.ino"
#include "utils.ino"
#include "Communication.ino"
#include "timer.ino";
const char* id_device = "tershhhh";
const char* token = "ggegegegegeg";
bool isConnected = false;
bool isRunning = false;
void setup() {
    Serial.begin(115200);
    Serial.println("welcommee");
    Serial.println("Check Connection");
    isConnected = initMainServer();
}
void loop() {
    isRunning = startRunning();
    if(isRunning){
        //get sensor from arduino
        
    }
}
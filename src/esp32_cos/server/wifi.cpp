#include "../esp32_cos_lib/lib.h"
#include "esp32_cos_header/server/wifi.h"
WiFiManager wm;
bool portalRunning = false;
const WifiPin COS_TRIGGER_PIN = { 0, INPUT_PULLUP, 120};
void initWifi(){
    WiFi.mode(WIFI_STA);
    pinMode(COS_TRIGGER_PIN.triggerPin, COS_TRIGGER_PIN.triggerPin);
}
bool checkWifi(){
    if (digitalRead(COS_TRIGGER_PIN.triggerPin) == LOW) {
        WiFiManager wm;
        wm.setConfigPortalTimeout(COS_TRIGGER_PIN.timeout);
        if (!wm.startConfigPortal("OnDemandAP", "terserah")) {
            Serial.println("failed to connect and hit timeout");
            delay(2000);
            ESP.restart();
            delay(2000);
        }
        Serial.println("connected...yeey :)");
        return true;
    }
}
#include <WiFiManager.h>
bool portalRunning = false;
WiFiManager wm;
void initWifi(){
    WiFi.mode(WIFI_STA);
    pinMode(TRIGGER_PIN, INPUT_PULLUP);
}
void checkWifi(){
    const int timeout = 120;
    if ( digitalRead(TRIGGER_PIN) == LOW) {
        WiFiManager wm;
        wm.setConfigPortalTimeout(timeout);
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
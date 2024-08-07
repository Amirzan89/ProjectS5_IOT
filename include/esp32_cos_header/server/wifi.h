#ifndef WIFI_H
#define WIFI_H
void initWifi();
bool checkWifi();
struct WifiPin {
    int triggerPin;
    int mode;
    float timeout;
};
extern const WifiPin COS_TRIGGER_PIN;
#endif
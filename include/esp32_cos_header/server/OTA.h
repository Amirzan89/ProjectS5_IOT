#ifndef OTA_ESP32_H
#define OTA_ESP32_H
#include <Arduino.h>
#define FIRMWARE_PARTITION_1_ADDRESS 0x1000
#define FIRMWARE_PARTITION_2_ADDRESS 0x8000
#define FIRMWARE_PARTITION_SIZE 0x7000
const String esp32Version = "1.0.0";
String arduinoVersion = "1.0.0";
void manageOTA();
void updateOTA(File data);
#endif
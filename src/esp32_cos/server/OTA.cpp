#include <Arduino.h>
#include "../esp32_cos_lib/lib.h"
#include "esp32_cos_header/communication.h"
#include "esp32_cos_header/server/server.h"
#include "esp32_cos_header/server/OTA.h"
const int autoUpdate = 23 * 7 * 1; //check every month
// NTP Server
const int delayChecking = 7 * 24 * 3600;
void updateFirmware(const uint8_t* firmwareBinary, size_t binarySize) {
    // esp_partition_erase_range(esp_partition_find_first(ESP_PARTITION_TYPE_APP, ESP_PARTITION_SUBTYPE_APP_OTA_0, NULL), 0, FIRMWARE_PARTITION_SIZE);
    // esp_partition_write_range(esp_partition_find_first(ESP_PARTITION_TYPE_APP, ESP_PARTITION_SUBTYPE_APP_OTA_0, NULL), 0, firmwareBinary, binarySize);
    // esp_partition_set_boot_partition(esp_partition_find_first(ESP_PARTITION_TYPE_APP, ESP_PARTITION_SUBTYPE_APP_OTA_0, NULL));
}
void manageOTA(){
    DynamicJsonDocument data(120);
    data[0]["device"] = "esp32";
    data[0]["version"] = esp32Version;
    data[1]["device"] = "arduino";
    data[1]["version"] = arduinoVersion;
    Response resCheck = sendCheckOTA(data);
    if(resCheck.message == "esp"){
        updateOTA(handleOTA("esp"));
    }else if(resCheck.message == "arduino"){
        sendOTA(handleOTA("arduino"));
        arduinoVersion = resCheck.data["arduino"].as<String>();
    }
}
void updateOTA(String data){
    //install OTA;
}
#include <Arduino.h>
#include "../esp32_cos_lib/lib.h"
#include "esp32_cos_header/communication.h"
#include "esp32_cos_header/server/server.h"
#include "esp32_cos_header/server/OTA.h"
const int delayChecking = 7 * 24 * 3600;
void updateFirmware(const uint8_t* firmwareBinary, size_t binarySize) {
    // esp_partition_erase_range(esp_partition_find_first(ESP_PARTITION_TYPE_APP, ESP_PARTITION_SUBTYPE_APP_OTA_0, NULL), 0, FIRMWARE_PARTITION_SIZE);
    // esp_partition_write_range(esp_partition_find_first(ESP_PARTITION_TYPE_APP, ESP_PARTITION_SUBTYPE_APP_OTA_0, NULL), 0, firmwareBinary, binarySize);
    // esp_partition_set_boot_partition(esp_partition_find_first(ESP_PARTITION_TYPE_APP, ESP_PARTITION_SUBTYPE_APP_OTA_0, NULL));
}
void manageOTA(){
    //check esp32
    DynamicJsonDocument data(120);
    data["device"] = "esp32";
    data["version"] = esp32Version;
    Response resCheck = sendCheckOTA(data);
    if(resCheck.message == "success"){
        updateOTA(handleOTA(data));
    }
    //check arduino
    data["device"] = "arduino";
    data["version"] = arduinoVersion;
    Response resCheck = sendCheckOTA(data);
    if(resCheck.message == "success"){
        sendOTA(handleOTA(data));
        arduinoVersion = resCheck.data["arduino"].as<String>();
    }
}
void updateOTA(File data){
    //install OTA;
    tarGzFS.begin();
}
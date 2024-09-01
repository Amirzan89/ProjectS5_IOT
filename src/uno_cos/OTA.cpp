#include <Arduino.h>
#include "../uno_cos_lib/lib.h"
#include "uno_cos_header/OTA.h"
const int delayChecking = 7 * 24 * 3600;
void updateFirmware(const uint8_t* firmwareBinary, size_t binarySize) {
    esp_partition_erase_range(esp_partition_find_first(ESP_PARTITION_TYPE_APP, ESP_PARTITION_SUBTYPE_APP_OTA_0, NULL), 0, FIRMWARE_PARTITION_SIZE);
    esp_partition_write_range(esp_partition_find_first(ESP_PARTITION_TYPE_APP, ESP_PARTITION_SUBTYPE_APP_OTA_0, NULL), 0, firmwareBinary, binarySize);
    esp_partition_set_boot_partition(esp_partition_find_first(ESP_PARTITION_TYPE_APP, ESP_PARTITION_SUBTYPE_APP_OTA_0, NULL));
}
void updateOTA(){
    // if(){
    //     return false;
    // }else{
    //     return true;
    // }
}
void manageOTA(){
    //unzip
    //check if()
}
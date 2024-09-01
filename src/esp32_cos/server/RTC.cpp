#include "../esp32_cos_lib/lib.h"
#include "esp32_cos_header/server/RTC.h"
WiFiUDP ntpUDP;
const char* ntpServer1 = "0.id.pool.ntp.org";
const char* ntpServer2 = "1.id.pool.ntp.org";
const char* ntpServer3 = "2.id.pool.ntp.org";
const char* ntpServer4 = "3.id.pool.ntp.org";
const int EEPROM_LAST_TIME_ADDRESS = 0;
NTPClient timeClient(ntpUDP, ntpServer1);
dateTime curTime;
void initRTC(){
    timeClient.begin();
    timeClient.setUpdateInterval(1*7*24*60*60*100); //1 weeks in milisecond
    //check if first time turn on
    if(EEPROM.read(EEPROM_LAST_TIME_ADDRESS) == 0xFFFFFFFF){
        timeClient.update();
        EEPROM.put(EEPROM_LAST_TIME_ADDRESS, timeClient.getEpochTime());
    }
}
void updateRTC(){
    if(!timeClient.isTimeSet()){
        String formattedDate = timeClient.getFormattedTime();
        EEPROM.put(EEPROM_LAST_TIME_ADDRESS, timeClient.getEpochTime());
    }else{
        timeClient.forceUpdate();
    }
}
bool checRTCforOTA() {
    // If it'sfirtday and on midnight
    if (timeClient.getDay() == 1 && timeClient.getHours() == 0 && timeClient.getMinutes() == 0 && timeClient.getSeconds() == 0) { 
        return true;
    }else{
        return false;
    }
}
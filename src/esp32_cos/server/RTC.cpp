#include "../esp32_cos_lib/lib.h"
#include "esp32_cos_header/server/RTC.h"
WiFiUDP ntpUDP;
const char* ntpServer1 = "0.id.pool.ntp.org";
const char* ntpServer2 = "1.id.pool.ntp.org";
const char* ntpServer3 = "2.id.pool.ntp.org";
const char* ntpServer4 = "3.id.pool.ntp.org";
NTPClient timeClient(ntpUDP, ntpServer1);
const int EEPROM_LAST_TIME_ADDRESS = 0;
dateTime curTime;
void initRTC(){
    timeClient.begin();
    timeClient.setUpdateInterval(1*7*24*60*60*100); //1 weeks in milisecond
    //check if first time turn on
    if(EEPROM.read(EEPROM_LAST_TIME_ADDRESS) == 0xFFFFFFFF){
        timeClient.update();
    }
}
void updateRTC(){
    if(!timeClient.isTimeSet()){
        String formattedDate = timeClient.getFormattedTime();
        EEPROM.put(EEPROM_LAST_TIME_ADDRESS, timeClient.getEpochTime());
    }
}
void checkNewDayAndMonth() {
    String formattedDate = timeClient.getFormattedDate();
    int day = formattedDate.substring(0, 2).toInt();
    int month = formattedDate.substring(3, 5).toInt();
    if (day == 1) { // If it's the first day of the month
        // Perform actions for new month
    }
    if (hour == 0 && minute == 0 && second == 0) { // If it's midnight
        // Perform actions for new day
    }
}
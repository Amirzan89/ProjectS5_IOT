#ifndef RTC_H
#define RTC_H
struct dateTime{
    String date;
    String time;
    unsigned long timestamp;
};
extern dateTime curTime;
void initRTC();
void updateRTC();
bool checRTCforOTA();
#endif
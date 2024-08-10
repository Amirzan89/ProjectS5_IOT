#ifndef TIMER_H
#define TIMER_H
void initTimer();
bool checkUpdateOTA();
bool checkTimer();
const int EEPROM_LAST_TIME_ADDRESS = 0;
#endif
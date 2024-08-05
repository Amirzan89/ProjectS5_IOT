// //config wifi
#ifndef CONFIG_OTA_H
#define CONFIG_OTA_H
#define TRIGGER_PIN 0
#endif

//config server
#ifndef CONFIG_SERVER_H
#define CONFIG_SERVER_H
extern const char* CONFIG_baseURL;
extern const char* CONFIG_path[];
#endif

//config sensor
#ifndef CONFIG_SENSOR_H
#endif

//config etc
#ifndef CONFIG_SENSOR_H
#endif

#include "src/server/main.h"
#include "src/server/wifi.h"
#include "src/server/OTA.h"
#include "src/server/server.h"
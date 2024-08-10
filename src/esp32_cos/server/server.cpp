#include "Arduino.h"
#include "esp32_cos_header/server/server.h"
CosServer cosServer;
void sendData(DynamicJsonDocument data){
    Response res = cosServer.postData("/api/device/post", data);
    if(res.status == "error"){
        // lcd.println("Error");
    }else{
        //
    }
}
Response sendCheckOTA(DynamicJsonDocument data){
    Response res = cosServer.postData("/api/firmware/check", data);
    if(res.status == "error"){
        // lcd.println("Error");
    }else{
    }
    return res;
}
String handleOTA(String cond){
    Response res = cosServer.postData("/api/firmware/download");
    if(res.status == "error"){
        // lcd.println("Error");
    }
    return res.data.as<String>();
}
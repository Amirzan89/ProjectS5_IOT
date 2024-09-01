#ifndef SERVER_H
#define SERVER_H
#include "../esp32_cos_lib/lib.h"
#include "../config.h"
#include "../globals.h"
struct Response {
    String status;
    String message;
    int code;
    DynamicJsonDocument data = DynamicJsonDocument(32);
    File file;
};
class CosServer {
    public:
        Response getData(const DynamicJsonDocument reqData) {
            DynamicJsonDocument reqConfig = reqData;
            reqConfig["method"] = "GET";
            return _sendRequest(reqConfig);
        }
        Response postData(const DynamicJsonDocument reqData, const DynamicJsonDocument& data = DynamicJsonDocument(64)) {
            DynamicJsonDocument reqConfig = reqData;
            reqConfig["method"] = "POST";
            return _sendRequest(reqConfig, data);
        }
        Response putData(const DynamicJsonDocument reqData, const DynamicJsonDocument& data) {
            DynamicJsonDocument reqConfig = reqData;
            reqConfig["method"] = "PUT";
            return _sendRequest(reqConfig, data);
        }
        Response deleteData(const DynamicJsonDocument reqData, const DynamicJsonDocument& data) {
            DynamicJsonDocument reqConfig = reqData;
            reqConfig["method"] = "DELETE";
            return _sendRequest(reqConfig, data);
        }
        Response download(const DynamicJsonDocument reqData, const DynamicJsonDocument& data){
            DynamicJsonDocument reqConfig = reqData;
            reqConfig["method"] = "DELETE";
            return _sendRequest(reqConfig, data, "file");
        }

    private:
        HTTPClient _http;
        Response _sendRequest(DynamicJsonDocument Req, const DynamicJsonDocument &data = DynamicJsonDocument(64), const char* opt = "normal") {
            String fullPath = String(CONFIG_baseURL) + Req["path"].as<String>();
            _http.begin(fullPath);
            int code = 0;
            const char* reqMethod = Req["method"].as<String>().c_str();
            if (reqMethod == "GET") {
                code = _http.sendRequest(reqMethod);
            } else {
                DynamicJsonDocument requestData = data;
                _http.addHeader("Content-Type", "application/json");
                requestData["id_device"] = id_device;
                requestData["token"] = token;
                String request;
                serializeJson(requestData, request);
                code = _http.sendRequest(reqMethod, request);
            }
            Response res;
            if (code <= 0) {
                res.status = "error";
                res.message = "ANEH";
                return res;
            }
            DynamicJsonDocument jsonRes(2048);
            String resStr = _http.getString();
            deserializeJson(jsonRes, resStr);
            if (code == 200) {
                if(opt == 'file'){
                File file = SPIFFS.open(Req["path_file"], FILE_WRITE);
                if(_http.getStream)
                }else{
                    res.status = "success";
                    res.message = jsonRes["message"].as<String>();
                    // res.data = jsonRes["data"];
                }
            } else {
                res.status = "error";
                res.message = jsonRes["message"].as<String>();
                res.code = code;
            }
            return res;
        }
};
void sendData(DynamicJsonDocument data);
Response sendCheckOTA(DynamicJsonDocument data);
File handleOTA(DynamicJsonDocument data);
#endif
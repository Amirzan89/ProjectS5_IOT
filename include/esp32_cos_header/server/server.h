#ifndef SERVER_H
#define SERVER_H
#include <ArduinoJson.h>
#include <HTTPClient.h>
// #include "../esp32_cos_lib/lib.h"
#include "../config.h"
#include "../globals.h"
struct Response {
    String status;
    String message;
    int code;
};
class CosServer {
    public:
        Response getData(const char* path) {
            return _sendRequest("GET", path);
        }
        Response postData(const char* path, const DynamicJsonDocument& data) {
            return _sendRequest("POST", path, data);
        }
        Response putData(const char* path, const DynamicJsonDocument& data) {
            return _sendRequest("PUT", path, data);
        }
        Response deleteData(const char* path, const DynamicJsonDocument& data) {
            return _sendRequest("DELETE", path, data);
        }

    private:
        HTTPClient _http;
        Response _sendRequest(const char* method, const char* path, const DynamicJsonDocument &data = DynamicJsonDocument(64)) {
            String fullPath = String(CONFIG_baseURL) + path;
            _http.begin(fullPath);
            int code = 0;
            if (method == "GET") {
                code = _http.sendRequest(method);
            } else {
                DynamicJsonDocument requestData = data;
                _http.addHeader("Content-Type", "application/json");
                requestData["id_device"] = id_device;
                requestData["token"] = token;
                String request;
                serializeJson(requestData, request);
                code = _http.sendRequest(method, request);
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
                res.status = "success";
                res.message = jsonRes["message"].as<String>();
            } else {
                res.status = "error";
                res.message = jsonRes["message"].as<String>();
                res.code = code;
            }
            return res;
        }
};
#endif
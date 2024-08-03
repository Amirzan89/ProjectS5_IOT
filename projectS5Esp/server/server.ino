#include <ArduinoJson.h>
#include <HTTPClient.h>
class CosServer {
    public:
        Response getData(const char* path) {
            return _sendRequest("GET", path);
        }
        Response postData(const char* path, const String& data) {
            return _sendRequest("POST", path, data);
        }
        Response putData(const char* path, const String& data) {
            return _sendRequest("PUT", path, data);
        }
        Response deleteData(const char* path, const String& data) {
            return _sendRequest("DELETE", path, data);
        }

    private:
        HTTPClient _http;
        // Response _sendRequest(const char* method, const char* path, const String& data = "") {
        Response _sendRequest(const char* method, const char* path, const DynamicJsonDocument &data) {
            String fullPath = String(CONFIG_baseURL) + path;
            _http.begin(fullPath);
            if (method == "GET") {
                int code = _http.sendRequest(method);
            } else {
                DynamicJsonDocument requestData = data
                _http.addHeader("Content-Type", "application/json");
                requestData["id_device"] = id_device;
                requestData["token"] = token;
                String request;
                serializeJson(requestData, request);
                int code = _http.sendRequest(method, request);
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
                res.message = jsonRes["message"];
            } else {
                res.status = "error";
                res.message = jsonRes["message"];
                res.code = code;
            }
            return res;
        }
};
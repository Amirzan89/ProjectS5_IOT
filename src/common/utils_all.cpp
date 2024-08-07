#include <Arduino.h>
#include "common/utils_all.h"
bool buttonState = LOW;
bool lastButtonState = LOW;
unsigned long lastDebounceTime = 0;
// void debounce(int inpPin, void (*callback)(bool), int debounceDelay = 20) {
// void debounce(int inpPin, std::function<void(bool)> callback, int debounceDelay = 20) {
//     pinMode(inpPin, INPUT);
//     bool reading = digitalRead(inpPin);
//     if (reading != lastButtonState) {
//         lastDebounceTime = millis();
//     }
//     if (millis() - lastDebounceTime > debounceDelay) {
//         if (reading != buttonState) {
//             buttonState = reading;
//             callback(buttonState);
//         }
//     }
//     lastButtonState = reading;
// }
// debounce(1, 50, [&](bool state) {
//     if (state) {
//         Serial.println("Button pressed!");
//     } else {
//         Serial.println("Button released!");
//     }
// });
void initUtilsAll(){
    //
}
const long getDataDelay = 1 * 60 * 60; //each get data from sensor
const long getDataTimeout = 5 * 60;
unsigned long previousMillis = 0;
bool dataState = false;
unsigned long curMil;
void startRunning(){
    curMil = millis();
    if (dataState == false && curMil - previousMillis >= getDataDelay) {
        previousMillis = curMil;
        dataState = true;
        //start get sensor
        return true;
    }
    if (dataState == true && curMil - previousMillis >= intervalOn) {
        previousMillis = curMil;
        dataState = false;
        return false;
    }
}
    // unsigned long currentMillis = millis();
    // if (ledState == false && currentMillis - previousMillis >= intervalOff) {
    //     previousMillis = currentMillis;
    //     ledState = true;
    //     digitalWrite(ledPin, HIGH);
    // }

    // if (ledState == true && currentMillis - previousMillis >= intervalOn) {
    //     previousMillis = currentMillis;
    //     ledState = false;
    //     digitalWrite(ledPin, LOW);
    // }
    // return ;
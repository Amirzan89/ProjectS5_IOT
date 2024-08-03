bool isReady = false;
void initCom(){
    Serial.print("init");
}
void getData(){
    Serial.print('getData');
    if(Serial.available){
        return Serial.readStringUntil('\n');
    }
}
void reqData(){
    Serial.print();
}
void resData(){
    Serial.print("");
}


enum State { WAITING, RECEIVING, PROCESSING };

State state = WAITING;

void SerialCommunication::handleSerialEvent() {
    switch (state) {
        case WAITING:
        if (Serial.available() > 0) {
            state = RECEIVING;
        }
        break;
        case RECEIVING:
        char c = Serial.read();
        // Process the received data
        if (c == '\n') {
            state = PROCESSING;
        }
        break;
        case PROCESSING:
        // Process the data
        state = WAITING;
        break;
    }
}

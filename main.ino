#include <Arduino.h>
#include "SerialCommunication.h"

SerialCommunication serialComm;

void setup() {
    serialComm.init();
}

void loop() {
    if (serialComm.available()) {
        const char* receivedCommand = serialComm.readCommand();
        if (receivedCommand != nullptr) {
            Serial.print("Received command: ");
            Serial.println(receivedCommand);
          if (String(receivedCommand) == "amid"){
            Serial.println("amid is true");
          }
            // Send response
            // const char* response = receivedCommand;
            // serialComm.sendResponse(response);
        }

    }
}

#include "SerialCommunication.h"

void SerialCommunication::init() {
    Serial.begin(SERIAL_BAUDRATE);
}

bool SerialCommunication::available() {
    return Serial.available() > 0;
}

const char* SerialCommunication::readCommand() {
    if (Serial.readBytesUntil('\n', buffer_, buffer_size)) {
        buffer_[buffer_size - 1] = '\0'; // Null-terminate

         // Parse the received data
        char *command = strtok(buffer_, "@");
        char *username = strtok(NULL, "@");
        char *userid = strtok(NULL, "@");
        
        Serial.println(command);
        // Check if the data is valid
        if (command != NULL && username != NULL && userid != NULL) {
            // Compare the command
            if (strcmp(command, "active") == 0) {
                Serial.print("Username: ");
                Serial.println(username);
                Serial.print("User ID: ");
                Serial.println(userid);
            } else {
                Serial.println("Unknown command.");
            }
        } else {
            Serial.println("Invalid data format.");
        }
        return buffer_;
    }
    return nullptr;
}

void SerialCommunication::sendResponse(const char* message) {
    Serial.print("Sending back: ");
    Serial.println(message);
}

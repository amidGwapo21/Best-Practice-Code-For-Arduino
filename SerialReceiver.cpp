#include "SerialReceiver.h"
#include <Arduino.h>

SerialReceiver::SerialReceiver(int bufferSize) {
    _bufferSize = bufferSize;
    _buffer = new char[_bufferSize]; // Allocate buffer
}

void SerialReceiver::begin(long baudRate) {
    Serial.begin(baudRate); // Start serial communication
}

String SerialReceiver::readData() {
    int index = 0;
    while (Serial.available() > 0 && index < _bufferSize - 1) {
        char c = Serial.read(); // Read a character
        if (c == '\n') { // Stop reading if newline character is encountered
            break;
        }
        _buffer[index++] = c; // Add character to buffer
    }
    _buffer[index] = '\0'; // Null-terminate the string
    return String(_buffer); // Return as a String
}

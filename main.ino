#include "SerialReceiver.h"

const int bufferSize = 50; // Define buffer size
SerialReceiver serialReceiver(bufferSize); // Create an instance of SerialReceiver

void setup() {
    serialReceiver.begin(115200); // Initialize serial communication at 115200 baud
    Serial.println("Serial Receiver Initialized");
}

void loop() {
    String receivedData = serialReceiver.readData(); // Read data from serial
    if (receivedData.length() > 0) {
        Serial.print("Received: ");
        Serial.println(receivedData); // Print received data to the Serial Monitor
    }
    delay(1000); // Wait before the next reading
}

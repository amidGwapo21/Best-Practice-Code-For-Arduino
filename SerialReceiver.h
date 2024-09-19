#ifndef SERIALCOMMUNICATION_H
#define SERIALCOMMUNICATION_H

#include <Arduino.h>

#define MAX_COMMAND_LENGTH 50
#define SERIAL_BAUDRATE 115200

class SerialCommunication {
public:
    void init();
    bool available();
    const char* readCommand();
    void sendResponse(const char* message);
private:
    static constexpr size_t buffer_size = MAX_COMMAND_LENGTH;
    char buffer_[buffer_size];
};

#endif // SERIALCOMMUNICATION_H

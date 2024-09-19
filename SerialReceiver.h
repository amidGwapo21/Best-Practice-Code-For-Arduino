#ifndef SerialReceiver_h
#define SerialReceiver_h

class SerialReceiver {
public:
    SerialReceiver(int bufferSize); // Constructor to set up the buffer size
    void begin(long baudRate); // Initialize serial communication
    String readData(); // Method to read data from serial
private:
    int _bufferSize; // Size of the buffer
    char* _buffer; // Pointer to hold the buffer
};

#endif

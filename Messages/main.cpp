#include "msg.hpp"
#include <iostream>

// Example 1: Define a simple message with no parameters
MSG_TYPE_0(MyMsgType0, 0x01)

// Example 2: Define a message with one parameter
MSG_TYPE_1(MyMsgType1, 0x02, int, value, 0)

// Example 3: Define a message with two parameters
MSG_TYPE_2(MyMsgType2, 0x03, float, floatValue, 0.0, char, charValue, 'A')

// Function to print the content of MyMsgType0
void printMessage(const MyMsgType0& msg) {
    std::cout << "MyMsgType0 - Type: " << static_cast<int>(msg.type) << std::endl;
}

// Function to print the content of MyMsgType1
void printMessage(const MyMsgType1& msg) {
    std::cout << "MyMsgType1 - Type: " << static_cast<int>(msg.type)
              << ", Value: " << msg.value << std::endl;
}

// Function to print the content of MyMsgType2
void printMessage(const MyMsgType2& msg) {
    std::cout << "MyMsgType2 - Type: " << static_cast<int>(msg.type)
              << ", Float Value: " << msg.floatValue
              << ", Char Value: " << msg.charValue << std::endl;
}

int main() {
    // Example 1: Instantiate and use the simple message type
    MyMsgType0 msg0;
    msg0.type = MyMsgType0::getCode();
    printMessage(msg0);

    // Example 2: Instantiate and use the message with one parameter
    MyMsgType1 msg1(42);
    printMessage(msg1);

    // Example 3: Instantiate and use the message with two parameters
    MyMsgType2 msg2(3.14, 'B');
    printMessage(msg2);

    return 0;
}
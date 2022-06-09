//Student1 Daniel Glazman, glazman.daniel@gmail.com, 318172848.
//Student2 Yogev Keshet, yogevkeshet34@gmail.com, 207286394.

#include "Keyboard.h"

//c'tor - initializing the attributes of base class PeripheralDevice and the current class' attributes
Keyboard::Keyboard(int price, const std::string& manufacturer, const std::string& color, bool isWireless, int numberOfKeys):
        PeripheralDevice(price, manufacturer, color, isWireless), numberOfKeys(numberOfKeys)
{}

//getters/setters
int Keyboard::getNumOfKeys() const
{
    return this->numberOfKeys;
}
void Keyboard::setNumOfKeys(int newNumOfKeys)
{
    this->numberOfKeys = newNumOfKeys;
}

//operator string with the addition of Keyboard class
Keyboard::operator std::string() const
{
    return PeripheralDevice::operator std::string() + ", Keyboard with " + std::to_string(numberOfKeys) + " keys";
}

//an implementation of connect function that overrides the function in the base class PeripheralDevice
void Keyboard::connect(Computer *computer)
{
    std::cout << "Connecting a keyboard" << std::endl;
    PeripheralDevice::connect(computer);
}
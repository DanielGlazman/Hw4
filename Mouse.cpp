//Student1 Daniel Glazman, glazman.daniel@gmail.com, 318172848.
//Student2 Yogev Keshet, yogevkeshet34@gmail.com, 207286394.

#include "Mouse.h"

//c'tor - initializing the attributes of base class PeripheralDevice and the current class' attributes
Mouse::Mouse(int price, const std::string& manufacturer, const std::string& color,bool isWireless, int dpi):
        PeripheralDevice(price, manufacturer, color, isWireless), dpi(dpi){}

int Mouse::getDpi() const //getters/setters
{
    return this->dpi;
}

void Mouse::setDpi(int newDpi)
{
    this->dpi = newDpi;
}

//operator string with the addition of Mouse class
Mouse::operator std::string() const
{
    return PeripheralDevice::operator std::string() + ", Mouse with dpi : " + std::to_string(dpi);
}

//an implementation of connect function that overrides the function in the base class PeripheralDevice
void Mouse::connect(Computer *computer)
{
    std::cout << "Connecting a mouse" << std::endl;
    PeripheralDevice::connect(computer);
}

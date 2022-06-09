//Student1 Daniel Glazman, glazman.daniel@gmail.com, 318172848.
//Student2 Yogev Keshet, yogevkeshet34@gmail.com, 207286394.

#include <vector>
#include <iostream>
#include "PeripheralDevice.h"
#include "HWExceptions.h"

//c'tor - initializing the attributes of base class Item and the current class' attributes
PeripheralDevice::PeripheralDevice(int price, const std::string& manufacturer, const std::string& color, bool isWireless):
    Item(price, manufacturer), color(color), isWireless(isWireless)
{}

//getters/getters
const std::string& PeripheralDevice::getColor() const
{
    return this->color;
}

void PeripheralDevice::setColor(const std::string& newColor)
{
    this->color = newColor;
}

bool PeripheralDevice::getIsWireless() const
{
    return this->isWireless;
}

void PeripheralDevice::setIsWireless(bool checkIsWireless)
{
    this->isWireless = checkIsWireless;
}

//operator string with the addition of PeripheralDevice class
PeripheralDevice::operator std::string() const
{
    std::string isWired;

    if(isWireless)
        isWired = "Wireless";
    else
        isWired = "Wired";

    return this->Item::operator std::string() + ", " + isWired + ", " + PeripheralDevice::getColor();
}

//basic implementation of the connect function for next override usages in derived classes  - pure virtual function
//the reason for that is that every derived class implements (overrides) this function
void PeripheralDevice::connect(Computer* computer)
{
    //as instructed if connecting to a computer that already connected to - do nothing.
    if(this->computerConnectedTo == computer)
    {
        return;
    }

    //throw an exception if the number of same connections is 2 or greater
    if(computer->numOfSameConnections(this) >= 2)
    {
        throw ConnectError();
    }

    std::cout << this->operator std::string() << " is Connecting to computer: " << computer->operator std::string() << std::endl;

    //throw an exception if number of connections is larger than the number of ports
    if(computer->numOfConnections() + 1 > computer->getPorts())
    {
        throw ConnectError();
    }

    //if we got through the exceptions - so we can add a connection.
    computer->addConnection(this);
    computerConnectedTo = computer; //determine the computer connected to as the given computer in the function
}

//the function that disconnects the device from the computer it was connected to,
//if wasn't connected to a computer - do nothing as instructed
void PeripheralDevice::disconnect()
{
    if(computerConnectedTo == NULL)
    {
        return;
    }
    computerConnectedTo->removeConnection(this);
    computerConnectedTo = NULL;
}

//d'tor
PeripheralDevice::~PeripheralDevice()
{
    disconnect();
}


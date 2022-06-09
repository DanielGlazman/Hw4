//Student1 Daniel Glazman, glazman.daniel@gmail.com, 318172848.
//Student2 Yogev Keshet, yogevkeshet34@gmail.com, 207286394.

#include <string>
#include <iostream>
#include <vector>
#include "Computer.h"

//constructor
Computer::Computer(int price, const std::string& manufacturer, const std::string& cpu, bool isLaptop, const int ports):
Item(price, manufacturer), cpu(cpu), isLaptop(isLaptop), ports(ports) {}

//getters/setters
void Computer::setCpu(const std::string& newCpu)
{
    this->cpu = newCpu;
}

const std::string& Computer::getCpu() const
{
    return this->cpu;
}

const int Computer::getPorts() const
{
    return this->ports;
}

//operator string that overrides the base function that is implemented in Item class
Computer::operator std::string() const
{
    std::string checkLaptop;
    if(isLaptop) // define a string that tells if a computer is laptop or not - using isLaptop variable
        checkLaptop = "Laptop";
    else
        checkLaptop = "Desktop";

    return  Item::operator std::string() + ", " + checkLaptop + ", " + cpu; //chaining the computer's new stuff
}

//implementation of the assistant functions that help us deal with the connected devices vector
//this function "connects" (adds) a new device to computer (the connected devices vector)
void Computer::addConnection(Item* newConnection)
{
    connectedDevices.push_back(newConnection);
}

//a function that counts the same type connected devices
int Computer::numOfSameConnections(Item* currConnection)
{
    int countSame = 0;
    std::vector<Item*>::iterator iter;
    for (iter = connectedDevices.begin(); iter != connectedDevices.end(); ++iter)
    {
        if(typeid(*iter) == typeid(*currConnection))
        {
            ++countSame;
        }
    }
    return countSame;
}

//a function that counts the number of connected devices exist to the current computer
int Computer::numOfConnections() const
{
    return connectedDevices.size();
}

//a function that removes a connection from a computer - removes an item from the connected devices vector
void Computer::removeConnection(Item* currConnection)
{
    std::vector<Item*>::iterator iter;
    for (iter = connectedDevices.begin(); iter != connectedDevices.end(); ++iter)
    {
        if(*iter == currConnection)
        {
            connectedDevices.erase( iter );
            break;
        }
    }
}

//a function that prints the devices that connected to the current computer
//basically we print the vector of connected devices we maintain
void Computer::print_connected()
{
    int numOfConnections = connectedDevices.size();
    std::cout << "There are " + std::to_string(numOfConnections) + " connection to " + this->operator std::string() << std::endl;

    //range based loop
    for(Item* itemPtr : connectedDevices)
    {
        std::cout << std::string(*itemPtr) << std::endl;
    }
}

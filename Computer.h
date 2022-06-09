//Student1 Daniel Glazman, glazman.daniel@gmail.com, 318172848.
//Student2 Yogev Keshet, yogevkeshet34@gmail.com, 207286394.

#include <string>
#include <iostream>
#include <vector>
#include "Item.h"

#ifndef HW4_COMPUTER_H
#define HW4_COMPUTER_H

class Computer: public Item{
    //Computer's attributes
    std::string cpu;
    bool isLaptop;
    const int ports;

    //a vector of Item* that will contain all the connected devices to the current computer
    std::vector<Item*> connectedDevices;

public:
    Computer(int price, const std::string& manufacturer, const std::string& cpu, bool isLaptop, int ports);
    //constructor

    void setCpu(const std::string& newCpu); // getters/setters
    const std::string& getCpu() const;
    const int getPorts() const;

    // assistant functions - dealing with the connected devices vector.
    void addConnection(Item* newConnection); //adding a connection to the vector
    int numOfSameConnections(Item* currConnection); //find the number of same type connections
    int numOfConnections() const; //return the number of connections
    void removeConnection(Item* currConnection); //removes a connection

    void print_connected(); //print all connected devices
    explicit operator std::string () const; //operator string declaration
    virtual ~Computer() {} //virtual destructor
 };


#endif //HW4_COMPUTER_H

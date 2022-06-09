//Student1 Daniel Glazman, glazman.daniel@gmail.com, 318172848.
//Student2 Yogev Keshet, yogevkeshet34@gmail.com, 207286394.

#ifndef HW4_PERIPHERALDEVICE_H
#define HW4_PERIPHERALDEVICE_H

#include <iostream>
#include <string>
#include "HWExceptions.h"
#include "Item.h"
#include "Computer.h"

class PeripheralDevice: public Item {
    //PeripheralDevice's attributes
    std::string color;
    bool isWireless;
    Computer* computerConnectedTo = NULL;

public:
    PeripheralDevice(int price, const std::string& manufacturer, const std::string& color, bool isWireless); //c'tor

    const std::string& getColor() const; //getters/setters
    void setColor(const std::string& newColor);
    bool getIsWireless() const;
    void setIsWireless(bool checkIsWireless);

    virtual void connect(Computer* computer) = 0; //virtual function - every derived class has to implement this function
    operator std::string() const; //operator string declaration
    void disconnect(); //disconnect function declaration
    virtual ~PeripheralDevice(); //virtual d'tor
};

#endif //HW4_PERIPHERALDEVICE_H

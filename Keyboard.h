//Student1 Daniel Glazman, glazman.daniel@gmail.com, 318172848.
//Student2 Yogev Keshet, yogevkeshet34@gmail.com, 207286394.

#include <iostream>
#include "PeripheralDevice.h"

#ifndef HW4_KEYBOARD_H
#define HW4_KEYBOARD_H


class Keyboard: public PeripheralDevice{
    //Keyboard's attributes
    int numberOfKeys;

public:
    Keyboard(int price, const std::string& manufacturer, const std::string& color, bool isWireless, int numberOfKeys); //c'tor

    int getNumOfKeys() const; //getters/setters
    void setNumOfKeys(int newNumOfKeys);

    operator std::string() const; //operator string declaration
    void connect(Computer *computer); //connect function declaration
    virtual ~Keyboard(){} //virtual d'tor
};


#endif //HW4_KEYBOARD_H

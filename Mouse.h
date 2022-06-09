//Student1 Daniel Glazman, glazman.daniel@gmail.com, 318172848.
//Student2 Yogev Keshet, yogevkeshet34@gmail.com, 207286394.

#include <string>
#include "PeripheralDevice.h"
#ifndef HW4_MOUSE_H
#define HW4_MOUSE_H

class Mouse: public PeripheralDevice {
    //Mouse's attributes
    int dpi;

public:
    Mouse(int price, const std::string& manufacturer, const std::string& color, bool isWireless, int dpi); //c'tor

    int getDpi() const; //getters/setters
    void setDpi(int newDpi);

    operator std::string() const;//operator string declaration
    void connect(Computer *computer);//connect function declaration
    virtual ~Mouse(){} //virtual d'tor
};


#endif //HW4_MOUSE_H

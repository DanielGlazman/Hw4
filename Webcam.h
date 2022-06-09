//
// Created by Daniel Glazman on 23/05/2022.
//
#include "PeripheralDevice.h"

#ifndef HW4_WEBCAM_H
#define HW4_WEBCAM_H


class Webcam: public PeripheralDevice{
    //Webcam's attributes
    std::string resolution;
public:
    //c'tor
    Webcam(int price, const std::string& manufacturer, const std::string& color,bool isWireless, const std::string& resolution);
    //getters/setters
    void setResolution(const std::string& newResolution);
    const std::string& getResolution() const;

    operator std::string() const; //operator string declaration
    void connect(Computer *computer); //connect function declaration
    virtual ~Webcam(){} //virtual d'tor
};
#endif //HW4_WEBCAM_H

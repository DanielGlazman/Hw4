//
// Created by Daniel Glazman on 23/05/2022.
//
#include "Webcam.h"
#include <iostream>
#include <string>

//c'tor - initializing the attributes of base class PeripheralDevice and the current class' attributes
Webcam::Webcam(int price, const std::string& manufacturer, const std::string& color,bool isWireless, const std::string& resolution):
            PeripheralDevice(price, manufacturer, color, isWireless), resolution(resolution){}

//getters/setters
void Webcam::setResolution(const std::string& newResolution)
{
    this->resolution = newResolution;
}

const std::string& Webcam::getResolution() const
{
    return this->resolution;
}

//operator string with the addition of Webcam class
Webcam::operator std::string() const
{
    return PeripheralDevice::operator std::string() + ", Webcam with " + resolution + " resolution";
}

//an implementation of connect function that overrides the function in the base class PeripheralDevice
void Webcam::connect(Computer *computer)
{
    std::cout << "Connecting a webcam" << std::endl;
    PeripheralDevice::connect(computer);
}
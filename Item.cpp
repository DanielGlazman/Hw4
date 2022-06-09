//Student1 Daniel Glazman, glazman.daniel@gmail.com, 318172848.
//Student2 Yogev Keshet, yogevkeshet34@gmail.com, 207286394.

#include "Item.h"
#include <iostream>

int Item::currId = 0; //initializing static variable

Item::Item(const int price, const std::string& manufacturer): price(price), manufacturer(manufacturer) //constructor
{
    id = ++currId; //initialize the id with the static current id variable
}

//getters/setters
int Item::getPrice() const
{
    return price;
}

const std::string& Item::getManufacturer() const
{
    return manufacturer;
}

int Item::getId() const
{
    return this->id;
}

void Item::setPrice(int newPrice)
{
    this->price = newPrice;
}

void Item::setManufacturer(const std::string& newManufacturer)
{
    this->manufacturer = newManufacturer;
}

//basic implementation of the string operator for next override usages in derived classes  - pure virtual function
//the reason for that is that every derived class implements (overrides) this function
Item::operator std::string() const
{
    return "id " + std::to_string(Item::getId()) + ": " + Item::getManufacturer() + " " + std::to_string(Item::getPrice()) + "$";
}

Item::~Item() //destructor
{
    std::cout<< "Throwing away an item" << std::endl;
}

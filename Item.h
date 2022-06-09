//Student1 Daniel Glazman, glazman.daniel@gmail.com, 318172848.
//Student2 Yogev Keshet, yogevkeshet34@gmail.com, 207286394.

#ifndef HW4_ITEM_H
#define HW4_ITEM_H

#include <string>

class Item{
    //Item's attributes
    int price;
    std::string manufacturer;
    int id;

public:
    static int currId; //static variable that represents the id of the current item
    Item(int price, const std::string& manufacturer); //c'tor

    int getPrice() const; //getters/setters
    void setPrice(int price);
    const std::string& getManufacturer() const;
    void setManufacturer(const std::string& manufacturer);
    int getId() const;

    virtual operator std::string() const = 0; //pure virtual function for the string operator
    virtual ~Item(); //virtual d'tor
};
#endif //HW4_ITEM_H

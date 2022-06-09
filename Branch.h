//Student1 Daniel Glazman, glazman.daniel@gmail.com, 318172848.
//Student2 Yogev Keshet, yogevkeshet34@gmail.com, 207286394.

#include <string>
#include <vector>
#include "Item.h"
#include "HWExceptions.h"

#ifndef HW4_BRANCH_H
#define HW4_BRANCH_H

class Branch{
    //Branch's attributes
    std::vector<Item*> itemCatalog;
    std::string location;
    int capacity;

    //private help functions
    static bool comparePrices(Item* i1, Item* i2);
    static bool compareIds(Item* i1, Item* i2);
    void prePrint();

public:
    Branch(); //default constructor
    Branch(const std::string& location, int capacity); //constructor
    Branch(const Branch& branch); //copy constructor

    const std::string& getLocation() const; //getters/setters
    void setLocation(const std::string& newLocation);
    int getCapacity() const;

    int branchValue(); //a function that computes the general value of a branch
    std::vector<Item *> getCatalog(); //get catalog function (as been defined in Main)
    void addItem(Item* newItem); //adding an item to a catalog
    Item* deleteItem(int id); //delete an item from the catalog

    //generic function that finds the finest object of a specific type,
    //done in order to suit every given object type - because we deal with pointers to Item.
    template<typename type>
    type retrieveFinest(type currItem)
    {
        int found = 0; //a flag that determines if the wanted type is found
        Item* finest = currItem;
        for(Item* itemPtr : itemCatalog)
        {
            if(typeid(*itemPtr) == typeid(*currItem)) //type comparison using typeid
            {
                if(finest->getPrice() <= itemPtr->getPrice())
                {
                    finest = itemPtr;
                    found = 1;
                }
            }
        }

        if(!found) //if the flag = 0, so we clearly didn't enter the loop and therefor the type isn't exist in the vector
        {
            throw NoneExistingItemTypeError();
        }
        return dynamic_cast<type>(finest); //cast the finest, from Item* to the type of the template
    }

    void print_catalog_by_id(); //printing functions  - by ID and by price
    void print_catalog_by_price();
    ~Branch(); //destructor
};


#endif //HW4_BRANCH_H

//Student1 Daniel Glazman, glazman.daniel@gmail.com, 318172848.
//Student2 Yogev Keshet, yogevkeshet34@gmail.com, 207286394.

#include <iostream>
#include <algorithm>
#include <string>
#include "Branch.h"
#include "HWExceptions.h"

Branch::Branch() //default c'tor
{
    location = "~";
    capacity = 0;
}
//constructor
Branch::Branch(const std::string& location, const int capacity): location(location), capacity(capacity)
{
//    for(int i = 0; i < itemCatalog.size(); i++) //initialize the pointers array with NULL for later convenience
//    {
//        itemCatalog[i] = NULL;
//    }
}

//copy c'tor
Branch::Branch(const Branch& branch)
{
    location = branch.location;
    capacity = branch.capacity;
}

//getters/setters
void Branch::setLocation(const std::string& newLocation)
{
    this->location = newLocation;
}

const std::string& Branch::getLocation() const
{
    return this->location;
}

std::vector<Item *> Branch::getCatalog() //update the given num parameter with itemsInCatalog and return the catalog
{
    return itemCatalog;
}

int Branch::getCapacity() const
{
    return this->capacity;
}

int Branch::branchValue()
{
    int value = 0;
    std::vector<Item*>::iterator iter;
    for (iter = itemCatalog.begin(); iter != itemCatalog.end(); ++iter)
    {
        value += (*iter)->getPrice();
    }
    return value;
}

void Branch::addItem(Item* newItem) //add a new item to the current catalog
{
    int currSize = 0;
    std::vector<Item*>::iterator iter; //define an iterator for the vector

    for (iter = itemCatalog.begin(); iter != itemCatalog.end(); ++iter) //check if there are same objects in the vector
    {
        if(*iter != newItem)
        {
            currSize++;
        }
    }

    if(currSize != itemCatalog.size()) //if there are same objects - throw an exception
    {
        throw ExistingItemError();
    }

    if(itemCatalog.size() + 1 > capacity) //throw an exception if the size is bigger than the capacity
    {
        throw FullCatalogError();
    }

    itemCatalog.push_back(newItem); //if none of the exception was thrown - add the new item into the vector
}

Item* Branch::deleteItem(int id) //delete an item from the catalog
{
    int found = 0; //a flag that helps us to know if the object exists in the vector
    std::vector<Item*>::iterator iter;
    for (iter = itemCatalog.begin(); iter != itemCatalog.end(); ++iter)
    {
        if((*iter)->getId() == id) //try to find the object with the given ID
        {
            found = 1;
            iter = itemCatalog.erase(iter);
            --iter;
        }
    }
    if(found == 0) //if not found, throw the suitable exception
    {
        throw NonExistingItemError();
    }
    return *iter;
}

void Branch::prePrint() //a function that helps with printing - to avoid code duplication
{
    std::cout << "Printing KSF branch in " + location << std::endl;
    std::cout << "There are " + std::to_string(itemCatalog.size()) + " item in the catalog" << std::endl;
    std::cout << "Catalog value is: " << std::to_string(branchValue()) << std::endl;
}

bool Branch::compareIds(Item* i1, Item* i2) //assistant function - helps us to sort the vector by ID
{
    return (i1->getId() < i2->getId());
}

void Branch::print_catalog_by_id()
{
    prePrint();
    std::vector<Item*> catalog = itemCatalog;
    std::stable_sort(catalog.begin(), catalog.end(), compareIds); //sort the vector by ID

    for(Item* itemPtr : catalog) // range based for loop
    {
        std::cout << std::string(*itemPtr) << std::endl;
    }
}

bool Branch::comparePrices(Item* i1, Item* i2) //assistant function - helps us to sort the vector by price
{
    return (i1->getPrice() < i2->getPrice());
}

void Branch::print_catalog_by_price()
{
    prePrint();
    std::vector<Item*> catalog = itemCatalog;
    std::stable_sort(catalog.begin(), catalog.end(), comparePrices); //sort the vector by price

    for(Item* itemPtr : catalog) // range based for loop
    {
        std::cout << std::string(*itemPtr) << std::endl;
    }
}

Branch::~Branch() //d'tor
{
    for(Item* itemPtr : itemCatalog)
    {
        delete itemPtr;
    }
    itemCatalog.clear();
}
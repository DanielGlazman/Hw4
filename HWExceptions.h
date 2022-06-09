//
// Created by Daniel Glazman on 26/05/2022.
//
#ifndef HW4_HWEXCEPTIONS_H
#define HW4_HWEXCEPTIONS_H

#include <iostream>
#include <exception>

//exception classes
//an exception class for an existing item the vector
class ExistingItemError: public std::exception{
public:
    virtual const char* what() const throw()
    {
        return "Trying to add an item with an id already in the catalog";
    }
};

//an exception class for a full vector (by capacity)
class FullCatalogError: public std::exception{
public:
    virtual const char* what() const throw()
    {
        return "Trying to add an item to a full catalog";
    }
};

//an exception class that is thrown when trying to delete an item that does not exist in the vector
class NonExistingItemError: public std::exception{
public:
    virtual const char* what() const throw()
    {
        return "Trying to delete an item with a non existing id";
    }
};

//an exception class  that is thrown when trying to get an item with a non-existing type
class NoneExistingItemTypeError: public std::exception{
public:
    virtual const char* what() const throw()
    {
        return "Trying to get an item with a non existing type";
    }
};

//an exception class  that is thrown when connect function conditions are violated
class ConnectError: public std::exception{
public:
    virtual const char* what() const throw()
    {
        return "Failed connection attempt";
    }
};

class ExistingBranchError: public std::exception{
public:
    virtual const char* what() const throw()
    {
        return "Trying to add a branch with an already existing location";
    }
};

class NonExistingBranchError: public std::exception{
public:
    virtual const char* what() const throw()
    {
        return "Trying to delete a branch with an non existing location";
    }
};

#endif //HW4_HWEXCEPTIONS_H

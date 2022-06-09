//
// Created by Daniel Glazman on 03/06/2022.
//
#include <iostream>
#include <map>
#include <exception>
#include "Branch.h"
#include "HWExceptions.h"

#ifndef HW4_MAINOFFICE_H
#define HW4_MAINOFFICE_H

class MainOffice{
    //definition of the map + private c'tor + copy c'tor + operator = (by Singleton design pattern convention)
    std::map<const std::string, Branch> branchMap;
    MainOffice(){}
    MainOffice(MainOffice& other) = delete;
    MainOffice& operator=(MainOffice& other) = delete;

public:
    //public methods - as instructed
    void addBranch(const std::string& location, int capacity);
    void deleteBranch(const std::string& location);
    void printByLocation();
    static MainOffice& getInstance();
    std::map<const std::string, Branch>& getBranches();
    ~MainOffice() {} //d'tor
};

#endif //HW4_MAINOFFICE_H

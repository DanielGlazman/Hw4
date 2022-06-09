//
// Created by Daniel Glazman on 03/06/2022.
//
#include <iostream>
#include "MainOffice.h"

//adding a new branch to the map of branches
void MainOffice::addBranch(const std::string& location, int capacity)
{
    Branch newBranch(location, capacity); //definition of new branch
    std::map<const std::string, Branch>::iterator iter; //definition of an iterator
    iter = branchMap.find(location);
    if(iter->first == newBranch.getLocation()) //throw an exception if the branch already exists
    {
        throw ExistingBranchError();
    }
    branchMap.insert(std::pair(location, newBranch)); //insert the new branch to the map
}

//deleting a branch from the branch map
void MainOffice::deleteBranch(const std::string& location)
{
    std::map<const std::string, Branch>::iterator iter;
    iter = branchMap.find(location); //find the branch with the given location
    if(iter == branchMap.end())
    {
        throw NonExistingBranchError(); //throw an exception if the branch is missing
    }
    branchMap.erase(iter); //remove the branch that we found
}

//printing the map by location - the map is ordered lexicographically by definition (because we ordered it by string)
void MainOffice::printByLocation()
{
    std::map<const std::string, Branch>::iterator iter;
    for (iter = branchMap.begin(); iter != branchMap.end(); iter++)
    {
        std::cout << iter->first << " Branch:" << std::endl;
        iter->second.print_catalog_by_id(); //print by id using the suitable function from Branch class
    }
}

//get an instance of the Main Office - by Singleton design pattern convention
MainOffice& MainOffice::getInstance()
{
    static MainOffice theInstance;
    return theInstance;
}

//get branches by returning the map of branches that we maintain
std::map<const std::string, Branch>& MainOffice::getBranches()
{
    return branchMap;
}
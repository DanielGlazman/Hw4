//#include <iostream>
//#include <map>
//#include "Branch.h"
//#include "Computer.h"
//#include "Mouse.h"
//#include "Keyboard.h"
//#include "Webcam.h"
//#include "MainOffice.h"
//
//#define TEST_MAIN_SIZE 4 // not related to STORE_SIZE , only here for the main test
//
//////using polymorphic base class B1
////class B1 {
////public:
////    virtual void fun() {}
////};
//////using non-polymorphic base class B2
////class B2 {};
////class D1 : public B1 {};
////class D2 : public B2 {};
////
////B1* func(B1* b1)
////{
////    return (D1*) b1;
////}
//
//
//int main()
//{
//
////    D1* d1 = new D1;
////    B1* b1 = d1;
////    D2* d2 = new D2;
////    D1* d3 = (D1*)func(d2);
//
//
//    //freopen("output_main.txt", "w", stdout);
//    Item* items[TEST_MAIN_SIZE]; //the array is only here for code organization
//    items[0] = new Computer(60, "Dell", "Intel", true,3);
//    items[0]->setPrice(70);
//    items[1] = new Computer(100, "Apple", "AMD", false,2);
//    items[2] = new Mouse(5, "Pilot", "Red",true, 100);
//    items[3] = new Keyboard(10, "Casio", "Silver", false, 26);
//
//    Branch haifaBranch("Haifa", 14);
//
//    try
//    {
//        for (int i = 0; i < TEST_MAIN_SIZE; i++)
//        {
//            haifaBranch.addItem(items[i]);
//        }
//        haifaBranch.addItem(items[0]);
//    }
//    catch (std::exception& e)
//    {
//        std::cout << e.what() << std::endl;
//    }
//    haifaBranch.print_catalog_by_id();
//    std::cout << std::endl;
//    haifaBranch.print_catalog_by_price();
//    std::cout << std::endl;
//    Keyboard* keyboardPtr = new Keyboard(20, "Sasio", "Gold", true, 24);
//    Mouse* mousePtr = new Mouse(10, "Goldline", "White", false, 1000);
//    Computer* computerPtr = new Computer(120, "Maple", "AMD", true,2);
//    Webcam* webcamPtr = new Webcam(5, "Samsung", "Red", true, "HD");
//    try
//    {
//        keyboardPtr->connect(computerPtr);
//        mousePtr->connect(computerPtr);
//        mousePtr->connect(computerPtr);
//        webcamPtr->connect(computerPtr);
//    }
//    catch (std::exception& e)
//    {
//        std::cout << e.what() << std::endl;
//    }
//    computerPtr->print_connected();
//    std::cout << std::endl;
//    mousePtr->disconnect();
//    computerPtr->print_connected();
//    std::cout << std::endl;
//    try
//    {
//        mousePtr->connect(computerPtr);
//    }
//    catch (std::exception& e)
//    {
//        std::cout << e.what() << std::endl;
//    }
//    Branch telAvivBranch("Tel Aviv-Yafo", 3);
//
//    std::cout << std::endl;
//    try
//    {
//        telAvivBranch.addItem(keyboardPtr);
//        telAvivBranch.addItem(computerPtr);
//        telAvivBranch.addItem(webcamPtr);
//        telAvivBranch.addItem(mousePtr);
//    }
//    catch (std::exception& e)
//    {
//        std::cout << e.what() << std::endl;
//    }
//    std::cout << std::endl;
//
//    try
//    {
//        telAvivBranch.deleteItem(webcamPtr->getId());
//        delete telAvivBranch.deleteItem(mousePtr->getId());
//    }
//    catch(std::exception& e)
//    {
//        std::cout << e.what() << std::endl;
//    }
//    std::cout << std::endl;
//
//    try
//    {
//        haifaBranch.deleteItem(items[0]->getId());
//        telAvivBranch.addItem(items[0]);
//        Computer* ptr = new Computer(0,"","",false,0);
//        Computer* finest = telAvivBranch.retrieveFinest(ptr);
//        std::cout <<"finest computer: "<< std::string(*finest) << std::endl;
//        delete ptr;
//        Webcam* finestWc = telAvivBranch.retrieveFinest(webcamPtr);
//        std::cout << std::string(*finestWc) << std::endl;
//    }
//    catch (std::exception& e)
//    {
//        std::cout << e.what() << std::endl;
//    }
//    std::cout << std::endl;
//
//    delete mousePtr;
//    computerPtr->print_connected();
//    delete webcamPtr;
//}


#include <iostream>
#include "Branch.h"
#include "Computer.h"
#include "Mouse.h"
#include "Keyboard.h"
#include "Webcam.h"
#include "MainOffice.h"
#define TEST_MAIN_SIZE 4 // not related to STORE_SIZE , only here for the main test

int main()
{
    Item* items[TEST_MAIN_SIZE]; //the array is only here for code organization
    items[0] = new Computer(60, "Dell", "Intel", true, 3);
    items[0]->setPrice(70);
    items[1] = new Computer(100, "Apple", "AMD", false, 2);
    items[2] = new Mouse(5, "Pilot", "Red", true, 100);
    items[3] = new Keyboard(10, "Casio", "Silver", false, 26);
    MainOffice::getInstance().addBranch("Haifa", 14);
    try
    {
        for (int i = 0; i < TEST_MAIN_SIZE; i++)
        {

            MainOffice::getInstance().getBranches()["Haifa"].addItem(items[i]);
        }

    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    MainOffice::getInstance().getBranches()["Haifa"].print_catalog_by_id();
    std::cout << std::endl;
    MainOffice& mo = MainOffice::getInstance();
    Branch& haifaBranch = mo.getBranches()["Haifa"];
    haifaBranch.print_catalog_by_price();
    std::cout << std::endl;
    try
    {
        mo.addBranch("Haifa", 100000);
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    try
    {
        mo.deleteBranch("Tel-Aviv");
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    try
    {
        mo.deleteBranch("Haifa");
        mo.addBranch("Tel-Aviv", 1);
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    mo.printByLocation();

    std::cout << "End of main" << std::endl;

}


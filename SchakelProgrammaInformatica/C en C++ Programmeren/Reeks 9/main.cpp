#include "LinkedList.h"

// todo: implement a friend operator

int main() 
{
    LinkedList * happyThing = new LinkedList();
//
//    // Add front
//    std::cout << "Size: " << happyThing->get_size() << std::endl;
//
//    // If start element is NULL, add the new one as the new start element
//    happyThing->add_front(15);
//    std::cout << "Size: " << happyThing->get_size() << std::endl;
//
//    // If the start element is NOT NULL, then add it to the front, and the old one to the new one.
//    happyThing->add_front(14);
//    std::cout << "Size: " << happyThing->get_size() << std::endl;
//
//    std::cout << happyThing << std::endl;
//    happyThing->print();
//
//    // Add Sorted
//    happyThing->add(7);
//    happyThing->add(9);
//    happyThing->add(5);
//    happyThing->add(2);
//    happyThing->add(6);
//    happyThing->add(3);
//    happyThing->add(1);
//    happyThing->print();
//    std::cout << "Size: " << happyThing->get_size() << std::endl;
//
//    // Remove Front
//    happyThing->add(3);
//    happyThing->add(1);
//    happyThing->add(2);
//    happyThing->add(6);
//    std::cout << "Before Removing Front:" << std::endl;
//    happyThing->print();
//    std::cout << "Size: " << happyThing->get_size() << std::endl;
//    happyThing->remove_front();
//    std::cout << "After Removing Front:" << std::endl;
//    happyThing->print();
//    std::cout << "Size: " << happyThing->get_size() << std::endl;

    // Remove element by key
    happyThing->add(3);
    happyThing->add(1);
    happyThing->add(2);
    happyThing->add(4);
    happyThing->add(5);
    happyThing->add(6);
    std::cout << "===========================" << std::endl;
    std::cout << "Original List" << std::endl;
    std::cout << "===========================" << std::endl;
    happyThing->print(std::cout);
    std::cout << "Size: " << happyThing->get_size() << std::endl;
    std::cout << "===========================" << std::endl;
    std::cout << "Remove Key 2:" << std::endl;
    std::cout << "===========================" << std::endl;
    happyThing->remove(2);
    happyThing->print(std::cout);
    std::cout << "Size: " << happyThing->get_size() << std::endl;
    std::cout << "===========================" << std::endl;
    std::cout << "Try to remove unexisting key" << std::endl;
    std::cout << "===========================" << std::endl;
    happyThing->remove(10000);
    happyThing->print(std::cout);
    std::cout << "Size: " << happyThing->get_size() << std::endl;
    std::cout << "===========================" << std::endl;
    std::cout << "Try removing the first element" << std::endl;
    std::cout << "===========================" << std::endl;
    happyThing->remove(1);
    happyThing->print(std::cout);
    std::cout << "Size: " << happyThing->get_size() << std::endl;
    std::cout << "===========================" << std::endl;
    std::cout << "Try removing the last element" << std::endl;
    std::cout << "===========================" << std::endl;
    happyThing->remove(6);
    happyThing->print(std::cout);
    std::cout << "Size: " << happyThing->get_size() << std::endl;


    // Delete list
    delete happyThing;
}


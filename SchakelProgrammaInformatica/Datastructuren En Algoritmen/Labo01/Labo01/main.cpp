//
//  main.cpp
//  Labo01
//
//  Created by Xavier Geerinck on 11/02/15.
//  Copyright (c) 2015 Xavier Geerinck. All rights reserved.
//

#include <iostream>
#include "list.cpp"
#include "chrono.h"

int main() {
    Lijsten::Lijst<int> l;
    srand(time(0));
    
    for (auto i = 0; i < 40; i++) {
        int random = rand() % 100;
        l.voeg_toe_vooraan(random);
    }
    
    // Start sorteren en timing
    Chrono cr;
    cr.start();
    l.insertion_sort();
    cr.stop();
    
    l.printList();
    
    std::cout << "Sorted in: " << cr.tijd() << std::endl;
}
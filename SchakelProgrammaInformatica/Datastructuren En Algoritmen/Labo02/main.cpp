//
//  main.cpp
//  Labo2
//
//  Created by Xavier Geerinck on 18/02/15.
//  Copyright (c) 2015 Xavier Geerinck. All rights reserved.
//

#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include "sortvector.h"
#include "sorteermethode.h"
#include "chrono.h"
#include "Nstring.h"

int main() {
    srand(time(NULL)); // seed it
    
    HeapSort<int> is;
    
    Sortvector<int> s(50);
    s.vul_range();
    
    std::cout << s;
    std::cout << "Is range?  " << s.is_range() << std::endl;
    std::cout << "Is sorted? " << s.is_gesorteerd() << std::endl;
    std::cout << std::endl;
    
    s.shuffle();
    
    std::cout << s;
    std::cout << "Is range?  " << s.is_range() << std::endl;
    std::cout << "Is sorted? " << s.is_gesorteerd() << std::endl;
    std::cout << std::endl;

    s.sorteer(is);

    std::cout << s;
    std::cout << "Is range?  " << s.is_range() << std::endl;
    std::cout << "Is sorted? " << s.is_gesorteerd() << std::endl;
    std::cout << std::endl;

    
    // OUTPUT
    //CsvData csv("test2", ';');
    //meet(1, 4, is, csv);
    
    // Sort Method     ElCount    Random El   Sorted El   Reverse Sorted El
    // Shellsort:      100000	  0.042827	  0.012409	  0.015433 (Shell sort is slechter in beste geval)
    // Insertion Sort: 100000	   12.1867	  0.001077	   24.6902 (Insertion sort is gewoon traag)
    // Heap Sort:      100000	  0.040391	  0.036628	  0.034401 (O(n log n) average and best)

   // meet(1, 6, is, std::cout);
    
    return 0;
}

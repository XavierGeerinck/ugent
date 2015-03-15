//
//  chrono.h
//  Labo2
//
//  Created by Xavier Geerinck on 18/02/15.
//  Copyright (c) 2015 Xavier Geerinck. All rights reserved.
//

#ifndef Labo2_chrono_h
#define Labo2_chrono_h

#include <ctime>

class Chrono{
public:
    Chrono();
    void start();
    void stop();
    double tijd() const;
private:
    clock_t begin, einde;
};

Chrono::Chrono(){}

void Chrono::start(){
    begin = clock();
}

void Chrono::stop(){
    einde = clock();
}

double Chrono::tijd() const{
    return static_cast<double>(einde - begin) / CLOCKS_PER_SEC;
}

#endif

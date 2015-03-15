//
//  Nstring.h
//  Labo2
//
//  Created by Xavier Geerinck on 21/02/15.
//  Copyright (c) 2015 Xavier Geerinck. All rights reserved.
//

#ifndef Labo2_NString_h
#define Labo2_NString_h

class NString : public std::string {
public:
    NString(int dec) : std::string(converteer(dec)) {
        this->dec = dec;
    };
    
    std::string converteer(int getal) {
        std::string s;
        
        while (getal > 0) {
            s += '0' + (getal % 10);
            
            getal /= 10; // deel door 10
        }
        
        return s;
    };
    
    int getDec() const {
        return dec;
    };
    
//    ostream& operator<<(ostream& os, const NString& s){
//        os << s.getDec();
//        
//        return os;
//    };
    
    bool operator<(const NString &rhs) const {
        return this->getDec() < rhs.getDec();
    };
    
    bool operator!=(const NString &rhs) const {
        return this->getDec() != rhs.getDec();
    };
    
private:
    int dec;
};

#endif

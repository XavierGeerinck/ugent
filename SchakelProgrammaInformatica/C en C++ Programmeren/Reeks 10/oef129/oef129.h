#include <iostream>
#include <fstream>

#ifndef OEF121_H
#define OEF121_H

class Breuk {
    private:
        int m_teller;
        int m_noemer;
    public:
        void normaliseer();
        Breuk();
        Breuk(int teller, int noemer);
        Breuk(const Breuk& b);
        void schrijf(std::ostream &os) const;
        void lees();
        Breuk vermenigvuldig_met(const Breuk &b);
        int get_teller() const;
        int get_noemer() const;
        void set_teller(const int teller);
        void set_noemer(const int teller);
};

#endif
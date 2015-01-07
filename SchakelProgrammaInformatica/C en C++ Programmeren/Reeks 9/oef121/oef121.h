#include <iostream>
#include <fstream>

#ifndef OEF121_H
#define OEF121_H

class Breuk {
    private:
        int m_teller;
        int m_noemer;
    public:
        double ggd(int getal1, int getal2);
        void normaliseer();
        Breuk();
        Breuk(int teller, int noemer);
        void schrijf(std::ostream &os) const;
        void lees();
        void vermenigvuldig_met(const Breuk &b);
        int get_teller() const;
        int get_noemer() const;
};

#endif
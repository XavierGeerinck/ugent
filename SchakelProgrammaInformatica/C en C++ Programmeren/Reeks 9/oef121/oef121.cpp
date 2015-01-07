#include "oef121.h"

Breuk::Breuk() : m_teller(0), m_noemer(1) {

};

Breuk::Breuk(int teller, int noemer) : m_teller(teller), m_noemer(noemer) {

};

double Breuk::ggd(int getal1, int getal2) {
    if (getal1 == 0) return getal2;
    if (getal2 == 0) return getal1;

    if (getal1 < 0) return getal1 = -getal1;
    if (getal2 < 0) return getal2 = -getal2;

    while (getal2 != getal1) {
        if (getal1 > getal2) getal1 -= getal2;
        else getal2 -= getal1;
    }

    return getal1;
}

void Breuk::normaliseer() {
    if (m_noemer < 0) {
        m_noemer = -m_noemer;
        m_teller = -m_teller;
    }

    int d(ggd(m_teller, m_noemer));
    m_teller /= d;
    m_noemer /= d;
}

void Breuk::schrijf(std::ostream &os) const {
    os << m_teller << " / " << m_noemer << std::endl;
}

void Breuk::lees() {

}

void Breuk::vermenigvuldig_met(const Breuk &b) {

}

int Breuk::get_teller() const {
    return m_teller;
}

int Breuk::get_noemer() const {
    return m_noemer;
}
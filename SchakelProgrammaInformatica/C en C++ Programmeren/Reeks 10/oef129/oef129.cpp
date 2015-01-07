#include "oef129.h"

int ggd(int a, int b) {
    if (a < 0 || b < 0) {
        return ggd(abs(a), abs(b));
    }

    if (a < b) {
        return ggd(b, a);
    }

    if (b == 0) {
        return a;
    }

    if (b == 1) {
        return 1;
    }

    return ggd(b, a % b);
}

Breuk::Breuk() : m_teller(0), m_noemer(1) {

};

Breuk::Breuk(const Breuk& b) : m_teller(b.get_noemer()), m_noemer(b.get_teller()) {
    normaliseer();
};

Breuk::Breuk(int teller, int noemer) : m_teller(teller), m_noemer(noemer) {

};

void Breuk::normaliseer() {
    if (m_noemer < 0) {
        m_noemer = -m_noemer;
        m_teller = -m_teller;
    }

    int deler = ggd(m_teller, m_noemer);
    m_teller /= deler;
    m_noemer /= deler;
}

void Breuk::schrijf(std::ostream &os) const {
    os << m_teller << " / " << m_noemer;
}

Breuk Breuk::vermenigvuldig_met(const Breuk &b) {
    this->m_noemer *= b.get_noemer();
    this->m_teller *= b.get_teller();

    Breuk b_n(m_noemer, m_teller);
    return b_n;
}

int Breuk::get_teller() const {
    return m_teller;
}

int Breuk::get_noemer() const {
    return m_noemer;
}

void Breuk::set_teller(const int teller) {
    this->m_teller = teller;
}

void Breuk::set_noemer(const int noemer) {
    this->m_noemer = noemer;
}